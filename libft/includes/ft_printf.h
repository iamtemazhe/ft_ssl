/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:14:40 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 08:51:53 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "printf_const.h"

int					ft_printf(const char *restrict format, ...);
int					ft_vprintf(int fd, const char *restrict format,\
								va_list ap);
int					ft_fprintf(int fd, const char *restrict format, ...);
int					ft_tprintf(int fd, const char *terminal_command,\
								const char *restrict format, ...);
#endif
