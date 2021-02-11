/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:32:20 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 06:06:51 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsa_params.h"

static size_t	rsa_bytes(const void *data, size_t n)
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

static void		construct_rsa_key_from_int(t_rsa *rsa, t_data **key,\
											uint64_t num, uint8_t n)
{
	uint8_t		n_bytes;
	uint8_t		bytes_len;
	void		*num_data;
	uint8_t		*u8data;
	t_data		*tmp;

	num = (n == BYTE_64) ? ft_swapint64(num) : ft_swapint32(num);
	num_data = &num;
	n_bytes = rsa_bytes(num_data, n);
	bytes_len = (n_bytes + 0xFF - 0x1) / 0xFF;
	tmp = ft_datandup(*key, (*key)->n + 1 + bytes_len + n_bytes);
	if (!tmp)
		rsa_out(rsa, FAILURE);
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

static void		add_sequence(t_rsa *rsa, t_data **key, uint8_t sequence)
{
	t_bool		is_long;
	uint32_t	bytes_len;
	t_data		*tmp;

	bytes_len = ((*key)->n + 0x7F - 1) / 0x7F;
	is_long = (bytes_len > 1) ? TRUE : FALSE;
	if (!(tmp = ft_datanew((*key)->n + 1 + bytes_len + is_long)))
		rsa_out(rsa, FAILURE);
	tmp->data[0] = sequence;
	if (is_long)
		tmp->data[1] = ASN_TAG_INT | ASN_TAG_LONG_LEN;
	ft_memcpy(tmp->data + 1 + is_long, &(*key)->n, bytes_len);
	ft_memcpy(tmp->data + 1 + is_long + bytes_len, (*key)->data, (*key)->n);
	ft_datareplace(key, &tmp);
}

void			construct_rsa_key(t_rsa *rsa)
{
	uint8_t		cbyte;
	uint32_t	bytes_len;
	t_data		*tmp;

	if (rsa->key)
		return ;
	if (!(rsa->key = ft_datanew(3)))
		rsa_out(rsa, FAILURE);
	rsa->key->data[0] = ASN_TAG_INT;
	rsa->key->data[1] = 1;
	rsa->key->data[2] = ASN_RSA_VERSION;
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->n, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->e, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->d, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->p, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->q, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->dp, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->dq, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->key, rsa->iq, BYTE_64);
	add_sequence(rsa, &rsa->key, ASN_TAG_SEQUENCE);
}

void			construct_rsa_pkey(t_rsa *rsa)
{
	uint8_t		null_byte;
	uint8_t		cbyte;
	uint32_t	bytes_len;
	t_data		*tmp;

	if (rsa->pkey)
		return ;
	if (!(rsa->pkey = ft_datanew(0)))
		rsa_out(rsa, FAILURE);
	construct_rsa_key_from_int(rsa, &rsa->pkey, rsa->n, BYTE_64);
	construct_rsa_key_from_int(rsa, &rsa->pkey, rsa->e, BYTE_64);
	add_sequence(rsa, &rsa->pkey, ASN_TAG_SEQUENCE);
	null_byte = 0;
	if (!(rsa->pkey = ft_datamemrrealloc(rsa->pkey, &null_byte, 1)))
		rsa_out(rsa, FAILURE);
	add_sequence(rsa, &rsa->pkey, ASN_TAG_SEQUENCE_P);
	if (!(rsa->pkey = ft_datarrealloc(rsa->pkey, &g_rsa_pkey_sequence)))
		rsa_out(rsa, FAILURE);
	add_sequence(rsa, &rsa->pkey, ASN_TAG_SEQUENCE);
}
