/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_genrsa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 07:21:24 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 11:27:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "genrsa_options.h"

void			gen_rsa(t_rsa *rsa)
{
	uint64_t	fi;

	ft_fprintf(STDERR, "Generating RSA private key, %u bit long modulus\n",\
																	rsa->bits);
	get_rsa32prime(rsa, &rsa->p, FALSE);
	get_rsa32prime(rsa, &rsa->q, TRUE);
	if (rsa->p < rsa->q)
		ft_lswap(&rsa->p, &rsa->q);
	fi = (rsa->p - 1) * (rsa->q - 1);
	if (!rsa->e)
		while (ft_gcd(rsa->e, fi) != 1)
			if (!(rsa->e = ft_rand(3, fi - 1)))
				rsa_out(rsa, FAILURE);
	ft_fprintf(STDERR, "e is %u (0x%X)\n", rsa->e, rsa->e);
	rsa->n = rsa->p * rsa->q;
	rsa->d = ft_modmult_inv(rsa->e, fi);
	rsa->dp = rsa->d % (rsa->p - 1);
	rsa->dq = rsa->d % (rsa->q - 1);
	rsa->iq = ft_modmult_inv(rsa->q, rsa->p);
	construct_rsa_key(rsa);
}

static t_bool	flg_analise_value(t_ssl *ssl, t_rsa *rsa, t_rsa_flag f,
									const char *arg)
{
	rsa->f.lag |= f.lag ^ SSL_FLG_HAS_VAL;
	if ((arg = ft_getstrp(arg)) && !arg[0])
		return (FALSE);
	else if (f.lg.i && !ft_fileexist(rsa->input = arg))
		rsa_out(rsa, ft_errno(rsa->input));
	else if (f.lg.o)
		rsa->output = arg;
	return (TRUE);
}

static void		flg_analise(t_ssl *ssl, t_rsa *rsa, int ac, char **av)
{
	int			i;
	t_rsa_flag	f;

	i = 1;
	while (++i < ac && av[i][0] == '-')
		if (!(f.lag = ssl_options(ssl, g_genrsa_options,\
									GENRSA_FLG_NUM, av[i])))
			ssl_err(ssl, av[i], INVALID_FLG);
		else if (f.lg.h)
			genrsa_help(ssl, rsa);
		else if (!IS_FLG(f.lag, SSL_FLG_HAS_VAL))
			rsa->f.lag |= f.lag;
		else if (++i == ac || !flg_analise_value(ssl, rsa, f, av[i]))
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
	if (i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
}

void			ssl_genrsa(t_ssl *ssl, int ac, char **av)
{
	t_rsa		rsa;

	rsa_init(ssl, &rsa);
	flg_analise(ssl, &rsa, ac, av);
	(rsa.input) ? get_rsa_key(&rsa) : gen_rsa(&rsa);
	rsa_print(&rsa);
	rsa_out(&rsa, SUCCESS);
}
