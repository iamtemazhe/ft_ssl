/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileexist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 03:49:55 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/28 03:49:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool				ft_fileexist(const char *file_name)
{
	int				fd;
	struct stat		st;

	fd = 0;
	stat(file_name, &st);
	if (S_ISREG(st.st_mode))
		fd = open(file_name, O_RDONLY);
	if (S_ISDIR(st.st_mode))
		errno = EISDIR;
	if (fd <= 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}
