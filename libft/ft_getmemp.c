/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmemp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:39:43 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 12:46:50 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void			*ft_getmemp(const void *data, size_t n)
{
	size_t			i;
	const uint8_t	*u8data;

	if (!(data && n))
		return (data);
	i = 0;
	u8data = (const uint8_t *)data;
	while (i < n && ft_iswhitespace(u8data[i]))
		i++;
	return (u8data + i);
}

const void			*ft_getcmemp(const void *data, size_t n, uint8_t c)
{
	size_t			i;
	const uint8_t	*u8data;

	if (!(data && n))
		return (data);
	i = 0;
	u8data = (const uint8_t *)data;
	while (i < n && u8data[i] != c)
		i++;
	return (u8data + i);
}

const void			*ft_getcmpmemp(const void *data, size_t n,\
									const void *cmp, size_t cmp_n)
{
	size_t			i;
	const uint8_t	*u8data;

	if (!(data && cmp && n && cmp_n && n >= cmp_n))
		return (NULL);
	i = 0;
	u8data = (const uint8_t *)data;
	while (i < (n - cmp_n))
	{
		if (!ft_memcmp(u8data + i, cmp, cmp_n))
			return (u8data + i);
		i++;
	}
	return (NULL);
}

const void			*ft_getrcmpmemp(const void *data, size_t n,\
									const void *cmp, size_t cmp_n)
{
	size_t			i;
	const uint8_t	*u8data;

	if (!(data && cmp && n && cmp_n && n >= cmp_n))
		return (NULL);
	i = n - cmp_n + 1;
	u8data = (const uint8_t *)data;
	while (i--)
		if (!ft_memcmp(u8data + i, cmp, cmp_n))
			return (u8data + i);
	return (NULL);
}
