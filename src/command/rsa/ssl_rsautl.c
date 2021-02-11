/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_rsautl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:04:36 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:27:26 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsautl_options.h"

static t_bool		flg_analise_value(t_ssl *ssl, t_rsa *rsa, t_rsa_flag f,\
										const char *arg)
{
	rsa->f.lag |= f.lag ^ SSL_FLG_HAS_VAL;
	if ((arg = ft_getstrp(arg)) && !arg[0])
		return (FALSE);
	else if (f.lg.ki && !ft_fileexist(rsa->input = arg))
		rsa_out(rsa, ft_errno(rsa->input));
	else if (f.lg.i && !ft_fileexist(rsa->input_file = arg))
		rsa_out(rsa, ft_errno(rsa->input_file));
	else if (f.lg.o)
		rsa->output = arg;
	else if (f.lg.fi && ft_strcmpi(RSA_KEY_FORMAT_PEM, arg) &&\
		!(rsa->is_inform_der = (!ft_strcmpi(RSA_KEY_FORMAT_DER, arg))))
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
			"%s: Invalid key format '%s' given.\n", ssl->command->name, arg));
	else if (f.lg.pi && !(rsa->cipdata_in.password = ft_datastrdup(arg)))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "%s: Password malloc error.\n",\
								rsa->cipdata_in.name));
	return (TRUE);
}

static void			flg_analise(t_ssl *ssl, t_rsa *rsa, int ac, char **av)
{
	int				i;
	t_rsa_flag		f;

	i = 1;
	while (++i < ac && av[i][0] == '-')
		if (!(f.lag = ssl_options(g_rsautl_options,\
													RSAUTL_FLG_NUM, av[i])))
			ssl_err(ssl, av[i], INVALID_FLG);
		else if (f.lg.h)
			rsautl_help(ssl, rsa);
		else if (f.lg.e || f.lg.d)
			rsa->f.lg.d = (f.lg.e) ? FALSE : TRUE;
		else if (!IS_FLG(f.lag, SSL_FLG_HAS_VAL))
			rsa->f.lag |= f.lag;
		else if (++i == ac || !flg_analise_value(ssl, rsa, f, av[i]))
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
	if (i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
	if (!rsa->f.lg.ki)
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
			"No keyfile specified. Use [-ki FILE | -inkey FILE] options\n"));
	if (rsa->f.lg.d && rsa->f.lg.bi)
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
					"Private key is needed for this operation\n"));
}

void				ssl_rsautl(t_ssl *ssl, int ac, char **av)
{
	t_rsa			rsa;

	rsa_init(ssl, &rsa);
	flg_analise(ssl, &rsa, ac, av);
	(rsa.f.lg.bi) ? get_rsa_pkey(&rsa) : get_rsa_key(&rsa);
	rsa_it(&rsa, get_data_from_fd(rsa.input_file), rsa.f.lg.d);
	rsa_out(&rsa, SUCCESS);
}
