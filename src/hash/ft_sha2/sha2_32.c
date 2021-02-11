/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:06:31 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/20 01:45:29 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2_utils_32.h"

static t_data			*sha2_out(t_sha2_32 *sha2)
{
	if (!sha2->op.data)
		ft_printf("%w%s[SHA2] Data malloc error.%s\n", STDERR, ERR, DEFAULT);
	else if (!sha2->op.hash)
		ft_printf("%w%s[SHA2] Hash malloc error.%s\n", STDERR, ERR, DEFAULT);
	ft_memdel((void**)&sha2->op.data);
	return (sha2->op.hash);
}

static void				sha2_const_init(t_sha2_32 *sha2)
{
	int16_t				i;

	i = -1;
	while (++i < BYTE_SIZE)
		sha2->h_[i] = sha2->c_h[i];
	sha2->c_k = g_sha2_k_32;
}

static t_bool			*sha2_init(t_sha2_32 *sha2, const void *data, size_t n)
{
	uint64_t			bits_len;

	bits_len = (n + 1) * BYTE_SIZE;
	while ((bits_len % 512) != 448)
		bits_len += BYTE_SIZE;
	sha2->op.len = bits_len / BYTE_SIZE + SHA2_BLOCK_32 / BYTE_SIZE;
	if (!(sha2->op.data = (uint8_t *)ft_memalloc(sha2->op.len)))
		return (NULL);
	ft_memcpy(sha2->op.data, data, n);
	sha2->op.data[n] |= SHIFTL(1, 7);
	bits_len = ft_swapint64(n * BYTE_SIZE);
	ft_memcpy(&sha2->op.data[sha2->op.len - BYTE_SIZE], &bits_len, BYTE_SIZE);
	return (sha2->op.data);
}

static t_data			*get_hash(t_sha2_32 *sha2)
{
	int16_t				i;
	uint8_t				*h;

	if (!(sha2->op.hash = ft_datanew(sha2->op.hash_len)))
		return (sha2_out(sha2));
	i = BYTE_SIZE;
	while (i--)
		sha2->h_[i] = ft_swapint32(sha2->h_[i]);
	h = (uint8_t *)sha2->h_;
	while (++i < sha2->op.hash_len)
		sha2->op.hash->data[i] = h[i];
	return (sha2_out(sha2));
}

t_data					*sha2_32(t_sha2_32 *sha2, const void *data, size_t n)
{
	if (!data)
		return (NULL);
	sha2_const_init(sha2);
	if (!sha2_init(sha2, data, n))
		return (sha2_out(sha2));
	sha2_hash_32(sha2);
	return (get_hash(sha2));
}
