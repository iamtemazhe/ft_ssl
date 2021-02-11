/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:02 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/30 06:24:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int						ft_patoi(const char **src)
{
	short int			sign;
	unsigned long long	number;

	number = 0;
	while (*src[0] == ' ' || *src[0] == '\t' || *src[0] == '\n' ||\
			*src[0] == '\v' || *src[0] == '\f' || *src[0] == '\r')
		src[0]++;
	sign = (*src[0] == '-') ? -1 : 1;
	src[0] += (*src[0] == '-' || *src[0] == '+') ? 1 : 0;
	while ('0' <= *src[0] && *src[0] <= '9')
	{
		number *= 10;
		number += ((int)*src[0] - '0');
		if ('0' <= *(src[0] + 1) && *(src[0] + 1) <= '9')
			src[0]++;
		else
			break ;
	}
	return ((int)number * sign);
}
