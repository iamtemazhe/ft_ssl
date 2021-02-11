/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:51:59 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_params.h"
#include "cipher_utils.h"

static void		cipdata_out(t_cipher *cipher)
{
	ft_putstr_fd("salt = ", cipher->fd);
	if (cipher->cipdata.salt)
		ft_putdata_fd(cipher->cipdata.salt, cipher->fd,\
						PRINT_HEX_UP | PRINT_ENDL);
	else
		ft_fprintf(cipher->fd, "%017\n");
	ft_putstr_fd("key  = ", cipher->fd);
	ft_putdata_fd(cipher->cipdata.key, cipher->fd, PRINT_HEX_UP | PRINT_ENDL);
	if (cipher->cipdata.ivector && ft_putstr_fd("iv   = ", cipher->fd))
		ft_putdata_fd(cipher->cipdata.ivector,\
						cipher->fd, PRINT_HEX_UP | PRINT_ENDL);
	cipher_out(cipher, SUCCESS);
}

static t_data	*salt_magic(t_cipdata *cipdata, t_data *cip,\
								t_bool decrypt_mode)
{
	t_data		*salted_cip;

	if (!cipdata->mode.is.salted || decrypt_mode)
		return (cip);
	salted_cip = ft_datajoin(&g_cipher_magic, cipdata->salt);
	salted_cip = ft_datarealloc(salted_cip, cip);
	ft_datadel(&cip);
	return (salted_cip);
}

static t_data	*validate_decrypt_msg(t_cipdata *cipdata, const char *file_name,
										t_bool decrypt_mode, t_bool base64_mode)
{
	t_data		*msg;
	t_data		*clear_msg;

	clear_msg = NULL;
	if (!cipdata->key && !get_password(cipdata, decrypt_mode))
		return (NULL);
	if (!(msg = get_data_from_fd(file_name)))
		return (NULL);
	if (base64_mode && !ft_datafreplace(&msg, base64_decode(msg->data, msg->n)))
		return (NULL);
	if (!cipdata->password && cipdata->key &&\
		(!cipdata->params->ivector_len || cipdata->ivector))
		return (msg);
	if (msg->n < CIPHER_MAGIC_LEN ||\
		ft_memcmp(msg->data, g_cipher_magic.data, g_cipher_magic.n))
		ft_printf("%w%sBad %s.%s\n",\
					STDERR, ERR, g_cipher_magic.file_name, DEFAULT);
	else if (ft_datafreplace(&cipdata->salt,\
		ft_datamemdup(msg->data + g_cipher_magic.n, CIPHER_SALT_LEN)))
		clear_msg = ft_datamemdup(msg->data + CIPHER_MAGIC_LEN,\
										msg->n - CIPHER_MAGIC_LEN);
	ft_datadel(&msg);
	return (clear_msg);
}

static t_data	*precipher(t_cipher *cipher, t_data **p_msg,\
							t_bool decrypt_mode)
{
	if (!get_key(&cipher->cipdata, decrypt_mode))
		return (ft_datadel_rn(p_msg));
	if (cipher->f.lg.w)
		cipdata_out(cipher);
	if (!decrypt_mode && !(*p_msg = get_data_from_fd(cipher->input)))
		return (NULL);
	return (*p_msg);
}

void			cipher_it(t_cipher *cipher, t_bool decrypt_mode)
{
	t_data		*msg;
	t_data		*cip;

	msg = NULL;
	if (decrypt_mode && !(msg = validate_decrypt_msg(&cipher->cipdata,\
							cipher->input, decrypt_mode, cipher->f.lg.a)))
		cipher_out(cipher, FAILURE);
	else if (!precipher(cipher, &msg, decrypt_mode))
		cipher_out(cipher, FAILURE);
	cip = cipher->cipdata.params->cipher(msg->data, msg->n,\
											&cipher->cipdata, decrypt_mode);
	ft_datadel(&msg);
	if (!(cip = salt_magic(&cipher->cipdata, cip, decrypt_mode)))
		cipher_out(cipher, FAILURE);
	if (cipher->f.lg.a && !decrypt_mode)
		base64_it(cip, cipher->fd, decrypt_mode);
	else
	{
		ft_putdata_fd(cip, cipher->fd, PRINT_CHAR);
		ft_datadel(&cip);
	}
}
