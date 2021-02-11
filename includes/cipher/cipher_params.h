/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_params.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:29:48 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 14:01:20 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIPHER_PARAMS_H
# define CIPHER_PARAMS_H

# include "cipher_const.h"
# include "t_cipher.h"
# include "ft_base64.h"
# include "ft_des.h"

static const char				g_cipher_flags[] = "acdefikmnohpsvw";

static const t_data				g_cipher_magic = {
	.file_name = "Salt Magic Number",
	.data = (uint8_t *)"Salted__",
	.n = CIPHER_SALT_LEN
};

static const t_cipher_param		g_cipher_params[CIPHERS_NUM] = {
	{
		.name = "des-ecb",
		.cipher = &ft_des_ecb,
		.is_pad = TRUE,
		.key_len = BYTE_64,
		.ivector_len = 0
	},
	{
		.name = "des-cbc",
		.cipher = &ft_des_cbc,
		.is_pad = TRUE,
		.key_len = BYTE_64,
		.ivector_len = BYTE_64
	},
	{
		.name = "des-cfb",
		.cipher = &ft_des_cfb,
		.is_pad = FALSE,
		.key_len = BYTE_64,
		.ivector_len = BYTE_64
	},
	{
		.name = "des-ofb",
		.cipher = &ft_des_ofb,
		.is_pad = FALSE,
		.key_len = BYTE_64,
		.ivector_len = BYTE_64
	},
	{
		.name = "des-ede3-ecb",
		.cipher = &ft_des3_ecb,
		.is_pad = TRUE,
		.key_len = BYTE_64 * 3,
		.ivector_len = 0
	},
	{
		.name = "des-ede3-cbc",
		.cipher = &ft_des3_cbc,
		.is_pad = TRUE,
		.key_len = BYTE_64 * 3,
		.ivector_len = BYTE_64
	},
	{
		.name = "des-ede3-cfb",
		.cipher = &ft_des3_cfb,
		.is_pad = FALSE,
		.key_len = BYTE_64 * 3,
		.ivector_len = BYTE_64
	},
	{
		.name = "des-ede3-ofb",
		.cipher = &ft_des3_ofb,
		.is_pad = FALSE,
		.key_len = BYTE_64 * 3,
		.ivector_len = BYTE_64
	}
};
#endif
