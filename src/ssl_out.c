/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:32:13 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 12:24:45 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void					ssl_err(t_ssl *ssl, const char *arg, int8_t err_code)
{
	if (err_code == INVALID_COM)
	{
		ft_printf("%w%s%s: Error: '%s' is an invalid command.%s\n",\
					STDERR, ERR, ssl->prog_name, arg, DEFAULT);
		ssl_info(ssl, INFO, FAILURE);
	}
	if (err_code == INVALID_FLG)
		ft_printf("%w%s%s: Unrecognized flag '%s'.%s\n",\
					STDERR, ERR, ssl->command->name, arg, DEFAULT);
	else if (err_code == MISSING_VALUE)
		ft_printf("%w%s%s: Option '-%s' needs a value.%s\n",\
					STDERR, ERR, ssl->command->name, arg, DEFAULT);
	else if (err_code == INVALID_ARG)
		ft_printf("%w%s%s: Invalid argument '%s' given.%s\n",\
					STDERR, ERR, ssl->command->name, arg, DEFAULT);
	else if (err_code == INVALID_INT)
		ft_printf("%w%s%s: Invalid positive integer number '%s' given.%s\n",\
					STDERR, ERR, ssl->command->name, arg, DEFAULT);
	else if (err_code == INVALID_HASH)
		ft_printf("%w%s%s: Invalid hash '%s' given.%s\n",\
					STDERR, ERR, ssl->command->name, arg, DEFAULT);
	ssl_out(ssl, ft_printf("%w%s%s: Use -h for summary.%s\n",\
							STDERR, ERR, ssl->command->name, DEFAULT));
}

static void				print_command_list(const t_command *commands, size_t n,\
										const char *list_name)
{
	uint8_t				i;

	i = 0;
	ft_fprintf(STDERR, "\n%s%s commands:", GRAY, list_name);
	while (i < n)
	{
		if (!(i % COMMANDS_IN_ROW))
			ft_putchar_fd('\n', STDERR);
		ft_printf("%- 20s", commands[i++].name);
	}
	ft_putendl_fd(DEFAULT, STDERR);
}

static inline void		info(t_ssl *ssl)
{
	print_command_list(ssl->commands, SSL_COMMANDS_NUM, "Standart");
	print_command_list(ssl->hashes, SSL_HASHES_NUM, "Message Digest");
	print_command_list(ssl->ciphers, SSL_CIPHERS_NUM, "Cipher");
	ft_putchar_fd('\n', STDERR);
}

void					ssl_info(t_ssl *ssl, uint8_t flg, int exit_code)
{
	if (IS_FLG(flg, USAGE))
		ft_tprintf(STDERR, GRAY,\
		"usage: %s command [command opts] [command args]\n", ssl->prog_name);
	if (IS_FLG(flg, HELP))
		info(ssl);
	if (IS_FLG(flg, INFO))
		info(ssl);
	ssl_out(ssl, exit_code);
}

void					ssl_help(t_ssl *ssl, int ac, char **av)
{
	if (!ac || !av)
		return ;
	ssl_info(ssl, USAGE | INFO, SUCCESS);
}
