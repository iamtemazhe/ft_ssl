/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_params.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:29:48 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 03:38:00 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_PARAMS_H
# define HASH_PARAMS_H

# include "hash_const.h"
# include "t_hash.h"
# include "ft_md5.h"
# include "ft_sha2.h"

static const char				g_hash_flags[] = "hpqrs";

static const t_hash_param		g_hash_params[HASHES_NUM] = {
	{
		.name = "md5",
		.hash = &ft_md5,
		.hash_len = T_MD5_LEN
	},
	{
		.name = "sha224",
		.hash = &ft_sha224,
		.hash_len = T_SHA224_LEN
	},
	{
		.name = "sha256",
		.hash = &ft_sha256,
		.hash_len = T_SHA256_LEN
	},
	{
		.name = "sha384",
		.hash = &ft_sha384,
		.hash_len = T_SHA384_LEN
	},
	{
		.name = "sha512",
		.hash = &ft_sha512,
		.hash_len = T_SHA512_LEN
	},
	{
		.name = "sha512-224",
		.hash = &ft_sha512_224,
		.hash_len = T_SHA512_224_LEN
	},
	{
		.name = "sha512-256",
		.hash = &ft_sha512_256,
		.hash_len = T_SHA512_256_LEN
	}
};
#endif
