/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_commands.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:36:13 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:53:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_COMMANDS_H
# define SSL_COMMANDS_H

# include "ft_ssl.h"
# include "ft_des.h"
# include "ssl_breakrsa.h"
# include "ssl_hexdump.h"
# include "ssl_gendsa.h"
# include "ssl_gendes.h"
# include "ssl_prime.h"
# include "ssl_rand.h"
# include "ssl_rsa.h"

static const t_command		g_commands[SSL_COMMANDS_NUM] = {
	{
		.name = "help",
		.out = "HELP",
		.run = &ssl_help,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "hexdump",
		.out = "DUMP",
		.run = &ssl_hexdump,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "rand",
		.out = "RAND",
		.run = &ssl_rand,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "prime",
		.out = "PRIME",
		.run = &ssl_prime,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "genrsa",
		.out = "RSA",
		.run = &ssl_genrsa,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "rsa",
		.out = "RSA",
		.run = &ssl_rsa,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "rsautl",
		.out = "RSA",
		.run = &ssl_rsautl,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "breakrsa",
		.out = "RSA",
		.run = &ssl_breakrsa,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "gendsa",
		.out = "DSA",
		.run = &ssl_gendsa,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "gendes",
		.out = "DES",
		.run = &ssl_gendes,
		.hash = NULL,
		.cipher = &ft_des_cbc
	}
};
#endif
