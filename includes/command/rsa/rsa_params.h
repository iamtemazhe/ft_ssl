/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_params.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:19:17 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:23:37 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSA_PARAMS_H
# define RSA_PARAMS_H

# include "t_ssl.h"
# include "t_rsa.h"
# include "rsa_const.h"

static const t_data			g_rsa_key_sline = {
	.file_name = "private key",
	.data = (uint8_t *)_RSA_KEY_SLINE,
	.n = _RSA_KEY_SLEN
};

static const t_data			g_rsa_key_eline = {
	.file_name = "private key",
	.data = (uint8_t *)_RSA_KEY_ELINE,
	.n = _RSA_KEY_ELEN
};

static const t_data			g_rsa_pkey_sline = {
	.file_name = "public key",
	.data = (uint8_t *)_RSA_PKEY_SLINE,
	.n = _RSA_PKEY_SLEN
};

static const t_data			g_rsa_pkey_eline = {
	.file_name = "public key",
	.data = (uint8_t *)_RSA_PKEY_ELINE,
	.n = _RSA_PKEY_ELEN
};

static const uint8_t		g_rsa_pkey_sequence_data[_RSA_PKEY_SEQ_LEN] = {
	ASN_TAG_SEQUENCE, 0x0d, _ASN_PKEY_ID, _ASN_PKEY_BSTR_LEN,
	0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01,
	_ASN_PKEY_NULL_ID, 0x00
};

static const t_data			g_rsa_pkey_sequence = {
	.file_name = "public key sequence tag",
	.data = (uint8_t *)g_rsa_pkey_sequence_data,
	.n = _RSA_PKEY_SEQ_LEN
};

static const t_data			g_rsa_ptype = {
	.file_name = "process type",
	.data = _RSA_PROC_TYPE,
	.n = _RSA_PROC_TYPE_LEN
};
#endif
