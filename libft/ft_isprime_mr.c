/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime_mr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:15:15 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:55:46 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	miller_rabin(uint64_t n, uint32_t k,\
								uint32_t s, uint64_t t)
{
	uint64_t	r;
	uint64_t	a;
	uint64_t	x;

	while (k--)
	{
		if (!(a = ft_rand(2, n - 2)))
			return (FALSE);
		if ((x = ft_modpow(a, t, n)) == 1 || x == (n - 1))
			continue ;
		r = 0;
		while (++r < s)
			if ((x = ft_modpow(x, 2, n)) == 1)
				return (FALSE);
			else if (x == (n - 1))
				break ;
		if (x != (n - 1))
			return (FALSE);
	}
	return (TRUE);
}

t_bool			ft_isprime_mr(uint64_t n, uint32_t k)
{
	uint32_t	s;
	uint64_t	t;

	if (n == 2 || n == 3)
		return (TRUE);
	if (n < 3 || !(n % 2))
		return (FALSE);
	s = 0;
	t = n - 1;
	while (t && (t % 2) == 0)
	{
		t /= 2;
		s += 1;
	}
	return (miller_rabin(n, k, s, t));
}

static t_bool	miller_rabin128(t_uint128 n, uint32_t k,\
									uint64_t s, t_uint128 t)
{
	t_uint128	r;
	t_uint128	a;
	t_uint128	x;

	while (k--)
	{
		if (!(a = ft_rand128(2, n - 2)))
			return (FALSE);
		if ((x = ft_modpow128(a, t, n)) == 1 || x == (n - 1))
			continue ;
		r = 0;
		while (++r < s)
			if ((x = ft_modpow128(x, 2, n)) == 1)
				return (FALSE);
			else if (x == (n - 1))
				break ;
		if (x != (n - 1))
			return (FALSE);
	}
	return (TRUE);
}

t_bool			ft_isprime_mr128(t_uint128 n, uint32_t k)
{
	uint64_t	s;
	t_uint128	t;

	if (n == 2 || n == 3)
		return (TRUE);
	if (n < 3 || !(n % 2))
		return (FALSE);
	s = 0;
	t = n - 1;
	while (t && (t % 2) == 0)
	{
		t /= 2;
		s += 1;
	}
	return (miller_rabin128(n, k, s, t));
}
