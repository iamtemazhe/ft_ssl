/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:20:35 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 07:19:06 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *src, int c)
{
	while (1)
	{
		if (*src == c)
			return ((char*)src);
		if (*src == '\0')
			break ;
		src++;
	}
	return (NULL);
}
