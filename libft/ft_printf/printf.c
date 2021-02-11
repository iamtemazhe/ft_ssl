/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:44:33 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 08:52:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int				ft_vprintf(int fd, const char *restrict format,\
									va_list ap)
{
	t_pf		*pf;
	int			count;

	if (!(format && (pf = (t_pf *)malloc(sizeof(t_pf)))))
		exit(-1);
	pf->str = NULL;
	pf->count = 0;
	pf->fildes = fd;
	print_str(format, ap, pf);
	count = pf->count;
	free(pf);
	return (count);
}

int				ft_fprintf(int fd, const char *restrict format, ...)
{
	int			prnt;
	va_list		ap;

	va_start(ap, format);
	prnt = ft_vprintf(fd, format, ap);
	va_end(ap);
	return (prnt);
}

int				ft_tprintf(int fd, const char *terminal_command,\
							const char *restrict format, ...)
{
	int			prnt;
	va_list		ap;

	va_start(ap, format);
	if (fd == STDERR || fd == STDOUT)
	{
		prnt = write(fd, terminal_command, ft_strlen(terminal_command));
		prnt += ft_vprintf(fd, format, ap);
		prnt += write(fd, DEFAULT, ft_strlen(DEFAULT));
	}
	else
		prnt = ft_vprintf(fd, format, ap);
	va_end(ap);
	return (prnt);
}
