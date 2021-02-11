/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_gendsa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 04:27:19 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:33:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsa_utils.h"
#include "dsa_options.h"

void			gen_dsa(t_dsa *dsa)
{
	uint64_t	h;

	ft_fprintf(STDERR, "Generating DSA key, %u bit long prime\n", dsa->bits);
	get_dsa64prime(dsa, &dsa->q, FALSE, MAX_UINT16);
	get_dsa64prime(dsa, &dsa->p, TRUE, MAX_UINT64);
	h = DSA_DEFAULT_H;
	while ((dsa->g = ft_modpow(h, ((dsa->p - 1) / dsa->q), dsa->p)) < 2 &&\
			dsa->g >= dsa->p)
		h++;
	get_dsa64prime(dsa, &dsa->x, FALSE, dsa->q);
	dsa->y = ft_modpow(dsa->g, dsa->x, dsa->p);
	construct_dsa_key(dsa);
}

static t_bool	flg_analise_value(t_dsa *dsa, t_dsa_flag f, const char *arg)
{
	dsa->f.lag |= f.lag ^ SSL_FLG_HAS_VAL;
	if ((arg = ft_getstrp(arg)) && !arg[0])
		return (FALSE);
	else if (f.lg.i && !ft_fileexist(dsa->input = arg))
		dsa_out(dsa, ft_errno(dsa->input));
	else if (f.lg.o)
		dsa->output = arg;
	return (TRUE);
}

static void		flg_analise(t_ssl *ssl, t_dsa *dsa, int ac, char **av)
{
	int			i;
	t_dsa_flag	f;

	i = 1;
	while (++i < ac && av[i][0] == '-')
		if (!(f.lag = ssl_options(g_dsa_options, DSA_FLG_NUM, av[i])))
			ssl_err(ssl, av[i], INVALID_FLG);
		else if (f.lg.h)
			gendsa_help(ssl, dsa);
		else if (!IS_FLG(f.lag, SSL_FLG_HAS_VAL))
			dsa->f.lag |= f.lag;
		else if (++i == ac || !flg_analise_value(dsa, f, av[i]))
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
	if (i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
}

void			ssl_gendsa(t_ssl *ssl, int ac, char **av)
{
	t_dsa		dsa;

	dsa_init(&dsa);
	flg_analise(ssl, &dsa, ac, av);
	(dsa.input) ? get_dsa_key(&dsa) : gen_dsa(&dsa);
	dsa_print(&dsa);
	dsa_out(&dsa, SUCCESS);
}
