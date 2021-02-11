/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:31:07 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 20:50:27 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_rand.h"

static void		rand_help(t_ssl *ssl)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name,\
	"[-h] [-b | -x] [-o FILE] NUM\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -d            : DECIMAL encode output                              |\n",\
	"| -b            : BINARY encode output                               |\n",\
	"| -h            : Print command usage then exit                      |\n",\
	"| -o FILE       : Output file                                        |\n",\
	"| -x            : HEX encode output                                  |\n",\
	"**********************************************************************");
	ssl_out(ssl, SUCCESS);
}

static void		rand_it(t_rand *rand)
{
	if (!(rand->data = ft_randn(rand->n)))
		return ;
	ft_putdata_fd(rand->data, rand->fd, rand->output_mode | PRINT_ENDL);
	ft_datadel(&rand->data);
	if (rand->output)
		close(rand->fd);
}

static void		flg_analise(t_ssl *ssl, t_rand *rand, int ac, char **av)
{
	char		c_flg;
	int			i;

	i = 1;
	while (++i < ac && av[i][0] == '-' && !av[i][2])
		if ((c_flg = ssl_flag(ssl, g_rand_flags, av[i])) && c_flg == 'h')
			rand_help(ssl);
		else if (c_flg == 'x')
			rand->output_mode = PRINT_HEX;
		else if (c_flg == 'd')
			rand->output_mode = PRINT_DECIMAL;
		else if (c_flg == 'b')
			rand->output_mode = PRINT_BINARY;
		else if (++i == ac)
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
		else if (c_flg == 'o')
			rand->output = av[i];
	if (i < ac && (((rand->n = ft_atoi(av[i])) <= 0) || ++i < ac))
		ssl_err(ssl, av[i], INVALID_ARG);
	if (rand->output &&\
		(rand->fd = ft_fileopen(rand->output, O_CREAT)) <= 0)
		ssl_out(ssl, ft_errno(rand->output));
}

void			ssl_rand(t_ssl *ssl, int ac, char **av)
{
	t_rand		rand;

	rand.n = 0;
	rand.fd = STDOUT;
	rand.output = NULL;
	rand.output_mode = PRINT_CHAR;
	flg_analise(ssl, &rand, ac, av);
	rand_it(&rand);
}
