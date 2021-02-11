/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:32:56 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/20 01:45:29 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5_utils.h"

static t_data			*md5_out(t_md5 *md5)
{
	if (!md5->op.data)
		ft_printf("%w%s[MD5] Data malloc error.%s\n", STDERR, ERR, DEFAULT);
	else if (!md5->op.hash)
		ft_printf("%w%s[MD5] Hash malloc error.%s\n", STDERR, ERR, DEFAULT);
	ft_memdel((void**)&md5->op.data);
	return (md5->op.hash);
}

static inline void		md5_const_init(t_md5 *md5)
{
	int16_t				i;

	md5->op.hash_len = T_MD5_LEN;
	i = -1;
	while (++i < md5->op.hash_len)
		md5->h_[i] = g_md5_h[i];
	i = MD5_ROUND;
	while (--i >= 0)
	{
		md5->k[i] = (uint32_t)(ft_lpow(2, 32) * ft_fabs(sin(i + 1)));
		md5->s[i] = g_md5_s[(i % 4) + 4 * (i / 16)];
	}
}

static t_bool			*md5_init(t_md5 *md5, const void *data, size_t n)
{
	uint64_t			bits_len;

	md5_const_init(md5);
	bits_len = (n + 1) * BYTE_SIZE;
	while ((bits_len % 512) != 448)
		bits_len += BYTE_SIZE;
	md5->op.len = bits_len / BYTE_SIZE;
	if (!(md5->op.data = (uint8_t *)ft_memalloc(md5->op.len + MD5_BLOCK)))
		return (NULL);
	ft_memcpy(md5->op.data, data, n);
	md5->op.data[n] |= SHIFTL(1, 7);
	bits_len = n * BYTE_SIZE;
	ft_memcpy(&md5->op.data[md5->op.len], &bits_len, BYTE_SIZE);
	return (md5->op.data);
}

static t_data			*get_hash(t_md5 *md5)
{
	int16_t				i;

	if (!(md5->op.hash = ft_datanew(md5->op.hash_len)))
		return (md5_out(md5));
	i = -1;
	while (++i < md5->op.hash_len / BYTE_32)
		ft_u8from32(&md5->op.hash->data[i * BYTE_32], md5->h_[i]);
	return (md5_out(md5));
}

t_data					*ft_md5(const void *data, size_t n)
{
	t_md5				md5;

	if (!data)
		return (NULL);
	if (!md5_init(&md5, data, n))
		return (md5_out(&md5));
	md5_hash(&md5);
	return (get_hash(&md5));
}
