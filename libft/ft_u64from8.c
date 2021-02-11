/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64from8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:49:37 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 12:36:46 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_u64pad8(const uint8_t *src, size_t n, uint8_t pad)
{
	uint8_t		i;
	uint64_t	dst;

	i = 0;
	dst = 0;
	n = (n > BYTE_64) ? BYTE_64 : n;
	while (i < n)
		dst = SHIFTL(dst, BYTE_SIZE) | src[i++];
	while (i++ < BYTE_64)
		dst = SHIFTL(dst, BYTE_SIZE) | pad;
	return (dst);
}

uint64_t		ft_u64from8(const uint8_t *src, size_t n)
{
	return (ft_u64pad8(src, n, 0));
}

uint64_t		ft_ufrom8(const uint8_t *src, size_t n)
{
	uint8_t		i;
	uint64_t	dst;

	i = 0;
	dst = 0;
	n = (n > BYTE_64) ? BYTE_64 : n;
	while (i < n)
		dst = SHIFTL(dst, BYTE_SIZE) | src[i++];
	return (dst);
}
