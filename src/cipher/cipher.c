/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 14:53:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_params.h"
#include "cipher_utils.h"

static void		flg_analise_value2(t_cipher *cipher, char c_flg,
									const char *arg)
{
	t_cipdata	*cipdata;

	cipdata = &cipher->cipdata;
	if (c_flg == 'p' && !(cipdata->password = ft_datastrdup(arg)))
		cipher_out(cipher, ft_printf("%w%s%s: Password malloc error.%s\n",\
					STDERR, ERR, cipdata->name, DEFAULT));
	else if (c_flg == 'k' && !(cipdata->key = get_data_from_hex_string(arg,\
						"Key", cipdata->params->key_len)))
		cipher_out(cipher, FAILURE);
	else if (c_flg == 's' && !(cipdata->salt = get_data_from_hex_string(arg,\
						"Salt", CIPHER_SALT_LEN)))
		cipher_out(cipher, FAILURE);
	else if (c_flg == 'v' && !cipher->cipdata.params->ivector_len)
		ft_printf("%w%sInitial Vector is not used by %s cipher.%s\n",\
					STDERR, WARN, cipdata->name, DEFAULT);
	else if (c_flg == 'v' && !(cipdata->ivector = get_data_from_hex_string(arg,\
						"Initial Vector", cipdata->params->ivector_len)))
		cipher_out(cipher, FAILURE);
}

static void		flg_analise_value(t_ssl *ssl, t_cipher *cipher, char c_flg,
									const char *arg)
{
	if ((arg = ft_getstrp(arg)) && !arg[0])
		ssl_err(ssl, &c_flg, MISSING_VALUE);
	if (c_flg == 'i' && !ft_fileexist(cipher->input = arg))
		cipher_out(cipher, ft_errno(cipher->input));
	else if (c_flg == 'o')
		cipher->output = arg;
	else if (!ssl->command->cipher)
		return ;
	else if (c_flg == 'n' && ((cipher->cipdata.iter = ft_atoi(arg)) <= 0))
		ssl_err(ssl, arg, INVALID_INT);
	else if (c_flg == 'n')
		cipher->cipdata.mode.is.pbkdf2 = TRUE;
	else if (c_flg == 'm' &&\
		(!(cipher->cipdata.hash_params = get_hash_params(arg)) ||\
		!(cipher->cipdata.hmac_params = get_hmac_params(arg))))
		ssl_err(ssl, arg, INVALID_HASH);
	else
		flg_analise_value2(cipher, c_flg, arg);
}

static t_bool	flg_analise_modes(t_cipher *cipher, char c_flg)
{
	if (c_flg == 'd')
		cipher->f.lg.d = TRUE;
	else if (c_flg == 'e')
		cipher->f.lg.d = FALSE;
	else if (c_flg == 'a')
		cipher->f.lg.a = TRUE;
	else if (c_flg == 'w')
		cipher->f.lg.w = TRUE;
	else if (c_flg == 'c')
		cipher->cipdata.mode.is.nopad = TRUE;
	else if (c_flg == 'f')
		cipher->cipdata.mode.is.pbkdf2 = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

static void		flg_analise(t_ssl *ssl, t_cipher *cipher, int ac, char **av)
{
	int			i;
	char		c_flg;

	i = 1;
	while (++i < ac && av[i][0] == '-' && !av[i][2])
		if ((c_flg = ssl_flag(ssl, g_cipher_flags, av[i])) && c_flg == 'h')
			cipher_help(ssl, cipher);
		else if (flg_analise_modes(cipher, c_flg))
			continue ;
		else if (++i == ac)
			ssl_err(ssl, &c_flg, MISSING_VALUE);
		else
			flg_analise_value(ssl, cipher, c_flg, av[i]);
	if (i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
	if (cipher->output &&\
		(cipher->fd = ft_fileopen(cipher->output, O_CREAT)) <= 0)
		cipher_out(cipher, ft_errno(cipher->output));
	if (cipher->cipdata.key && cipher->cipdata.params->ivector_len &&\
		!cipher->cipdata.ivector && !cipher->cipdata.password &&\
		ft_printf("%w%sInitial Vector is undefined.%s\n", STDERR, ERR, DEFAULT))
		cipher_out(cipher, FAILURE);
}

void			cipher(t_ssl *ssl, int ac, char **av)
{
	t_cipher	cipher;

	cipher_init(ssl, &cipher);
	flg_analise(ssl, &cipher, ac, av);
	if (!ssl->command->cipher)
		base64_it(get_data_from_fd(cipher.input), cipher.fd, cipher.f.lg.d);
	else
		cipher_it(&cipher, cipher.f.lg.d);
	cipher_out(&cipher, SUCCESS);
}
