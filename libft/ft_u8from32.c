/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8from32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:49:37 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 04:10:01 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_u8nfrom32(uint8_t *dst, size_t n, uint32_t src)
{
	int8_t		i;
	uint8_t		len;

	i = -1;
	len = (n > BYTE_32) ? BYTE_32 : n;
	while (++i < len)
		dst[i] = (uint8_t)SHIFTR(src, i * BYTE_SIZE);
}

void			ft_u8from32(uint8_t *dst, uint32_t src)
{
	ft_u8nfrom32(dst, BYTE_32, src);
}
