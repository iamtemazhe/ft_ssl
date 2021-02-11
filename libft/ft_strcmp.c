/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:48:26 by jwinthei          #+#    #+#             */
/*   Updated: 2020/11/22 01:33:23 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strcmp(const char *src1, const char *src2)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (1)
	{
		diff = ((unsigned char *)src1)[i] - ((unsigned char *)src2)[i];
		if (diff != 0 || src1[i] == '\0' || src2[i] == '\0')
			break ;
		i++;
	}
	return (diff);
}
