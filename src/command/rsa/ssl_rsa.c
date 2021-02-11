/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_rsa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:04:36 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 10:14:15 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsa_options.h"

static t_bool	flg_analise_value(t_ssl *ssl, t_rsa *rsa, t_rsa_flag f,\
										const char *arg)
{
	t_bool		tmp_flg;

	tmp_flg = FALSE;
	rsa->f.lag |= f.lag ^ SSL_FLG_HAS_VAL;
	if ((arg = ft_getstrp(arg)) && !arg[0])
		return (FALSE);
	else if (f.lg.i && !ft_fileexist(rsa->input = arg))
		rsa_out(rsa, ft_errno(rsa->input));
	else if (f.lg.o)
		rsa->output = arg;
	else if ((f.lg.fi || f.lg.fo) && ft_strcmpi(RSA_KEY_FORMAT_PEM, arg) &&\
		!(tmp_flg = (!ft_strcmpi(RSA_KEY_FORMAT_DER, arg))))
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
			"%s: Invalid key format '%s' given.\n", ssl->command->name, arg));
	else if (f.lg.fi)
		rsa->is_inform_der = tmp_flg;
	else if (f.lg.fo)
		rsa->is_outform_der = tmp_flg;
	else if (f.lg.pi && !(rsa->cipdata_in.password = ft_datastrdup(arg)))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "%s: Password malloc error.\n",\
								rsa->cipdata_in.name));
	else if (f.lg.po && !(rsa->cipdata_out.password = ft_datastrdup(arg)))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "%s: Password malloc error.\n",\
								rsa->cipdata_out.name));
	return (TRUE);
}

static void		flg_analise(t_ssl *ssl, t_rsa *rsa, int ac, char **av)
{
	int			i;
	t_rsa_flag	f;

	i = 1;
	while (++i < ac && av[i][0] == '-')
		if (fill_cipher_params(rsa->ciphers, &av[i][1], &rsa->cipdata_out))
			continue ;
		else if (!(f.lag = ssl_options(ssl, g_rsa_options, RSA_FLG_NUM, av[i])))
			ssl_err(ssl, av[i], INVALID_FLG);
		else if (f.lg.h)
			rsa_help(ssl, rsa);
		else if (!IS_FLG(f.lag, SSL_FLG_HAS_VAL))
			rsa->f.lag |= f.lag;
		else if (++i == ac || !flg_analise_value(ssl, rsa, f, av[i]))
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
	if (i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
	if (rsa->f.lg.c && rsa->f.lg.bi)
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Only private keys can be checked\n"));
}

void			ssl_rsa(t_ssl *ssl, int ac, char **av)
{
	t_rsa		rsa;

	rsa_init(ssl, &rsa);
	flg_analise(ssl, &rsa, ac, av);
	(rsa.f.lg.bi) ? get_rsa_pkey(&rsa) : get_rsa_key(&rsa);
	(rsa.f.lg.bo) ? construct_rsa_pkey(&rsa) : construct_rsa_key(&rsa);
	rsa_print(&rsa);
	rsa_out(&rsa, SUCCESS);
}
