/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:06:59 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 09:40:32 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putstr_fd(const char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

size_t		ft_putunistr_fd(const int *s, int fd)
{
	return (write(fd, s, ft_unistrlen(s)));
}
