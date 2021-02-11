/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_hashes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:16:41 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/19 01:19:58 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_HASHES_H
# define SSL_HASHES_H

# include "t_ssl.h"
# include "hash.h"
# include "ssl_const.h"

static const t_command		g_hashes[SSL_HASHES_NUM] = {
	{
		.name = "md5",
		.out = "MD5",
		.run = &hash,
		.hash = &ft_md5,
		.cipher = NULL
	},
	{
		.name = "sha224",
		.out = "SHA224",
		.run = &hash,
		.hash = &ft_sha224,
		.cipher = NULL
	},
	{
		.name = "sha256",
		.out = "SHA256",
		.run = &hash,
		.hash = &ft_sha256,
		.cipher = NULL
	},
	{
		.name = "sha384",
		.out = "SHA384",
		.run = &hash,
		.hash = &ft_sha384,
		.cipher = NULL
	},
	{
		.name = "sha512",
		.out = "SHA512",
		.run = &hash,
		.hash = &ft_sha512,
		.cipher = NULL
	},
	{
		.name = "sha512-224",
		.out = "SHA512-224",
		.run = &hash,
		.hash = &ft_sha512_224,
		.cipher = NULL
	},
	{
		.name = "sha512-256",
		.out = "SHA512-256",
		.run = &hash,
		.hash = &ft_sha512_256,
		.cipher = NULL
	}
};

#endif
