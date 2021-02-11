/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:21:32 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 07:31:16 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_modpow(uint64_t n, uint64_t pow, uint64_t mod)
{
	uint64_t	num;

	num = 1;
	n %= mod;
	while (pow)
	{
		if (pow & 1)
			num = ft_modmult(num, n, mod);
		n = ft_modmult(n, n, mod);
		pow >>= 1;
	}
	return (num);
}

t_uint128		ft_modpow128(t_uint128 n, t_uint128 pow, t_uint128 mod)
{
	t_uint128	num;

	num = 1;
	n %= mod;
	while (pow)
	{
		if (pow & 1)
			num = ft_modmult128(num, n, mod);
		n = ft_modmult128(n, n, mod);
		pow >>= 1;
	}
	return (num);
}
