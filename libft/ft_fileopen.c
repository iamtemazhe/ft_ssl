/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileopen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:49:15 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 05:10:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_fileopen(const char *file_name, int oflag)
{
	int				mode;
	struct stat		st;

	if (!file_name)
		return (STDIN);
	stat(file_name, &st);
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	if (IS_FLG(oflag, O_CREAT))
		return (open(file_name, oflag | O_WRONLY | O_TRUNC, mode));
	if (S_ISREG(st.st_mode))
		return (open(file_name, oflag));
	if (S_ISDIR(st.st_mode))
		errno = EISDIR;
	return (-errno);
}
