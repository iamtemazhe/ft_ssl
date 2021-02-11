/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 06:28:59 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 11:39:00 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsa_utils.h"
#include "dsa_params.h"

static void			dsa_print_key(t_dsa *dsa, const t_data *key,\
								const t_data *sline, const t_data *eline)
{
	t_data			*cip;

	if (dsa->f.lg.n)
		return ;
	if (dsa->input)
		ft_putstr_fd("writing DSA key\n", STDERR);
	ft_putdata_fd(sline, dsa->fd, PRINT_CHAR | PRINT_ENDL);
	if ((cip = base64_encode(key->data, key->n)))
	{
		base64_print(cip, dsa->fd, FALSE);
		ft_datadel(&cip);
	}
	ft_putdata_fd(eline, dsa->fd, PRINT_CHAR | PRINT_ENDL);
}

static void			dsa_print_text(t_dsa *dsa)
{
	ft_printf("%w%s(%u bit)%s%llu (0x%llx)%s%zu (0x%llx)", dsa->fd,\
	"Private-Key: ", dsa->bits,\
	"\npriv: ", dsa->x, dsa->x, "\npub:  ", dsa->y, dsa->y);
	ft_printf("%w%s%lU (0x%llx)%s%lU (0x%llx)%s%lU (0x%llx)\n", dsa->fd,\
	"\nP:    ", dsa->p, dsa->p, "\nQ:    ", dsa->q, dsa->q,\
	"\nG:    ", dsa->g, dsa->g);
}

void				dsa_print(t_dsa *dsa)
{
	if (dsa->output && (dsa->fd = ft_fileopen(dsa->output, O_CREAT)) <= 0)
		dsa_out(dsa, ft_errno(dsa->output));
	if (dsa->f.lg.t)
		dsa_print_text(dsa);
	if (dsa->f.lg.m)
		ft_fprintf(dsa->fd, "Public Key=%zX\n", dsa->y);
	dsa_print_key(dsa, dsa->key, &g_dsa_key_sline, &g_dsa_key_eline);
	dsa_out(dsa, SUCCESS);
}
