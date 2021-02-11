/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ssl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:23:40 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/01 23:52:44 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SSL_H
# define T_SSL_H

# include <stdint.h>

# include "t_data.h"
# include "t_cipher.h"

typedef struct s_command	t_command;
typedef struct s_ssl		t_ssl;

typedef struct				s_ssl_option
{
	const char				*name;
	const char				*alias;
	uint8_t					bit;
	t_bool					has_val;
}							t_ssl_option;

struct						s_command
{
	const char				*name;
	const char				*out;
	void					(*run)(t_ssl *ssl, int ac, char **av);
	t_data					*(*hash)(const void *data, size_t n);
	t_data					*(*cipher)(const void *data, size_t n,\
									t_cipdata *cipdata, t_bool decrypt_mode);
};

struct						s_ssl
{
	const char				*prog_name;
	const t_command			*command;
	const t_command			*commands;
	const t_command			*hashes;
	const t_command			*ciphers;
};
#endif
