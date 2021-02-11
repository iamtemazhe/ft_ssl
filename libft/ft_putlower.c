/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:44:43 by jwinthei          #+#    #+#             */
/*   Updated: 2020/11/21 21:11:14 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_putlower(const char *src)
{
	size_t		i;

	i = 0;
	while (src[i])
		i += ft_putchar(ft_tolower(src[i]));
	return (i);
}
