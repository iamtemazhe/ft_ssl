/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:50:27 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/04 16:42:45 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

void	ft_wcsdel(wchar_t **aw)
{
	if (!(aw && *aw))
		return ;
	free(*aw);
	*aw = NULL;
}
