/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_rand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:35:35 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 08:48:39 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_RAND_H
# define SSL_RAND_H

# include "ft_ssl.h"

static const char		g_rand_flags[] = "dbohx";

typedef struct			s_rand
{
	const char			*output;
	uint8_t				output_mode;
	int					n;
	int					fd;
	t_data				*data;
}						t_rand;

void					ssl_rand(t_ssl *ssl, int ac, char **av);
#endif
