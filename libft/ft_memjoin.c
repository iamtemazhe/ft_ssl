/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:22:15 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 07:23:00 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin(const void *p1, size_t n1, const void *p2, size_t n2)
{
	void	*data;

	if ((!n1 && !n2) || n1 + n2 > MIN_INT64)
		return (NULL);
	if (!(data = ft_memalloc(n1 + n2)))
		return (NULL);
	if (p1 && n1)
		ft_memcpy(data, p1, n1);
	if (p2 && n2)
		ft_memcpy((unsigned char *)data + ((p1 && n1) ? n1 : 0), p2, n2);
	return (data);
}
