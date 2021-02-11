/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:01:39 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 10:37:35 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsa_utils.h"
#include "dsa_params.h"

static size_t	dsa_bytes(const void *data, size_t n)
{
	size_t		i;
	uint8_t		*u8data;

	if (!(data && n))
		return (0);
	i = 0;
	u8data = (uint8_t *)data;
	while (i < n)
	{
		if (u8data[i])
			break ;
		i++;
	}
	return (n - i + ((u8data[i] & 0x80) ? 1 : 0));
}

static void		construct_dsa_key_from_int(t_dsa *dsa, t_data **key,\
											uint64_t num, uint8_t n)
{
	uint8_t		n_bytes;
	uint8_t		bytes_len;
	void		*num_data;
	uint8_t		*u8data;
	t_data		*tmp;

	num = (n == BYTE_64) ? ft_swapint64(num) : ft_swapint32(num);
	num_data = &num;
	n_bytes = dsa_bytes(num_data, n);
	bytes_len = (n_bytes + 0xFF - 0x1) / 0xFF;
	tmp = ft_datandup(*key, (*key)->n + 1 + bytes_len + n_bytes);
	if (!tmp)
		dsa_out(dsa, FAILURE);
	u8data = tmp->data + (*key)->n;
	*(u8data++) = ASN_TAG_INT | ((bytes_len > 1) ? ASN_TAG_LONG_LEN : 0);
	ft_memcpy(u8data, &n_bytes, bytes_len);
	u8data += bytes_len;
	if (*(uint8_t *)num_data & 0x80)
		*(u8data++) = 0;
	ft_memcpy(u8data, num_data + ((n_bytes > n) ? 0 : (n - n_bytes)),\
				(n_bytes > n) ? n : n_bytes);
	ft_datareplace(key, &tmp);
}

static void		add_sequence(t_dsa *dsa, t_data **key, uint8_t sequence)
{
	t_bool		is_long;
	uint32_t	bytes_len;
	t_data		*tmp;

	bytes_len = ((*key)->n + 0x7F - 1) / 0x7F;
	is_long = (bytes_len > 1) ? TRUE : FALSE;
	if (!(tmp = ft_datanew((*key)->n + 1 + bytes_len + is_long)))
		dsa_out(dsa, FAILURE);
	tmp->data[0] = sequence;
	if (is_long)
		tmp->data[1] = ASN_TAG_INT | ASN_TAG_LONG_LEN;
	ft_memcpy(tmp->data + 1 + is_long, &(*key)->n, bytes_len);
	ft_memcpy(tmp->data + 1 + is_long + bytes_len, (*key)->data, (*key)->n);
	ft_datareplace(key, &tmp);
}

void			construct_dsa_key(t_dsa *dsa)
{
	uint8_t		cbyte;
	uint32_t	bytes_len;
	t_data		*tmp;

	if (dsa->key)
		return ;
	if (!(dsa->key = ft_datanew(3)))
		dsa_out(dsa, FAILURE);
	dsa->key->data[0] = ASN_TAG_INT;
	dsa->key->data[1] = 1;
	dsa->key->data[2] = ASN_DSA_VERSION;
	construct_dsa_key_from_int(dsa, &dsa->key, dsa->p, BYTE_64);
	construct_dsa_key_from_int(dsa, &dsa->key, dsa->q, BYTE_64);
	construct_dsa_key_from_int(dsa, &dsa->key, dsa->g, BYTE_64);
	construct_dsa_key_from_int(dsa, &dsa->key, dsa->y, BYTE_64);
	construct_dsa_key_from_int(dsa, &dsa->key, dsa->x, BYTE_64);
	add_sequence(dsa, &dsa->key, ASN_TAG_SEQUENCE);
}
