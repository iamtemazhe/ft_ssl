/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 23:08:56 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:28:03 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char			ssl_flag(t_ssl *ssl, const char *flags, char *arg)
{
	int8_t		i;
	char		c_flg;

	i = -1;
	c_flg = ft_tolower(arg[1]);
	while (flags[++i])
		if (c_flg == flags[i])
			return (c_flg);
	ssl_err(ssl, arg, INVALID_FLG);
	return (FAILURE);
}

uint32_t		ssl_options(const t_ssl_option *options,\
								size_t options_num, char *arg)
{
	size_t		i;
	uint32_t	flag;
	char		*flg_arg;

	i = -1;
	flg_arg = arg + 1;
	while (++i < options_num)
		if (!ft_strcmpi(options[i].alias, flg_arg) ||\
			!ft_strcmpi(options[i].name, flg_arg))
		{
			flag = SHIFTL(1, options[i].bit);
			if (options[i].has_val)
				flag |= SSL_FLG_HAS_VAL;
			return (flag);
		}
	return (0);
}
