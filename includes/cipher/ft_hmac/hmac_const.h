/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_const.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:24:51 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 09:47:28 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HMAC_CONST_H
# define HMAC_CONST_H

# include "hash_const.h"

# define HMAC_HASH32_BS		(uint8_t)(BIT_32 * 2)
# define HMAC_HASH64_BS		(uint8_t)(BIT_64 * 2)
# define HMAC_MD5_BS		HMAC_HASH32_BS
# define HMAC_SHA256_BS		HMAC_HASH32_BS
# define HMAC_SHA224_BS		HMAC_HASH32_BS
# define HMAC_SHA384_BS		HMAC_HASH64_BS
# define HMAC_SHA512_224_BS	HMAC_HASH64_BS
# define HMAC_SHA512_256_BS	HMAC_HASH64_BS
# define HMAC_SHA512_BS		HMAC_HASH64_BS
# define HMAC_MAX_BS		HMAC_HASH64_BS

# define HMAC_IPAD			(uint8_t)0x36
# define HMAC_OPAD			(uint8_t)0x5c

# define HMACS_NUM			HASHES_NUM

#endif
