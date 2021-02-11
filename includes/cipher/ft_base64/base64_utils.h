/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:47:11 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 14:01:15 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_UTILS_H
# define BASE64_UTILS_H

# include "ft_base64.h"
# include "ft_ssl.h"
# include "t_cipher.h"

# define BASE64_BYTES		(uint8_t)3
# define BASE64_WORDS		(uint8_t)4
# define BASE64_WORD_SIZE	(uint8_t)6
# define BASE64_WORD_LEN	(uint8_t)(BASE64_WORD_SIZE * BASE64_WORD_NUM)
# define BASE64_NUM			(uint8_t)64

# define BASE64_WORD1(x)	SHIFTR(x, 2)
# define BASE64_WORD2(x, y)	(SHIFTL(x & 0x03, 4) | SHIFTR(y, 4))
# define BASE64_WORD3(x, y)	(SHIFTL(x & 0x0f, 2) | SHIFTR(y, 6))
# define BASE64_WORD4(x)	(x & 0x3f)

static const char		g_base64_flags[] = "deio";

static const uint8_t	g_base64_h[BASE64_NUM] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
};

static const int8_t		g_unbase64_h[128] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, 0, -1, -1,
	-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, 63,
	-1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1
};

void					base64_it(t_data *msg, int fd, t_bool decode_mode);
void					base64_print(t_data *cipher, int fd,\
									t_bool decode_mode);
#endif
