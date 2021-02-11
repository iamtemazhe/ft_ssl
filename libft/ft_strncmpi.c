/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmpi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:38:17 by jwinthei          #+#    #+#             */
/*   Updated: 2020/11/22 01:38:18 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmpi(const char *src1, const char *src2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = ft_tolower(((unsigned char *)src1)[i]) -\
				ft_tolower(((unsigned char *)src2)[i]);
		if (diff != 0 || src1[i] == '\0' || src2[i] == '\0')
			break ;
		i++;
	}
	return (diff);
}
