/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_hexdump.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:12:54 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 10:12:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_HEXDUMP_H
# define SSL_HEXDUMP_H

# include "ft_ssl.h"

static const char		g_hexdump_flags[] = "hio";

typedef struct			s_hexdump
{
	const char			*input;
	const char			*output;
	uint8_t				output_mode;
	int					n;
	int					fd;
	t_data				*data;
}						t_hexdump;

void					ssl_hexdump(t_ssl *ssl, int ac, char **av);
#endif
