/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:25:00 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 00:45:26 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *dst, size_t nd, const void *src, size_t ns)
{
	void	*tmp;

	if (!ns)
		return (dst);
	if (!dst)
		return ((!src) ? ft_memalloc(ns) : ft_memdup(src, ns));
	tmp = ft_memjoin(dst, nd, src, ns);
	free(dst);
	return (tmp);
}

void		*ft_rrealloc(void *dst, size_t nd, const void *src, size_t ns)
{
	void	*tmp;

	if (!ns)
		return (dst);
	if (!dst)
		return ((!src) ? ft_memalloc(ns) : ft_memdup(src, ns));
	tmp = ft_memjoin(src, ns, dst, nd);
	free(dst);
	return (tmp);
}
