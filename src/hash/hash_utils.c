/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 02:22:07 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/24 02:22:08 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include "hash_params.h"

const t_hash_param	*get_hash_params(const char *hash_name)
{
	int16_t			i;

	i = -1;
	while (++i < HASHES_NUM)
		if (!ft_strcmpi(hash_name, g_hash_params[i].name))
			return (&g_hash_params[i]);
	return (NULL);
}
