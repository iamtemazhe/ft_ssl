/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 04:49:34 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 11:02:29 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSA_CONST_H
# define DSA_CONST_H

# include "ft_ssl.h"
# include "base64_utils.h"

# define DSA_NAME			"DSA-64"
# define DSA_BITS			BIT_64
# define DSA_BYTES			(uint8_t)(DSA_BITS / BYTE_SIZE)
# define DSA_PRIME_BITS		(uint8_t)(DSA_BITS / 2)
# define DSA_PRIME_BYTES	(uint8_t)(DSA_PRIME_BITS / BYTE_SIZE)
# define DSA_PRIME_K		(uint8_t)5
# define DSA_PRIME_MAX_K	(uint8_t)(DSA_PRIME_K * 5)
# define DSA_PRIME_MIN		(uint8_t)17
# define DSA_DEFAULT_H		(uint8_t)2

# define _DSA_KEY_SLINE		"-----BEGIN DSA PRIVATE KEY-----"
# define _DSA_KEY_ELINE		"-----END DSA PRIVATE KEY-----"
# define _DSA_KEY_SLEN		(uint8_t)31
# define _DSA_KEY_ELEN		(uint8_t)29
# define _DSA_PKEY_SLINE	"-----BEGIN PUBLIC KEY-----"
# define _DSA_PKEY_ELINE	"-----END PUBLIC KEY-----"
# define _DSA_PKEY_SLEN		(uint8_t)26
# define _DSA_PKEY_ELEN		(uint8_t)24
# define _DSA_PKEY_SEQ_LEN	(uint8_t)15

# define _ASN_PKEY_ID    	(uint8_t)0x06
# define _ASN_PKEY_BSTR_LEN	(uint8_t)0x09
# define _ASN_PKEY_NULL_ID	(uint8_t)0x05

# define DSA_KEY_FORMAT_PEM	"PEM"
# define DSA_KEY_FORMAT_DER	"DER"
# define DSA_KEY_MIN_LEN	(uint8_t)29
# define DSA_PKEY_MIN_LEN	(uint8_t)(13 + _DSA_PKEY_SEQ_LEN)

# define ASN_TAG_SEQUENCE	(uint8_t)0x30
# define ASN_TAG_INT		(uint8_t)0x02
# define ASN_TAG_LONG_LEN	(uint8_t)0x80
# define ASN_DSA_VERSION	(uint8_t)0x0
# define ASN_TAG_SEQUENCE_P	(uint8_t)0x03

#endif
