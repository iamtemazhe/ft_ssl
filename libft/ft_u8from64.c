/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8from64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:49:37 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 04:10:28 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_u8nfrom64(uint8_t *dst, size_t n, uint64_t src)
{
	int8_t		i;
	uint8_t		len;

	i = -1;
	len = (n > BYTE_64) ? BYTE_64 : n;
	while (++i < len)
		dst[i] = (uint8_t)SHIFTR(src, i * BYTE_SIZE);
}

void			ft_u8from64(uint8_t *dst, uint64_t src)
{
	ft_u8nfrom64(dst, BYTE_64, src);
}
