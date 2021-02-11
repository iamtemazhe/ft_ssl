/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:29:47 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 08:50:48 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des_utils.h"

uint64_t			permutation(const uint8_t *table, uint8_t table_size,\
								uint64_t block, uint8_t block_size)
{
	int8_t			i;
	uint64_t		result_block;
	uint64_t		tblock_size;

	i = -1;
	result_block = 0;
	tblock_size = (block_size == table_size) ? block_size : BIT_64;
	while (++i < table_size)
		result_block |= PERM(block, block_size - table[i], tblock_size - i);
	return (result_block);
}

static uint64_t		initial_key_permutation(uint64_t u64block)
{
	int8_t			i;
	t_des_block		des_block;

	i = -1;
	des_block.val = 0;
	while (++i < DES_IKP_SIZE)
	{
		des_block.v.l |= PERM(u64block, BIT_64 - g_des_ikp_c[i], BIT_32 - i);
		des_block.v.r |= PERM(u64block, BIT_64 - g_des_ikp_d[i], BIT_32 - i);
	}
	return (des_block.val);
}

static void			init_round_keys(uint64_t *round_keys, const t_data *key,\
									uint8_t key_ind)
{
	int8_t			i;
	uint8_t			shift_byte;
	uint64_t		k64block;
	uint64_t		init64key;
	t_des_block		des_block;

	shift_byte = key_ind * BYTE_SIZE;
	init64key = ft_u64from8(key->data + shift_byte, key->n - shift_byte);
	des_block.val = initial_key_permutation(init64key);
	i = -1;
	while (++i < DES_RK_NUM)
	{
		des_block.v.l = ROTL(DES_IKP_SIZE, des_block.v.l, g_des_cd_shift[i]);
		des_block.v.r = ROTL(DES_IKP_SIZE, des_block.v.r, g_des_cd_shift[i]);
		k64block = SHIFTR(des_block.v.l, 4);
		k64block = SHIFTL(SHIFTL(k64block, BIT_32) | des_block.v.r, 4);
		round_keys[i] = round_key_permutation(k64block);
	}
}

t_data				*des_init(t_des *des, t_cipdata *cipdata,\
								size_t n, t_bool decrypt_mode)
{
	int8_t			key_ind;
	size_t			des_len;

	des->key_num = cipdata->params->key_len / DES_WORD;
	des->pad = DES_WORD - (n % DES_WORD);
	if (decrypt_mode || !cipdata->params->is_pad)
		des_len = n;
	else
		des_len = DLEN(cipdata->mode.is.nopad, n, des->pad);
	if (cipdata->params->is_pad && cipdata->mode.is.nopad && (n % DES_WORD))
		ft_printf("%w%sData not multiple of block length.%s\n",\
					STDERR, WARN, DEFAULT);
	if (cipdata->params->ivector_len)
		des->v64block = ft_u64from8(cipdata->ivector->data,\
									cipdata->ivector->n);
	key_ind = -1;
	while (++key_ind < des->key_num)
		init_round_keys(des->rounds_keys[key_ind], cipdata->key, key_ind);
	des->round_keys = *(des->rounds_keys + (des->key_num - 1) * decrypt_mode);
	des->round2_keys = *(des->rounds_keys + 1 % des->key_num);
	des->round3_keys = *(des->rounds_keys + (des->key_num - 1) * !decrypt_mode);
	return ((des->cipher = ft_datanew(des_len)));
}

t_data				*des_decrypt_validation(t_des *des, t_cipdata *cipdata,\
											t_bool decrypt_mode)
{
	size_t			data_len;

	if (!decrypt_mode || !cipdata->params->is_pad || cipdata->mode.is.nopad)
		return (des->cipher);
	data_len = des->cipher->n;
	des->pad = des->cipher->data[des->cipher->n - 1];
	if (des->pad && des->pad <= DES_WORD)
		while ((data_len > (des->cipher->n - DES_WORD)) &&\
				(des->cipher->data[data_len - 1] == des->pad))
			data_len--;
	else
		des->pad = DES_WORD;
	if (des->pad != (des->cipher->n - data_len))
		ft_printf("%w%sBad decrypt data.%s\n", STDERR, ERR, DEFAULT);
	des->cipher->n -= des->pad;
	return (des->cipher);
}
