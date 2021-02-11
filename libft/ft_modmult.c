/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 07:45:41 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 07:31:10 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_modmult(uint64_t a, uint64_t b, uint64_t mod)
{
	uint64_t	num;

	num = 0;
	if (b >= mod)
		b = (mod > UINT64_MAX / 2U) ? (b - mod) : (b % mod);
	while (a)
	{
		if (a & 1)
			num = (b >= mod - num) ? (num - mod + b) : (num + b);
		a >>= 1;
		b = (b >= mod - b) ? (b - mod + b) : (b + b);
	}
	return (num);
}

t_uint128		ft_modmult128(t_uint128 a, t_uint128 b, t_uint128 mod)
{
	t_uint128	num;

	num = 0;
	if (b >= mod)
		b = (mod > UINT64_MAX / 2U) ? (b - mod) : (b % mod);
	while (a)
	{
		if (a & 1)
			num = (b >= mod - num) ? (num - mod + b) : (num + b);
		a >>= 1;
		b = (b >= mod - b) ? (b - mod + b) : (b + b);
	}
	return (num);
}
