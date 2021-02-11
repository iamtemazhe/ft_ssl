/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:38:47 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 11:19:49 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_bitlen(const void *data, size_t n)
{
	size_t		i;
	size_t		j;
	uint8_t		*u8data;

	if (!(data && n))
		return (0);
	i = 0;
	u8data = (uint8_t *)data;
	while (i < n)
	{
		j = BYTE_SIZE;
		while (j--)
			if (SHIFTR(u8data[i], j))
				break ;
		i++;
	}
	return ((i - 1) * BYTE_SIZE + j + 1);
}
