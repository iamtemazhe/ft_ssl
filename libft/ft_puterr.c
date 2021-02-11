/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:58:42 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/06 17:14:37 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterr(int retv, const char *s)
{
	if (!s)
		return (retv);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (retv);
}
