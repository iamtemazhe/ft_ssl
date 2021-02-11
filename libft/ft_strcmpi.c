/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:37:55 by jwinthei          #+#    #+#             */
/*   Updated: 2020/11/22 01:37:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmpi(const char *src1, const char *src2)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (1)
	{
		diff = ft_tolower(((unsigned char *)src1)[i]) -\
				ft_tolower(((unsigned char *)src2)[i]);
		if (diff != 0 || src1[i] == '\0' || src2[i] == '\0')
			break ;
		i++;
	}
	return (diff);
}
