/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:04:08 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 09:20:53 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

size_t		ft_putunichar_fd(int c, int fd)
{
	if (c & 0xFF000000)
		return (write(fd, &c, 4));
	if (c & 0x00FF0000)
		return (write(fd, &c, 3));
	if (c & 0x0000FF00)
		return (write(fd, &c, 2));
	return (write(fd, &c, 1));
}
