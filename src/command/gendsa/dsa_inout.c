/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_inout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 06:31:15 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 10:38:47 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsa_utils.h"

void			gendsa_help(t_ssl *ssl, t_dsa *dsa)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name,\
	"[-h] [-t] [-m] [-n] [-i FILE] [-o FILE]\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -h  | -help             : Print command usage then exit            |\n",\
	"| -m  | -modulus          : Print DSA key modulus                    |\n",\
	"| -n  | -noout            : Don't print key out                      |\n",\
	"| -t  | -text             : Print key in text                        |\n",\
	"| -i  | -in FILE          : Input file                               |\n",\
	"| -o  | -out FILE         : Output file                              |\n",\
	"**********************************************************************");
	dsa_out(dsa, SUCCESS);
}

void			dsa_out(t_dsa *dsa, int prnt)
{
	ft_datadel(&dsa->key);
	if (dsa->fd > STDERR)
		close(dsa->fd);
	exit((prnt) ? FAILURE : SUCCESS);
}

void			dsa_init(t_ssl *ssl, t_dsa *dsa)
{
	dsa->f.lag = 0;
	dsa->fd = STDOUT;
	dsa->input = NULL;
	dsa->output = NULL;
	dsa->key = NULL;
	dsa->bits = DSA_BITS;
	dsa->p = 0;
	dsa->q = 0;
	dsa->x = 0;
}
