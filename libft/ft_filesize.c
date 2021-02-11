/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:44:08 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/05 16:30:48 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t			ft_filesize(int fd)
{
	int64_t		file_size;

	file_size = lseek(fd, 0L, SEEK_END);
	lseek(fd, 0L, SEEK_SET);
	return (file_size);
}
