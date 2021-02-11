/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:29:34 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsa_params.h"

static void			rsa_print_key(t_rsa *rsa, const t_data *key,\
								const t_data *sline, const t_data *eline)
{
	if (rsa->f.lg.n)
		return ;
	if (rsa->input)
		ft_putstr_fd("writing RSA key\n", STDERR);
	if (rsa->is_outform_der)
		ft_putdata_fd(key, rsa->fd, PRINT_CHAR);
	else
		rsa_pem_encode(rsa, key, sline, eline);
}

static void			rsa_print_text(t_rsa *rsa)
{
	if (rsa->f.lg.bi)
		ft_printf("%w%s(%u%s)%s%lU (0x%llx)%s%lU (0x%llx)\n", rsa->fd,\
		"RSA Public-Key: ", rsa->bits, " bit",\
		"\nModulus: ", rsa->n, rsa->n, "\nExponent: ", rsa->e, rsa->e);
	else
	{
		ft_printf("%w%s(%u%s%u%s)%s%lU (0x%llx)%s%lU (0x%llx)", rsa->fd,\
		"RSA Private-Key: ", rsa->bits, " bit, ", rsa->primes, " primes",\
		"\nmodulus: ", rsa->n, rsa->n, "\npublicExponent: ", rsa->e, rsa->e);
		ft_printf("%w%s%lU (0x%llx)%s%lU (0x%llx)%s%lU (0x%llx)", rsa->fd,\
		"\nprivateExponent: ", rsa->d, rsa->d,\
		"\nprime1: ", rsa->p, rsa->p, "\nprime2: ", rsa->q, rsa->q);
		ft_printf("%w%s%lU (0x%llx)%s%lU (0x%llx)%s%lU (0x%llx)\n", rsa->fd,\
		"\nexponent1: ", rsa->dp, rsa->dp, "\nexponent2: ", rsa->dq, rsa->dq,\
		"\ncoefficient: ", rsa->iq, rsa->iq);
	}
}

void				rsa_print(t_rsa *rsa)
{
	if (rsa->output && (rsa->fd = ft_fileopen(rsa->output, O_CREAT)) <= 0)
		rsa_out(rsa, ft_errno(rsa->output));
	if (rsa->f.lg.t)
		rsa_print_text(rsa);
	if (rsa->f.lg.m)
		ft_fprintf(rsa->fd, "Modulus=%llX\n", rsa->n);
	check_rsa_key(rsa);
	if (rsa->f.lg.bi || rsa->f.lg.bo)
		rsa_print_key(rsa, rsa->pkey, &g_rsa_pkey_sline, &g_rsa_pkey_eline);
	else
		rsa_print_key(rsa, rsa->key, &g_rsa_key_sline, &g_rsa_key_eline);
	rsa_out(rsa, SUCCESS);
}

void				rsa_hexdump(t_rsa *rsa, const t_data *src_data)
{
	size_t			i;
	uint8_t			buff[RSA_DUMP_BYTES + 1];
	const uint8_t	*u8data;

	i = 0;
	u8data = src_data->data;
	while (i < src_data->n)
	{
		if (!(i % RSA_DUMP_BYTES))
		{
			if (i)
				ft_fprintf(rsa->fd, "   %s\n", buff);
			ft_fprintf(rsa->fd, "%04x -", i);
			ft_fprintf(rsa->fd, " %02x", u8data[i]);
		}
		else if (i % RSA_BYTES)
			ft_fprintf(rsa->fd, " %02x", u8data[i]);
		else
			ft_fprintf(rsa->fd, "-%02x", u8data[i]);
		buff[i % RSA_DUMP_BYTES] = (ft_isprint(u8data[i])) ? u8data[i] : '.';
		buff[(i++ % RSA_DUMP_BYTES) + 1] = 0;
	}
	while (i++ % RSA_DUMP_BYTES)
		ft_putstr_fd("   ", rsa->fd);
	ft_fprintf(rsa->fd, "   %s\n", buff);
}
