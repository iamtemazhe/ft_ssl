/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_ciphers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:36:13 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 13:40:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_CIPHERS_H
# define SSL_CIPHERS_H

# include "ft_ssl.h"
# include "cipher.h"

static const t_command		g_ciphers[SSL_CIPHERS_NUM] = {
	{
		.name = "base64",
		.out = "base64",
		.run = &cipher,
		.hash = NULL,
		.cipher = NULL
	},
	{
		.name = "des",
		.out = "des-cbc",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des_cbc
	},
	{
		.name = "des-ecb",
		.out = "des-ecb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des_ecb
	},
	{
		.name = "des-cbc",
		.out = "des-cbc",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des_cbc
	},
	{
		.name = "des-cfb",
		.out = "des-cfb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des_cfb
	},
	{
		.name = "des-ofb",
		.out = "des-ofb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des_ofb
	},
	{
		.name = "des3",
		.out = "des-ede3-cbc",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_cbc
	},
	{
		.name = "des3-ecb",
		.out = "des-ede3-ecb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_ecb
	},
	{
		.name = "des3-cbc",
		.out = "des-ede3-cbc",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_cbc
	},
	{
		.name = "des3-cfb",
		.out = "des-ede3-cfb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_cfb
	},
	{
		.name = "des3-ofb",
		.out = "des-ede3-ofb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_ofb
	},
	{
		.name = "des-ede3-ecb",
		.out = "des-ede3-ecb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_ecb
	},
	{
		.name = "des-ede3-cbc",
		.out = "des-ede3-cbc",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_cbc
	},
	{
		.name = "des-ede3-cfb",
		.out = "des-ede3-cfb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_cfb
	},
	{
		.name = "des-ede3-ofb",
		.out = "des-ede3-ofb",
		.run = &cipher,
		.hash = NULL,
		.cipher = &ft_des3_ofb
	}
};

#endif
