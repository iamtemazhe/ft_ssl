/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:08:22 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 07:22:26 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_sqrt(int n)
{
	int			i;
	int			nbr;

	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	i = 2;
	nbr = n;
	while (nbr--)
	{
		if ((n % i == 0) && (n / i == i))
			return (i);
		i++;
	}
	return (0);
}

uint64_t		ft_lsqrt(uint64_t n)
{
	uint64_t	tmp;
	uint64_t	sqr;
	uint64_t	base;
	uint64_t	shift;

	sqr = 0;
	base = MIN_INT32;
	shift = BIT_32 - 1;
	while (base)
	{
		if (n >= (tmp = (((sqr << 1) + base) << shift--)))
		{
			sqr += base;
			n -= tmp;
		}
		base >>= 1;
	}
	return (sqr);
}
