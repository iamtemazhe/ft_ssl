/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:54:50 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 09:34:23 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putstr(const char *s)
{
	return (ft_putstr_fd(s, STDOUT));
}

size_t		ft_putunistr(const int *s)
{
	return (ft_putunistr_fd(s, STDOUT));
}
