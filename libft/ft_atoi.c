/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:43:11 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 07:23:18 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *src)
{
	size_t			i;
	char			sign;
	unsigned long	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((src[i] == ' ') || (src[i] == '\t') || (src[i] == '\n') \
			|| (src[i] == '\v') || (src[i] == '\f') || (src[i] == '\r'))
		i++;
	if (src[i] == '-')
		sign = -1;
	if ((src[i] == '-') || (src[i] == '+'))
		i++;
	while ('0' <= src[i] && src[i] <= '9')
	{
		number *= 10;
		number += ((short int)src[i++] - '0');
	}
	if (number > 2147483647 && sign == 1)
		return (-1);
	if (number > 2147483648 && sign == -1)
		return (0);
	return ((int)number * sign);
}

long long			ft_latoi(const char *src)
{
	size_t			i;
	char			sign;
	t_uint128		number;

	i = 0;
	number = 0;
	sign = 1;
	while (ft_iswhitespace(src[i]))
		i++;
	if (src[i] == '-')
		sign = -1;
	if ((src[i] == '-') || (src[i] == '+'))
		i++;
	while ('0' <= src[i] && src[i] <= '9')
	{
		number *= 10;
		number += ((short int)src[i++] - '0');
	}
	if (number > MAX_INT64 && sign == 1)
		return (-1);
	if (number > MIN_INT64 && sign == -1)
		return (0);
	return ((long long)number * sign);
}
