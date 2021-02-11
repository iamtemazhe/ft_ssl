/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_breakrsa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:04:36 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 05:27:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "breakrsa_utils.h"
#include "breakrsa_options.h"

t_data			*break_rsa(t_rsa *rsa)
{
	t_data		*msg;
	t_data		*decrypted_msg;

	msg = NULL;
	decrypted_msg = NULL;
	if (rsa->input_file && !(msg = get_data_from_fd(rsa->input_file)))
		return (NULL);
	rsa->p = UINT32_MAX;
	ft_tprintf(STDERR, OK, "Breaking RSA Public key...\n");
	while (rsa->p > 3 && (rsa->n % rsa->p))
		rsa->p -= 2;
	rsa->q = rsa->n / rsa->p;
	gen_rsa(rsa);
	if (msg && (decrypted_msg = rsa_crypt(msg->data, msg->n, rsa->n, rsa->d)))
		rsa_clear_outdata(rsa, &decrypted_msg, TRUE);
	ft_datadel(&msg);
	return (decrypted_msg);
}

static void		break_it(t_rsa *rsa)
{
	int			fd;
	t_data		*decrypted_msg;

	ft_tprintf(STDERR, OK, "Begining analysis...\n");
	get_rsa_pkey(rsa);
	ft_tprintf(STDERR, OK, "Estimated keysize is %u bits.\n", rsa->bits);
	if ((decrypted_msg = break_rsa(rsa)))
	{
		if (rsa->output_file)
		{
			if ((fd = ft_fileopen(rsa->output_file, O_CREAT)) <= 0)
				rsa_out(rsa, ft_errno(rsa->output_file));
			ft_putdata_fd(decrypted_msg, fd, PRINT_CHAR);
			close(fd);
		}
		if (rsa->f.lg.s && ft_tprintf(STDERR, OK, "Decrypted msg:\n"))
			ft_putdata_fd(decrypted_msg, STDERR, PRINT_CHAR);
		ft_datadel(&decrypted_msg);
	}
	else if (rsa->input_file)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "%s: Forbidden input data\n",\
								rsa->input_file));
	ft_tprintf(STDERR, OK, "Breaking successfully completed!\n");
	construct_rsa_key(rsa);
	rsa_print(rsa);
}

static t_bool	flg_analise_value(t_ssl *ssl, t_rsa *rsa, t_rsa_flag f,\
										const char *arg)
{
	t_bool		tmp_flg;

	tmp_flg = FALSE;
	rsa->f.lag |= f.lag ^ SSL_FLG_HAS_VAL;
	if ((arg = ft_getstrp(arg)) && !arg[0])
		return (FALSE);
	else if (f.lg.i && !ft_fileexist(rsa->input_file = arg))
		rsa_out(rsa, ft_errno(rsa->input_file));
	else if (f.lg.o)
		rsa->output_file = arg;
	else if (f.lg.ko)
		rsa->output = arg;
	else if (f.lg.fi && ft_strcmpi(RSA_KEY_FORMAT_PEM, arg) &&\
		!(tmp_flg = (!ft_strcmpi(RSA_KEY_FORMAT_DER, arg))))
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
			"%s: Invalid key format '%s' given.\n", ssl->command->name, arg));
	else if (f.lg.fi)
		rsa->is_inform_der = tmp_flg;
	else if (f.lg.pi && !(rsa->cipdata_in.password = ft_datastrdup(arg)))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "%s: Password malloc error.\n",\
								rsa->cipdata_in.name));
	return (TRUE);
}

static void		flg_analise(t_ssl *ssl, t_rsa *rsa, int ac, char **av)
{
	int			i;
	t_rsa_flag	f;

	i = 1;
	while (++i < ac && av[i][0] == '-')
		if (!(f.lag = ssl_options(ssl, g_breakrsa_options,\
									BREAKRSA_FLG_NUM, av[i])))
			ssl_err(ssl, av[i], INVALID_FLG);
		else if (f.lg.h)
			breakrsa_help(ssl, rsa);
		else if (!IS_FLG(f.lag, SSL_FLG_HAS_VAL))
			rsa->f.lag |= f.lag;
		else if (++i == ac || !flg_analise_value(ssl, rsa, f, av[i]))
			ssl_err(ssl, &av[i - 1][1], MISSING_VALUE);
	if (i == ac)
		ssl_err(ssl, av[i], 0);
	if (!ft_fileexist(rsa->input = av[i]))
		rsa_out(rsa, ft_errno(rsa->input));
	if (++i < ac)
		ssl_err(ssl, av[i], INVALID_ARG);
}

void			ssl_breakrsa(t_ssl *ssl, int ac, char **av)
{
	t_rsa		rsa;

	rsa_init(ssl, &rsa);
	rsa.quiet = TRUE;
	flg_analise(ssl, &rsa, ac, av);
	break_it(&rsa);
	rsa_out(&rsa, SUCCESS);
}
