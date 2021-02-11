/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:19:11 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:27:06 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "t_ssl.h"
# include "ssl_const.h"

void					ssl_info(t_ssl *ssl, uint8_t flg, int exit_code);
void					ssl_err(t_ssl *ssl, const char *arg, int8_t err_code);
void					ssl_out(t_ssl *ssl, int prnt);
uint32_t				ssl_options(const t_ssl_option *options,\
									size_t options_num, char *arg);

char					ssl_flag(t_ssl *ssl, const char *flags, char *arg);

void					ssl_help(t_ssl *ssl, int ac, char **av);
#endif
