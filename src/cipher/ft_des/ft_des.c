/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:29:47 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/23 07:49:14 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des_utils.h"

t_data				*ft_des_ecb(const void *data, size_t n, t_cipdata *cipdata,\
								t_bool decrypt_mode)
{
	size_t			i;
	uint64_t		u64block;
	const uint8_t	*u8data;
	t_des			des;

	if (!(u8data = (uint8_t *)data))
		return (NULL);
	if (!des_init(&des, cipdata, n, decrypt_mode))
		return (NULL);
	get_des_cipher(&des, decrypt_mode);
	i = 0;
	while (i < des.cipher->n)
	{
		u64block = ft_u64pad8(u8data + i, n - i, des.pad);
		u64block = des.des_cipher(u64block, des.round_keys);
		ft_u8from64(des.cipher->data + i, ft_swapint64(u64block));
		i += BYTE_64;
	}
	return (des_decrypt_validation(&des, cipdata, decrypt_mode));
}

static void			des_cbc(const uint8_t *u8data, size_t n, t_des *des,\
							t_bool decrypt_mode)
{
	size_t			i;
	uint64_t		u64block;

	i = 0;
	if (decrypt_mode)
		while (i < des->cipher->n)
		{
			u64block = ft_u64pad8(u8data + i, n - i, des->pad);
			des->v64block ^= des->des_cipher(u64block, des->round_keys);
			ft_u8from64(des->cipher->data + i, ft_swapint64(des->v64block));
			des->v64block = u64block;
			i += BYTE_64;
		}
	else
		while (i < des->cipher->n)
		{
			u64block = ft_u64pad8(u8data + i, n - i, des->pad);
			u64block ^= des->v64block;
			des->v64block = des->des_cipher(u64block, des->round_keys);
			ft_u8from64(des->cipher->data + i, ft_swapint64(des->v64block));
			i += BYTE_64;
		}
}

t_data				*ft_des_cbc(const void *data, size_t n, t_cipdata *cipdata,\
								t_bool decrypt_mode)
{
	const uint8_t	*u8data;
	t_des			des;

	if (!(u8data = (uint8_t *)data))
		return (NULL);
	if (!des_init(&des, cipdata, n, decrypt_mode))
		return (NULL);
	get_des_cipher(&des, decrypt_mode);
	des_cbc(u8data, n, &des, decrypt_mode);
	return (des_decrypt_validation(&des, cipdata, decrypt_mode));
}

t_data				*ft_des(const void *data, size_t n, t_cipdata *cipdata,\
								t_bool decrypt_mode)
{
	return (ft_des_cbc(data, n, cipdata, decrypt_mode));
}
