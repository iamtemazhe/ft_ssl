/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_utils_32.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:52:20 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/04 18:32:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2_utils_32.h"

static void		sha2_circle(t_sha2_32 *sha2)
{
	int8_t		i;
	uint32_t	t0;
	uint32_t	t1;

	i = -1;
	while (++i < SHA2_ROUND_32)
	{
		t0 = MAJ_32(sha2->a, sha2->b, sha2->c) + SUM0_32(sha2->a);
		t1 = CH_32(sha2->e, sha2->f, sha2->g) + SUM1_32(sha2->e);
		t1 += sha2->h + sha2->c_k[i] + sha2->words[i];
		sha2->h = sha2->g;
		sha2->g = sha2->f;
		sha2->f = sha2->e;
		sha2->e = sha2->d + t1;
		sha2->d = sha2->c;
		sha2->c = sha2->b;
		sha2->b = sha2->a;
		sha2->a = t0 + t1;
	}
}

static void		construct_word(t_sha2_32 *sha2, const void *data, size_t offest)
{
	int8_t		i;
	uint32_t	w;

	ft_memset(sha2->words, 0, SHA2_ROUND_32);
	i = -1;
	while (++i < 16)
	{
		ft_memcpy(sha2->words + i, data + offest + (i * BYTE_32), BYTE_32);
		sha2->words[i] = ft_swapint32(sha2->words[i]);
	}
	while (i < SHA2_ROUND_32)
	{
		w = SIGMA0_32(sha2->words[i - 15]) + SIGMA1_32(sha2->words[i - 2]);
		sha2->words[i] = sha2->words[i - 16] + sha2->words[i - 7] + w;
		i++;
	}
}

void			sha2_hash_32(t_sha2_32 *sha2)
{
	size_t		offset;

	offset = 0;
	while (offset < sha2->op.len)
	{
		construct_word(sha2, sha2->op.data, offset);
		sha2->a = sha2->h_[0];
		sha2->b = sha2->h_[1];
		sha2->c = sha2->h_[2];
		sha2->d = sha2->h_[3];
		sha2->e = sha2->h_[4];
		sha2->f = sha2->h_[5];
		sha2->g = sha2->h_[6];
		sha2->h = sha2->h_[7];
		sha2_circle(sha2);
		sha2->h_[0] += sha2->a;
		sha2->h_[1] += sha2->b;
		sha2->h_[2] += sha2->c;
		sha2->h_[3] += sha2->d;
		sha2->h_[4] += sha2->e;
		sha2->h_[5] += sha2->f;
		sha2->h_[6] += sha2->g;
		sha2->h_[7] += sha2->h;
		offset += SHA2_BLOCK_32;
	}
}
