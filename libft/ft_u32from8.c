/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u32from8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:49:37 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 16:26:19 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t		ft_u32pad8(const uint8_t *src, uint8_t n, uint8_t pad)
{
	uint8_t		i;
	uint32_t	dst;

	i = 0;
	dst = 0;
	n = (n > BYTE_32) ? BYTE_32 : n;
	while (i < n)
		dst = SHIFTL(dst, BYTE_SIZE) | src[i++];
	while (i++ < BYTE_32)
		dst = SHIFTL(dst, BYTE_SIZE) | pad;
	return (dst);
}

uint32_t		ft_u32from8(const uint8_t *src, uint8_t n)
{
	return (ft_u32pad8(src, n, 0));
}
