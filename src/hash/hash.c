/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:36:18 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 14:47:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include "hash_params.h"

static void		hash_out(t_ssl *ssl)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name,\
	"[-h] [-r] [-q] [-p] [-s TEXT] <file1> <...> <fileN>\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -h            : Print command usage then exit                      |\n",\
	"| -p            : Echo STDIN and append the checksum to STDOUT       |\n",\
	"| -q            : Quiet mode                                         |\n",\
	"| -r            : Reverse the format of the output                   |\n",\
	"| -s TEXT       : Print the sum of the given string TEXT             |\n",\
	"**********************************************************************");
	ssl_out(ssl, SUCCESS);
}

static void		put_name(t_ssl *ssl, t_hash_f *hash_f, t_data *msg)
{
	if (hash_f->lg.q)
		return ;
	if (!hash_f->lg.r)
		ft_printf("%s (", ssl->command->out);
	else
		ft_putstr(" ");
	if (msg->file_name)
		ft_putstr(msg->file_name);
	else
		ft_printf("\"%s\"", msg->data);
	if (!hash_f->lg.r)
		ft_putstr(") = ");
}

static void		hash_it(t_ssl *ssl, t_hash_f *hash_f, t_data *msg, uint8_t flg)
{
	t_data		*hash;

	if (!msg)
		return ;
	if ((hash = ssl->command->hash(msg->data, msg->n)))
	{
		if (IS_FLG(flg, FLG_P) && (hash_f->lg.r || !hash_f->lg.q))
			ft_printf("%s", msg->data);
		if (IS_FLG(flg, FLG_IN))
			ft_putdata(hash);
		else
		{
			if (!hash_f->lg.r)
				put_name(ssl, hash_f, msg);
			ft_putdata(hash);
			if (hash_f->lg.r)
				put_name(ssl, hash_f, msg);
		}
	}
	ft_putstr("\n");
	ft_datadel(&msg);
	ft_datadel(&hash);
}

static int		flg_analise(t_ssl *ssl, t_hash_f *hash_f, int ac, char **av)
{
	char		c_flg;
	int			i;

	i = 1;
	while (++i < ac && av[i][0] == '-' && !av[i][2])
		if ((c_flg = ssl_flag(ssl, g_hash_flags, av[i])) && c_flg == 'p')
			hash_it(ssl, hash_f, get_data_from_fd(NULL), FLG_IN | FLG_P);
		else if (c_flg == 'h')
			hash_out(ssl);
		else if (c_flg == 'q')
			hash_f->lg.q = TRUE;
		else if (c_flg == 'r')
			hash_f->lg.r = TRUE;
		else if (++i == ac)
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
		else if (c_flg == 's')
		{
			hash_it(ssl, hash_f, get_data_from_text(av[i++]), FLG_S);
			break ;
		}
		else
			ssl_err(ssl, av[i], INVALID_FLG);
	return (i);
}

void			hash(t_ssl *ssl, int ac, char **av)
{
	t_hash_f	hash_f;
	int			i;

	hash_f.lag = 0;
	if (ac == 2)
		hash_it(ssl, &hash_f, get_data_from_fd(NULL), FLG_IN);
	else
	{
		i = flg_analise(ssl, &hash_f, ac, av);
		while (i < ac)
			hash_it(ssl, &hash_f, get_data_from_fd(av[i++]), 0);
	}
}
