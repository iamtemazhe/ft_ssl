/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_hexdump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:13:53 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 03:47:57 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_hexdump.h"

static void		hexdump_help(t_ssl *ssl)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s\n",\
	GRAY, ssl->prog_name, ssl->command->name,\
	"[-h] [-i FILE] [-o FILE] NUM\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -h            : Print command usage then exit                      |\n",\
	"| -i FILE       : Input file                                         |\n",\
	"| -o FILE       : Output file                                        |\n",\
	"| -x            : HEX encode output                                  |\n",\
	"**********************************************************************");
	ssl_out(ssl, SUCCESS);
}

static void		dump_it(t_ssl *ssl, t_hexdump *dump)
{
	if (!(dump->data = get_data_from_fd(dump->input)))
		ssl_out(ssl, FAILURE);
	if (dump->output &&\
		(dump->fd = ft_fileopen(dump->output, O_CREAT)) <= 0)
		ssl_out(ssl, ft_errno(dump->output));
	ft_hexdump_fd(dump->fd, dump->data->data, dump->data->n, dump->n);
	ft_datadel(&dump->data);
	if (dump->output)
		close(dump->fd);
}

static void		flg_analise(t_ssl *ssl, t_hexdump *dump, int ac, char **av)
{
	char		c_flg;
	int			i;

	i = 1;
	while (++i < ac && av[i][0] == '-' && !av[i][2])
		if ((c_flg = ssl_flag(ssl, g_hexdump_flags, av[i])) && c_flg == 'h')
			hexdump_help(ssl);
		else if (++i == ac)
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
		else if (c_flg == 'i' && !ft_fileexist(dump->input = av[i]))
			ssl_out(ssl, ft_errno(dump->input));
		else if (c_flg == 'o')
			dump->output = av[i];
	if (i < ac && (((dump->n = ft_atoi(av[i])) <= 0) || ++i < ac))
		ssl_err(ssl, av[i], INVALID_ARG);
}

void			ssl_hexdump(t_ssl *ssl, int ac, char **av)
{
	t_hexdump	dump;

	dump.n = 0;
	dump.n = BYTE_SIZE * 2;
	dump.fd = STDOUT;
	dump.input = NULL;
	dump.output = NULL;
	dump.output_mode = PRINT_CHAR;
	flg_analise(ssl, &dump, ac, av);
	dump_it(ssl, &dump);
}
