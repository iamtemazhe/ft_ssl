/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_prime.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:35:35 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 08:48:46 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_PRIME_H
# define SSL_PRIME_H

# include "ft_ssl.h"

# define PRIME_RSA_K	(uint8_t)17

static const char		g_prime_flags[] = "koh";

typedef struct			s_prime
{
	const char			*output;
	long long			n;
	uint32_t			k;
	int					fd;
}						t_prime;

void					ssl_prime(t_ssl *ssl, int ac, char **av);
#endif
