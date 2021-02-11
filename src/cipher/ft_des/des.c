/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:29:47 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 08:50:41 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des_utils.h"

static uint32_t		des_feistel(uint32_t r32block, uint64_t key48)
{
	int8_t			i;
	uint64_t		r48block;
	uint32_t		s48block;
	t_des_b6block	b;

	s48block = 0;
	r48block = expansion_permutation(r32block);
	r48block ^= key48;
	i = -1;
	while (++i < DES_S_SIZE)
	{
		b.val = SHIFTR(r48block, BIT_64 - ((i + 1) * DES_B_SIZE));
		b.val <<= BYTE_SIZE - DES_B_SIZE;
		s48block <<= DES_X_SIZE;
		s48block |= g_des_s[i][SHIFTL(b.v.x1, 1) | b.v.x0][b.v.y];
	}
	return (substitution_permutation(s48block));
}

static void			des_round(t_des_block *init, uint64_t round_key)
{
	t_des_block		final;

	final.v.l = init->v.r;
	final.v.r = init->v.l ^ des_feistel(init->v.r, round_key);
	init->val = final.val;
}

static uint64_t		des_decrypt(uint64_t u64block, uint64_t *round_keys)
{
	uint8_t			i;
	t_des_block		des_block;

	i = DES_ROUND;
	des_block.val = initial_permutation(u64block);
	while (i--)
		des_round(&des_block, round_keys[i]);
	des_block.val = SHIFTL((uint64_t)des_block.v.r, BIT_32) | des_block.v.l;
	return (final_permutation(des_block.val));
}

static uint64_t		des_encrypt(uint64_t u64block, uint64_t *round_keys)
{
	uint8_t			i;
	t_des_block		des_block;

	i = -1;
	des_block.val = initial_permutation(u64block);
	while (++i < DES_ROUND)
		des_round(&des_block, round_keys[i]);
	des_block.val = SHIFTL((uint64_t)des_block.v.r, BIT_32) | des_block.v.l;
	return (final_permutation(des_block.val));
}

inline void			get_des_cipher(t_des *des, t_bool decrypt_mode)
{
	des->des_cipher = (decrypt_mode) ? &des_decrypt : &des_encrypt;
	des->des3_cipher = (!decrypt_mode) ? &des_decrypt : &des_encrypt;
}
