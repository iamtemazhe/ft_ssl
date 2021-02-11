/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:44:19 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 13:13:25 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSA_CONST_H
# define RSA_CONST_H

# include "ft_ssl.h"
# include "base64_utils.h"

# define RSA_NAME			"RSA-64"
# define RSA_BITS			BIT_64
# define RSA_BYTES			(uint8_t)(RSA_BITS / BYTE_SIZE)
# define RSA_PRIMES			(uint8_t)2
# define RSA_PRIME_BITS		(uint8_t)(RSA_BITS / 2)
# define RSA_PRIME_BYTES	(uint8_t)(RSA_PRIME_BITS / BYTE_SIZE)
# define RSA_PRIME_K		(uint8_t)5
# define RSA_PRIME_MAX_K	(uint8_t)(RSA_PRIME_K * 5)
# define RSA_PRIME_MIN		(uint8_t)17
# define RSA_DEFAULT_E		(uint32_t)0x10001

# define _RSA_KEY_SLINE		"-----BEGIN RSA PRIVATE KEY-----"
# define _RSA_KEY_ELINE		"-----END RSA PRIVATE KEY-----"
# define _RSA_KEY_SLEN		(uint8_t)31
# define _RSA_KEY_ELEN		(uint8_t)29
# define _RSA_PKEY_SLINE	"-----BEGIN PUBLIC KEY-----"
# define _RSA_PKEY_ELINE	"-----END PUBLIC KEY-----"
# define _RSA_PKEY_SLEN		(uint8_t)26
# define _RSA_PKEY_ELEN		(uint8_t)24
# define _RSA_PKEY_SEQ_LEN	(uint8_t)15
# define _RSA_PROC_TYPE		"Proc-Type: 4,ENCRYPTED\nDEK-Info: "
# define _RSA_PROC_TYPE_LEN	(uint8_t)33

# define RSA_PKSC_SLEN		(uint8_t)2
# define RSA_PKSC_ELEN		(uint8_t)1
# define RSA_PKSC_LEN		(uint8_t)(RSA_PKSC_SLEN + RSA_PKSC_ELEN)
# define RSA_PKSC1T2		(uint8_t)0x2

# define RSA_KEY_FORMAT_PEM	"PEM"
# define RSA_KEY_FORMAT_DER	"DER"
# define RSA_KEY_MIN_LEN	(uint8_t)29
# define RSA_PKEY_MIN_LEN	(uint8_t)(13 + _RSA_PKEY_SEQ_LEN)

# define RSA_HASH_DEFAULT	"md5"
# define RSA_PTYPE_MIN_LEN	(uint8_t)(_RSA_PROC_TYPE_LEN + CIPHER_SALT_LEN + 4)
# define RSA_DUMP_BYTES		(uint8_t)16

# define _ASN_PKEY_ID    	(uint8_t)0x06
# define _ASN_PKEY_BSTR_LEN	(uint8_t)0x09
# define _ASN_PKEY_NULL_ID	(uint8_t)0x05

# define ASN_TAG_SEQUENCE	(uint8_t)0x30
# define ASN_TAG_INT		(uint8_t)0x02
# define ASN_TAG_LONG_LEN	(uint8_t)0x80
# define ASN_RSA_VERSION	(uint8_t)0x0
# define ASN_TAG_SEQUENCE_P	(uint8_t)0x03

#endif
