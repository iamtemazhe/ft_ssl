/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:53:51 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 09:22:10 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putchar(int c)
{
	return (ft_putchar_fd(c, STDOUT));
}

size_t		ft_putunichar(int c)
{
	return (ft_putunichar_fd(c, STDOUT));
}
