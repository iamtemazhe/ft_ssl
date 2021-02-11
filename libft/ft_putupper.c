/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:42:37 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 09:24:50 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_putupper_fd(const char *src, int fd)
{
	size_t		i;

	i = 0;
	while (src[i])
		i += ft_putchar_fd(ft_toupper(src[i]), fd);
	return (i);
}

size_t			ft_putupper(const char *src)
{
	return (ft_putupper_fd(src, STDOUT));
}
