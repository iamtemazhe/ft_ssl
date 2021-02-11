/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_utils_32.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:46:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 08:41:29 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2_UTILS_32_H
# define SHA2_UTILS_32_H

# include "sha2_const.h"

# define CH_32(x, y, z)		(((x) & (y)) ^ (~(x) & (z)))
# define MAJ_32(x, y, z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SUM0_32(x)		    (ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22))
# define SUM1_32(x)		    (ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25))
# define SIGMA0_32(x)		(ROTR32(x, 7) ^ ROTR32(x, 18) ^ SHIFTR(x, 3))
# define SIGMA1_32(x)		(ROTR32(x, 17) ^ ROTR32(x, 19) ^ SHIFTR(x, 10))

static const uint32_t		g_sha224_h[BYTE_SIZE] = {
	0xC1059ED8, 0x367CD507, 0x3070DD17, 0xF70E5939,
	0xFFC00B31, 0x68581511, 0x64F98FA7, 0xBEFA4FA4
};

static const uint32_t		g_sha256_h[BYTE_SIZE] = {
	0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
	0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
};

static const uint32_t		g_sha2_k_32[SHA2_ROUND_32] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
	0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
	0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
	0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
	0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
	0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
	0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
	0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
	0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

typedef struct				s_sha2_32
{
	t_hash_op				op;
	uint32_t				h_[BYTE_SIZE];
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	uint32_t				e;
	uint32_t				f;
	uint32_t				g;
	uint32_t				h;
	uint32_t				words[SHA2_ROUND_32];
	const uint32_t			*c_h;
	const uint32_t			*c_k;
}							t_sha2_32;

void						sha2_hash_32(t_sha2_32 *sha2);
t_data						*sha2_32(t_sha2_32 *sha2, const void *data,\
										size_t n);
#endif
