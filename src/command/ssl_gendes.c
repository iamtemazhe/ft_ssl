/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_gendes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 12:22:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_params.h"
#include "cipher_utils.h"
#include "ssl_gendes.h"

static void		gendes_help(t_ssl *ssl, t_cipher *cipher)
{
	ft_tprintf(STDERR, GRAY, "%s %s %s %s%s%s%s%s%s%s%s%s%s%s%s\n",\
	"usage:", ssl->prog_name, ssl->command->name,\
	"[-h] [-o FILE] [-p PASSWORD] "
	"[-k KEY] [-s SALT] [-v VECTOR] [-m HASH] [-n ITER]\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -f            : Use Password-Based Key Derivation Function 2       |\n",\
	"| -h            : Print command usage then exit                      |\n",\
	"| -k KEY        : Key in HEX                                         |\n",\
	"| -m HASH       : Specified HASH to create KEY from PASSWORD         |\n",\
	"| -n ITER       : Iteration count in uint and force use of PBKDF2    |\n",\
	"| -o FILE       : Output file                                        |\n",\
	"| -p PASSWORD   : Password in ASCII                                  |\n",\
	"| -s SALT       : Salt in HEX                                        |\n",\
	"| -v VECTOR     : Initialization vector (iv) VECTOR in HEX           |\n",\
	"**********************************************************************");
	cipher_out(cipher, SUCCESS);
}

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
	if (c_flg == 'o')
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

static void		flg_analise(t_ssl *ssl, t_cipher *cipher, int ac, char **av)
{
	int			i;
	char		c_flg;

	i = 1;
	while (++i < ac && av[i][0] == '-')
		if (fill_cipher_params(ssl->ciphers, &av[i][1], &cipher->cipdata))
			continue ;
		else if (av[i][2])
			ssl_err(ssl, av[i], INVALID_FLG);
		else if ((c_flg = ssl_flag(ssl, g_gendes_flags, av[i])) && c_flg == 'h')
			gendes_help(ssl, cipher);
		else if (c_flg == 'f')
			cipher->cipdata.mode.is.pbkdf2 = TRUE;
		else if (++i == ac)
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
		else
			flg_analise_value(ssl, cipher, c_flg, av[i]);
	if (i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
	if (cipher->output &&\
		(cipher->fd = ft_fileopen(cipher->output, O_CREAT)) <= 0)
		cipher_out(cipher, ft_errno(cipher->output));
}

void			ssl_gendes(t_ssl *ssl, int ac, char **av)
{
	t_cipher	cipher;

	cipher_init(ssl, &cipher);
	cipher.f.lg.w = TRUE;
	flg_analise(ssl, &cipher, ac, av);
	cipher_it(&cipher, cipher.f.lg.d);
	cipher_out(&cipher, SUCCESS);
}
