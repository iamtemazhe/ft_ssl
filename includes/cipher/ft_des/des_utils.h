/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:23:20 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/23 09:18:20 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_UTILS_H
# define DES_UTILS_H

# include "ft_base64.h"
# include "ft_ssl.h"
# include "t_cipher.h"

# define DES_BLOCK			BIT_64
# define DES_WORD			BYTE_64
# define DES_ROUND			(uint8_t)16
# define DES_KEY_NUM_MAX	(uint8_t)3
# define DES_RK_NUM			DES_ROUND
# define DES_IKP_SIZE		(uint8_t)((BIT_64 - BYTE_SIZE) / 2)
# define DES_KEY_LEN		(uint8_t)(DES_BLOCK / BYTE_SIZE)
# define DES_EP_SIZE		(uint8_t)(BIT_64 - DES_ROUND)
# define DES_RKP_SIZE		DES_EP_SIZE
# define DES_B_SIZE			(uint8_t)6
# define DES_S_SIZE			BYTE_SIZE
# define DES_X_SIZE			(uint8_t)4
# define DES_Y_SIZE			(uint8_t)(BIT_64 / DES_X_SIZE)
# define DES_SP_SIZE		BIT_32

# define PERM(w, c, i)		SHIFTL((SHIFTR((w), (c)) & 0x1), ((i) - 1))
# define DPAD(n)			(DES_WORD - ((n) % DES_WORD))
# define DLEN(npd, n, pd)	((npd) ? (((n) / BYTE_64) * BYTE_64) : ((n) + (pd)))

static const uint8_t	g_des_ip[DES_BLOCK] = {
	58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
};

static const uint8_t	g_des_fp[DES_BLOCK] = {
	40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
};

static const uint8_t	g_des_ep[DES_EP_SIZE] = {
	32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11,
	12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21,
	22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1
};

static const uint8_t	g_des_sp[DES_SP_SIZE] = {
	16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
	2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25
};

static const uint8_t	g_des_ikp_c[DES_IKP_SIZE] = {
	57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
};

static const uint8_t	g_des_ikp_d[DES_IKP_SIZE] = {
	63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4,
};

static const uint8_t	g_des_rkp[DES_RKP_SIZE] = {
	14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4,
	26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40,
	51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

static const uint8_t	g_des_cd_shift[DES_ROUND] = {
	1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

static const uint8_t	g_des_s[DES_S_SIZE][DES_X_SIZE][DES_Y_SIZE] = {
	{
		{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
		{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
		{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
		{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
	},
	{
		{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
		{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
		{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
		{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
	},
	{
		{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
		{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
		{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
		{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
	},
	{
		{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
		{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
		{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
		{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
	},
	{
		{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
		{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
		{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
		{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
	},
	{
		{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
		{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
		{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
		{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
	},
	{
		{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
		{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
		{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
		{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
	},
	{
		{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
		{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
		{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
		{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
	}
};

typedef struct			s_des
{
	uint8_t				pad;
	uint8_t				key_num;
	uint64_t			v64block;
	uint64_t			rounds_keys[DES_KEY_NUM_MAX][DES_RK_NUM];
	uint64_t			*round_keys;
	uint64_t			*round2_keys;
	uint64_t			*round3_keys;
	uint64_t			(*des_cipher)(uint64_t u64block, uint64_t *round_keys);
	uint64_t			(*des3_cipher)(uint64_t u64block, uint64_t *round_keys);
	t_data				*cipher;
}						t_des;

typedef union			u_des_block
{
	uint64_t			val;
	struct
	{
		uint32_t		r	: 32;
		uint32_t		l	: 32;
	}					v;
}						t_des_block;

typedef union			u_des_b6block
{
	uint8_t				val;
	struct
	{
		uint8_t			tmp	: 2;
		uint8_t			x0	: 1;
		uint8_t			y	: 4;
		uint8_t			x1	: 1;
	}					v;
}						t_des_b6block;

void					get_des_cipher(t_des *des, t_bool decrypt_mode);

t_data					*des_init(t_des *des, t_cipdata *cipdata, size_t n,\
												t_bool decrypt_mode);
t_data					*des_decrypt_validation(t_des *des, t_cipdata *cipdata,\
												t_bool decrypt_mode);

uint64_t				initial_permutation(uint64_t u64block);
uint64_t				final_permutation(uint64_t u64block);
uint64_t				expansion_permutation(uint32_t u32block);
uint32_t				substitution_permutation(uint64_t u48block);
uint64_t				round_key_permutation(uint64_t u64block);
uint64_t				permutation(const uint8_t *table, uint8_t table_size,\
									uint64_t block, uint8_t block_size);
#endif
