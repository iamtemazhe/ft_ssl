/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:32:39 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/19 01:32:25 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ssl_commands.h"
#include "ssl_hashes.h"
#include "ssl_ciphers.h"

static void				ssl_init(t_ssl *ssl)
{
	ssl->commands = g_commands;
	ssl->hashes = g_hashes;
	ssl->ciphers = g_ciphers;
	ssl->command = NULL;
	ssl->prog_name = NULL;
}

void					ssl_out(t_ssl *ssl, int prnt)
{
	ssl->command = NULL;
	ssl->commands = NULL;
	ssl->hashes = NULL;
	ssl->ciphers = NULL;
	ssl->prog_name = NULL;
	exit((prnt) ? FAILURE : SUCCESS);
}

static const t_command	*command_finder(t_ssl *ssl, const char *command_name)
{
	int16_t				i;

	i = -1;
	while (++i < SSL_COMMANDS_NUM)
		if (!ft_strcmpi(command_name, ssl->commands[i].name))
			return (&ssl->commands[i]);
	i = -1;
	while (++i < SSL_HASHES_NUM)
		if (!ft_strcmpi(command_name, ssl->hashes[i].name))
			return (&ssl->hashes[i]);
	i = -1;
	while (++i < SSL_CIPHERS_NUM)
		if (!ft_strcmpi(command_name, ssl->ciphers[i].name))
			return (&ssl->ciphers[i]);
	return (NULL);
}

static void				command_validation(t_ssl *ssl, int ac, char **av)
{
	ssl->prog_name = (av[0][0] == '.') ? &av[0][2] : av[0];
	if (ac < 2)
		ssl_info(ssl, USAGE, SUCCESS);
	if ((ssl->command = command_finder(ssl, av[1])))
		return ;
	ssl_err(ssl, av[1], INVALID_COM);
}

int						main(int ac, char **av)
{
	t_ssl				ssl;

	ssl_init(&ssl);
	command_validation(&ssl, ac, av);
	ssl.command->run(&ssl, ac, av);
	return (SUCCESS);
}
