/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8from_any.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:49:37 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 04:10:17 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_u8nfrom_any(uint8_t *dst, size_t n, size_t src, uint8_t size)
{
	int8_t		i;
	uint8_t		len;

	i = -1;
	len = (n > size) ? size : n;
	while (++i < len)
		dst[i] = (uint8_t)SHIFTR(src, i * BYTE_SIZE);
}

void			ft_u8from_any(uint8_t *dst, size_t src, uint8_t size)
{
	ft_u8nfrom_any(dst, size, src, size);
}
