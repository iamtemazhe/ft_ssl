/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_params.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 04:09:35 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/28 05:49:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HMAC_PARAMS_H
# define HMAC_PARAMS_H

# include "ft_hmac.h"

static const t_hmac_param		g_hmac_params[HMACS_NUM] = {
	{
		.name = "md5",
		.hmac = &ft_hmac_md5,
		.block_size = HMAC_MD5_BS,
		.hmac_len = T_MD5_LEN
	},
	{
		.name = "sha224",
		.hmac = &ft_hmac_sha224,
		.block_size = HMAC_SHA224_BS,
		.hmac_len = T_SHA224_LEN
	},
	{
		.name = "sha256",
		.hmac = &ft_hmac_sha256,
		.block_size = HMAC_SHA256_BS,
		.hmac_len = T_SHA256_LEN
	},
	{
		.name = "sha384",
		.hmac = &ft_hmac_sha384,
		.block_size = HMAC_SHA384_BS,
		.hmac_len = T_SHA384_LEN
	},
	{
		.name = "sha512",
		.hmac = &ft_hmac_sha512,
		.block_size = HMAC_SHA512_BS,
		.hmac_len = T_SHA512_LEN
	},
	{
		.name = "sha512-224",
		.hmac = &ft_hmac_sha512_224,
		.block_size = HMAC_SHA512_224_BS,
		.hmac_len = T_SHA512_224_LEN
	},
	{
		.name = "sha512-256",
		.hmac = &ft_hmac_sha512_256,
		.block_size = HMAC_SHA512_256_BS,
		.hmac_len = T_SHA512_256_LEN
	}
};
#endif
