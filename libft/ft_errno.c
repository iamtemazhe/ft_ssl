/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:49:15 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 04:49:41 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_errno(const char *file_name)
{
	int		errno_code;

	if ((errno_code = errno) == EACCES)
		ft_printf("%w%s%s: Permission denied%s\n",\
					STDERR, ERR, file_name, DEFAULT);
	else if (errno_code == ENOENT)
		ft_printf("%w%s%s: No such file or directory%s\n",\
					STDERR, ERR, file_name, DEFAULT);
	else if (errno_code == EISDIR)
		ft_printf("%w%s%s: Is a directory%s\n",\
					STDERR, ERR, file_name, DEFAULT);
	else if (errno_code == ETXTBSY)
		ft_printf("%w%s%s: File is busy%s\n",\
					STDERR, ERR, file_name, DEFAULT);
	else if (errno_code == ENOEXEC)
		ft_printf("%w%s%s: File format error%s\n",\
					STDERR, ERR, file_name, DEFAULT);
	else if (errno_code)
		ft_printf("%w%s%s: File error %d%s\n",\
					STDERR, ERR, file_name, errno_code, DEFAULT);
	return (errno_code);
}
