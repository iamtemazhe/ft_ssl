/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:45:21 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 01:33:06 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

long long		ft_max(long long a, long long b)
{
	return ((a > b) ? a : b);
}

long long		ft_max3(long long a, long long b, long long c)
{
	long long	d;

	d = (a > b) ? a : b;
	return ((d > c) ? d : c);
}

size_t			ft_umax(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

size_t			ft_umax3(size_t a, size_t b, size_t c)
{
	size_t	d;

	d = (a > b) ? a : b;
	return ((d > c) ? d : c);
}
