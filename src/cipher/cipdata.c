/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 06:09:13 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_utils.h"

t_data			*get_salt(t_cipdata *cipdata)
{
	if (cipdata->salt)
		return (cipdata->salt);
	cipdata->salt = ft_randn(CIPHER_SALT_LEN);
	return (cipdata->salt);
}

t_data			*get_password(t_cipdata *cipdata, t_bool decrypt_mode)
{
	char		*pass;

	if (cipdata->password)
		return (cipdata->password);
	pass = (decrypt_mode) ? getpass("Enter decryption password:") :\
							getpass("Enter encryption password:");
	if (!pass)
		ft_printf("%w%s%s: Password malloc error.", STDERR, ERR, cipdata->name);
	else if (!pass[0])
		ft_printf("%w%s%s: Password is missing.", STDERR, ERR, cipdata->name);
	else if (!(cipdata->password = ft_datastrreplace(&pass)))
		ft_printf("%w%s%s: Password malloc error.", STDERR, ERR, cipdata->name);
	else if (decrypt_mode)
		return (cipdata->password);
	else if (!(pass = getpass("Verifying encryption password:")))
		ft_printf("%w%s%s: Password malloc error.", STDERR, ERR, cipdata->name);
	else if (((ft_strlen(pass) != cipdata->password->n) ||\
		ft_memcmp(cipdata->password->data, pass, cipdata->password->n)))
		ft_printf("%w%s%s: Passwords differ.", STDERR, ERR, cipdata->name);
	else
		return (cipdata->password);
	ft_printf("%w%s\n", STDERR, DEFAULT);
	return (NULL);
}

void			cipdata_free(t_cipdata *cipdata)
{
	ft_datadel(&cipdata->key);
	ft_datadel(&cipdata->password);
	ft_datadel(&cipdata->salt);
	ft_datadel(&cipdata->ivector);
	ft_datadel(&cipdata->pbkdf2_s);
	ft_datadel(&cipdata->pbkdf2_u);
}

void			cipdata_init(t_cipdata *cipdata)
{
	cipdata->mode.val = 0;
	cipdata->iter = CIPHER_ITER_COUNT;
	cipdata->key = NULL;
	cipdata->password = NULL;
	cipdata->salt = NULL;
	cipdata->ivector = NULL;
	cipdata->pbkdf2_s = NULL;
	cipdata->pbkdf2_u = NULL;
	cipdata->hash_params = NULL;
	cipdata->hmac_params = NULL;
	cipdata->params = NULL;
	cipdata->name = NULL;
}
