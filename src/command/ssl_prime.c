/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_prime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 04:28:57 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 14:21:41 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_prime.h"

static void		prime_help(t_ssl *ssl)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name,\
	"[-h] [-k CYCLES] [-o FILE] NUM\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -h            : Print command usage then exit                      |\n",\
	"| -k CYCLES     : Check cycles count                                 |\n",\
	"| -o FILE       : Output file                                        |\n",\
	"**********************************************************************");
	ssl_out(ssl, SUCCESS);
}

static void		is_prime(t_prime *prime)
{
	if (ft_isprime_mr(prime->n, prime->k))
	{
		ft_printf("%wNumber %lld is Prime.\nProbability: %04.2llf%%\n",\
			prime->fd, prime->n, (1 - ft_fpow(4, -(long long)prime->k)) * 100);
	}
	else
		ft_printf("%wNumber %lld is not Prime.\n", prime->fd, prime->n);
	if (prime->fd > STDERR)
		close(prime->fd);
}

static void		flg_analise(t_ssl *ssl, t_prime *prime, int ac, char **av)
{
	char		c_flg;
	int			i;

	i = 1;
	while (++i < ac && av[i][0] == '-' && !av[i][2])
		if ((c_flg = ssl_flag(ssl, g_prime_flags, av[i])) && c_flg == 'h')
			prime_help(ssl);
		else if (++i == ac)
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
		else if (c_flg == 'o')
			prime->output = av[i];
		else if (c_flg == 'k' && (prime->k = ft_atoi(av[i])) <= 0)
			ssl_err(ssl, av[i], INVALID_INT);
	if (i < ac && (((prime->n = ft_latoi(av[i])) <= 0) || ++i < ac))
		ssl_err(ssl, av[i], INVALID_ARG);
	if (prime->output &&\
		(prime->fd = ft_fileopen(prime->output, O_CREAT)) <= 0)
		ssl_out(ssl, ft_errno(prime->output));
}

void			ssl_prime(t_ssl *ssl, int ac, char **av)
{
	t_prime		prime;

	prime.n = 0;
	prime.k = PRIME_RSA_K;
	prime.fd = STDOUT;
	prime.output = NULL;
	flg_analise(ssl, &prime, ac, av);
	is_prime(&prime);
}
