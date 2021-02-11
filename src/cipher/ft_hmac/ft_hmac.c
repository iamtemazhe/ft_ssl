/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:21:33 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/27 01:39:27 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmac_utils.h"
#include "hmac_params.h"

static t_bool		hmac_init(t_data *(hash)(const void *, size_t),\
							uint8_t block_size, const t_data *key, t_hmac *hmac)
{
	uint8_t			i;
	t_data			*ikey;
	t_data			*hmac_key;

	ikey = NULL;
	hmac->hash = hash;
	hmac->block_size = block_size;
	if (key->n > hmac->block_size && !(ikey = hmac->hash(key->data, key->n)))
		return (FALSE);
	hmac_key = ft_datandup((ikey) ? ikey : key, hmac->block_size);
	ft_datadel(&ikey);
	if (!hmac_key)
		return (FALSE);
	i = 0;
	while (i < hmac->block_size)
	{
		hmac->i_key_pad[i] = hmac_key->data[i] ^ HMAC_IPAD;
		hmac->o_key_pad[i] = hmac_key->data[i] ^ HMAC_OPAD;
		i++;
	}
	ft_datadel(&hmac_key);
	return (TRUE);
}

t_data				*hmac(t_data *(hash)(const void *, size_t),\
							uint8_t block_size, const t_data *key,\
							const t_data *msg)
{
	void			*tmp;
	uint8_t			hash_len;
	t_hmac			hmac;
	t_data			*hash_msg;

	if (!key || !msg || !hmac_init(hash, block_size, key, &hmac))
		return (NULL);
	if (!(tmp = ft_memjoin(hmac.i_key_pad, hmac.block_size, msg->data, msg->n)))
		return (NULL);
	hash_msg = hmac.hash(tmp, hmac.block_size + msg->n);
	ft_memdel(&tmp);
	if (!hash_msg)
		return (NULL);
	hash_len = hash_msg->n;
	tmp = ft_memjoin(hmac.o_key_pad, hmac.block_size, hash_msg->data, hash_len);
	ft_datadel(&hash_msg);
	if (!tmp)
		return (NULL);
	hash_msg = hmac.hash(tmp, hmac.block_size + hash_len);
	ft_memdel(&tmp);
	return (hash_msg);
}

const t_hmac_param	*get_hmac_params(const char *hash_name)
{
	int16_t			i;

	i = -1;
	while (++i < HMACS_NUM)
		if (!ft_strcmpi(hash_name, g_hmac_params[i].name))
			return (&g_hmac_params[i]);
	return (NULL);
}

t_data				*ft_hmac(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha256, HMAC_SHA256_BS, key, msg));
}
