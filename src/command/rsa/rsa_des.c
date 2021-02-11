/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_des.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 13:11:50 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsa_params.h"

static t_data	*get_cipher_key(t_cipdata *cipdata, t_bool decrypt_mode)
{
	if (cipdata->key)
		return (cipdata->key);
	if (!(get_password(cipdata, decrypt_mode) && get_salt(cipdata)))
		return (NULL);
	if (!cipdata->ivector && !(cipdata->ivector = ft_datadup(cipdata->salt)))
		return (NULL);
	return (get_key(cipdata, decrypt_mode));
}

static void		rsa_cipher_decrypt(t_rsa *rsa, t_data **p_key, t_data *key)
{
	if (!fill_cipher_params(rsa->ciphers,\
		get_cipher_name(rsa->ciphers, key->data, ','), &rsa->cipdata_in))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Unsupported encryption\n"));
	key->data += ft_strlen(rsa->cipdata_in.params->name) + 1;
	if (!(rsa->cipdata_in.salt = get_data_from_hex_string(key->data,\
								"Salt", CIPHER_SALT_LEN)))
		rsa_out(rsa, FAILURE);
	key->data += CIPHER_SALT_LEN * 2 + 2;
	key->n -= ft_strlen(rsa->cipdata_in.params->name) + CIPHER_SALT_LEN * 2 + 3;
	if (!ft_datafreplace(p_key, base64_decode(key->data, key->n)))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Base64 decode error.\n"));
	if (!get_cipher_key(&rsa->cipdata_in, TRUE))
		rsa_out(rsa, FAILURE);
	if (!(ft_datafreplace(p_key, rsa->cipdata_in.params->cipher((*p_key)->data,\
		(*p_key)->n, &rsa->cipdata_in, TRUE))))
		rsa_out(rsa, FAILURE);
	cipdata_free(&rsa->cipdata_in);
}

void			rsa_pem_decode(t_rsa *rsa, t_data **p_key, t_data *key)
{
	if (key->n > RSA_PTYPE_MIN_LEN &&
		!ft_memcmp(key->data, g_rsa_ptype.data, g_rsa_ptype.n))
	{
		key->data += g_rsa_ptype.n;
		key->n -= g_rsa_ptype.n;
		rsa_cipher_decrypt(rsa, p_key, key);
	}
	else if (rsa->f.lg.pi)
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Bad %s\n", g_rsa_ptype.file_name));
	else if (!ft_datafreplace(p_key,\
								base64_decode(key->data, key->n)))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Base64 decode error.\n"));
}

static void		rsa_cipher_encrypt(t_rsa *rsa, const t_data *key)
{
	t_data		*cip;

	cip = rsa->cipdata_out.params->cipher(key->data, key->n,\
											&rsa->cipdata_out, FALSE);
	ft_putdata_fd(&g_rsa_ptype, rsa->fd, PRINT_CHAR);
	ft_putupper_fd(rsa->cipdata_out.name, rsa->fd);
	ft_putchar_fd(',', rsa->fd);
	ft_putdata_fd(rsa->cipdata_out.ivector, rsa->fd, PRINT_HEX_UP | PRINT_ENDL);
	ft_putchar_fd('\n', rsa->fd);
	if (ft_datafreplace(&cip, base64_encode(cip->data, cip->n)))
		base64_print(cip, rsa->fd, FALSE);
	ft_datadel(&cip);
	cipdata_free(&rsa->cipdata_out);
}

void			rsa_pem_encode(t_rsa *rsa, const t_data *key,\
								const t_data *sline, const t_data *eline)
{
	t_data		*cip;

	if (rsa->cipdata_out.params && !get_cipher_key(&rsa->cipdata_out, FALSE))
		rsa_out(rsa, FAILURE);
	ft_putdata_fd(sline, rsa->fd, PRINT_CHAR | PRINT_ENDL);
	if (rsa->cipdata_out.params)
		rsa_cipher_encrypt(rsa, key);
	else if ((cip = base64_encode(key->data, key->n)))
	{
		base64_print(cip, rsa->fd, FALSE);
		ft_datadel(&cip);
	}
	ft_putdata_fd(eline, rsa->fd, PRINT_CHAR | PRINT_ENDL);
}
