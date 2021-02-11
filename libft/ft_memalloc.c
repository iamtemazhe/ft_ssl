/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:51:05 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 09:16:58 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*dst;

	if (!(dst = malloc(size)))
		return (NULL);
	while (size--)
		((unsigned char*)dst)[size] = 0;
	return (dst);
}
