/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modmult_inv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 07:45:41 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 01:36:26 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t			ft_modmult_inv(uint64_t a, uint64_t mod)
{
	uint64_t		b;
	uint64_t		q;
	uint64_t		t;
	uint64_t		x;
	uint64_t		y;

	b = mod;
	x = 1;
	y = 0;
	while (a)
	{
		t = a;
		q = b / t;
		a = b - (q * t);
		b = t;
		t = x;
		x = y - (q * t);
		y = t;
	}
	return (((int64_t)y < 0) ? (y + mod) : y);
}

static uint64_t		gcd_extend(uint64_t a, uint64_t b, uint64_t *x, uint64_t *y)
{
	uint64_t		x1;
	uint64_t		y1;
	uint64_t		gcd;

	if (!a)
	{
		*x = 0;
		*y = 1;
		return (b);
	}
	gcd = gcd_extend(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return (gcd);
}

uint64_t			ft_modmult_inv_rec(uint64_t a, uint64_t mod)
{
	uint64_t		x;
	uint64_t		y;

	return (((int64_t)gcd_extend(a, mod, &x, &y) < 0) ? x : (x + mod));
}
