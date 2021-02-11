/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:47:11 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/06 19:55:55 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_UTILS_H
# define MD5_UTILS_H

# include <math.h>

# include "md5_const.h"

static const uint32_t		g_md5_h[T_MD5_LEN] = {
	0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
};

static const uint32_t		g_md5_s[16] = {
	7, 12, 17, 22,
	5, 9, 14, 20,
	4, 11, 16, 23,
	6, 10, 15, 21
};

typedef struct				s_md5_point
{
	uint32_t				f;
	uint32_t				g;
}							t_md5_point;

typedef struct				s_md5
{
	t_hash_op				op;
	uint32_t				h_[T_MD5_LEN];
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	uint32_t				*p;
	uint32_t				k[MD5_ROUND];
	uint32_t				s[MD5_ROUND];
}							t_md5;

void						md5_hash(t_md5 *md5);
#endif
