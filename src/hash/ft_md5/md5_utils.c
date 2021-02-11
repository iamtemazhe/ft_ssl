/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:32:56 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/06 17:12:07 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5_utils.h"

static t_md5_point	md5_logic(uint32_t b, uint32_t c, uint32_t d, int8_t i)
{
	if (i < 16)
		return (t_md5_point){.f = (b & c) | ((~b) & d), .g = i};
	if (i < 32)
		return (t_md5_point){.f = (d & b) | ((~d) & c), .g = (5 * i + 1) % 16};
	if (i < 48)
		return (t_md5_point){.f = b ^ c ^ d, .g = (3 * i + 5) % 16};
	return (t_md5_point){.f = c ^ (b | (~d)), .g = (7 * i) % 16};
}

static void			md5_circle(t_md5 *md5)
{
	int8_t			i;
	t_md5_point		point;

	i = -1;
	while (++i < MD5_ROUND)
	{
		point = md5_logic(md5->b, md5->c, md5->d, i);
		point.f += md5->a + md5->k[i] + md5->p[point.g];
		md5->a = md5->d;
		md5->d = md5->c;
		md5->c = md5->b;
		md5->b += ROTL32(point.f, md5->s[i]);
	}
}

void				md5_hash(t_md5 *md5)
{
	size_t			offset;

	offset = 0;
	while (offset < md5->op.len)
	{
		md5->p = (uint32_t *)(md5->op.data + offset);
		md5->a = md5->h_[0];
		md5->b = md5->h_[1];
		md5->c = md5->h_[2];
		md5->d = md5->h_[3];
		md5_circle(md5);
		md5->h_[0] += md5->a;
		md5->h_[1] += md5->b;
		md5->h_[2] += md5->c;
		md5->h_[3] += md5->d;
		offset += MD5_BLOCK;
	}
}
