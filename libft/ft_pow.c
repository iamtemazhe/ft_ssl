/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:43:26 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 14:27:27 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_pow(int n, int pow)
{
	int			num;
	int			i;

	if (pow < 0 || n == 0)
		return (0);
	if (pow == 0)
		return (1);
	i = 0;
	num = n;
	while (++i < pow)
		num *= n;
	return (num);
}

long long		ft_lpow(long long n, long long pow)
{
	long long	num;
	long long	i;

	i = 0;
	num = 1;
	while (++i <= pow)
		num *= n;
	return (num);
}

double			ft_fpow(double n, long long pow)
{
	double		num;

	if (pow == 0)
		return (1);
	if (n == 0)
		return (0);
	num = (pow < 0) ? 1.0 : n;
	if (pow > 0)
		while (pow--)
			num *= n;
	else
		while (pow++)
			num /= n;
	return (num);
}
