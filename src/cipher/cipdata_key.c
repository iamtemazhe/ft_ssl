/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipdata_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:51:48 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_utils.h"

static t_bool	pbkdf2_f(t_cipdata *cipdata, size_t key_len,\
							uint8_t **p_key_data, uint32_t i)
{
	uint8_t		hmac_len;
	int32_t		key_step;
	uint32_t	iter;

	iter = cipdata->iter;
	hmac_len = cipdata->hmac_params->hmac_len;
	key_step = (key_len < hmac_len * i) ?\
				(key_len - hmac_len * (i - 1)) : hmac_len;
	i = ft_swapint32(i);
	ft_memcpy(cipdata->pbkdf2_s->data + CIPHER_SALT_LEN, &i, BYTE_32);
	if (!(cipdata->pbkdf2_u = ft_datadup(cipdata->pbkdf2_s)))
		return (FALSE);
	while (iter--)
	{
		if (!ft_datafreplace(&cipdata->pbkdf2_u,\
			cipdata->hmac_params->hmac(cipdata->password, cipdata->pbkdf2_u)))
			return (FALSE);
		ft_memxor(*p_key_data, cipdata->pbkdf2_u->data, key_step);
	}
	*p_key_data += key_step;
	return (TRUE);
}

static t_data	*pbkdf2(t_cipdata *cipdata)
{
	uint8_t		i;
	uint8_t		iv_len;
	uint8_t		hmac_len;
	uint8_t		*p_key_data;
	t_data		*key;

	iv_len = (cipdata->params->ivector_len && !cipdata->ivector) ?\
				cipdata->params->ivector_len : 0;
	if (!cipdata->hmac_params)
		cipdata->hmac_params = get_hmac_params(CIPHER_DEFAULT_HASH);
	hmac_len = cipdata->hmac_params->hmac_len;
	if (!(key = ft_datanew(cipdata->params->key_len + iv_len)))
		return (NULL);
	if (!(cipdata->pbkdf2_s = ft_datandup(cipdata->salt, CIPHER_PBKDF2_S)))
		return (ft_datadel_rn(&key));
	i = 0;
	p_key_data = key->data;
	while (i++ < ((key->n + hmac_len - 1) / hmac_len))
		if (!pbkdf2_f(cipdata, key->n, &p_key_data, i))
			return (ft_datadel_rn(&key));
	if (iv_len && !(cipdata->ivector = ft_datamemdup(key->data +\
											cipdata->params->key_len, iv_len)))
		return (ft_datadel_rn(&key));
	key->n = cipdata->params->key_len;
	return (key);
}

static t_bool	kdf_f(t_cipdata *cipdata, t_data *key)
{
	uint16_t	i;
	uint8_t		hash_len;
	uint32_t	key_step;
	uint8_t		*key_data;

	i = 1;
	hash_len = cipdata->hash_params->hash_len;
	ft_memcpy(key->data, cipdata->pbkdf2_u->data, hash_len);
	key_data = key->data + hash_len;
	while (i++ < ((key->n + hash_len - 1) / hash_len))
	{
		key_step = (key->n < hash_len * i) ?\
					(key->n - hash_len * (i - 1)) : hash_len;
		if (!ft_datafreplace(&cipdata->pbkdf2_u,\
			ft_datajoin(cipdata->pbkdf2_u, cipdata->pbkdf2_s)))
			return (FALSE);
		if (!ft_datafreplace(&cipdata->pbkdf2_u,
			cipdata->hash_params->hash(cipdata->pbkdf2_u->data,\
											cipdata->pbkdf2_u->n)))
			return (FALSE);
		ft_memcpy(key_data, cipdata->pbkdf2_u->data, key_step);
		key_data += key_step;
	}
	return (TRUE);
}

static t_data	*kdf(t_cipdata *cipdata)
{
	uint8_t		iv_len;
	t_data		*key;

	iv_len = (cipdata->params->ivector_len && !cipdata->ivector) ?\
				cipdata->params->ivector_len : 0;
	if (!cipdata->hash_params)
		cipdata->hash_params = get_hash_params(CIPHER_DEFAULT_HASH);
	if (!(key = ft_datanew(cipdata->params->key_len + iv_len)))
		return (NULL);
	if (!(cipdata->pbkdf2_s = ft_datajoin(cipdata->password, cipdata->salt)))
		return (ft_datadel_rn(&key));
	if (!(cipdata->pbkdf2_u = cipdata->hash_params->hash(\
								cipdata->pbkdf2_s->data, cipdata->pbkdf2_s->n)))
		return (ft_datadel_rn(&key));
	if (key->n <= cipdata->hash_params->hash_len)
		ft_memcpy(key->data, cipdata->pbkdf2_u->data, key->n);
	else if (!kdf_f(cipdata, key))
		return (ft_datadel_rn(&key));
	if (iv_len && !(cipdata->ivector = ft_datamemdup(key->data +\
											cipdata->params->key_len, iv_len)))
		return (ft_datadel_rn(&key));
	key->n = cipdata->params->key_len;
	return (key);
}

t_data			*get_key(t_cipdata *cipdata, t_bool decrypt_mode)
{
	t_data		*key;

	if (!cipdata->password && cipdata->key &&\
		(cipdata->ivector || !cipdata->params->ivector_len))
		return (cipdata->key);
	if (!(get_salt(cipdata) && get_password(cipdata, decrypt_mode)))
		return (ft_datadel_rn(&cipdata->key));
	cipdata->mode.is.salted = TRUE;
	if (cipdata->mode.is.pbkdf2)
		key = pbkdf2(cipdata);
	else
	{
		if (!cipdata->mode.is.quiet)
			ft_tprintf(STDERR, WARN, "Deprecated key derivation used. %s\n",\
						"Using PBKDF2 [-f | -c ITER] would be better.");
		key = kdf(cipdata);
	}
	if (cipdata->key)
		ft_datadel(&key);
	else
		cipdata->key = key;
	return (cipdata->key);
}
