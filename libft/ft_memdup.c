/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:18:36 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/26 02:24:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memdup(const void *src, size_t n)
{
	void	*data;

	if (!src)
		return (NULL);
	if (!(data = malloc(n)))
		return (NULL);
	while (n--)
		((unsigned char *)data)[n] = ((unsigned char *)src)[n];
	return (data);
}
