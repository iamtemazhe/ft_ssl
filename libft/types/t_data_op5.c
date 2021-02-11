/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_op5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:42:27 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 01:10:44 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "libft.h"

t_data			*ft_datajoin(const t_data *data1, const t_data *data2)
{
	t_data		*new_data;

	if (!(data1 && data2))
		return (NULL);
	if (!data2)
		return (ft_datadup(data1));
	if (!data1)
		return (ft_datadup(data2));
	if (!(new_data = ft_datamemdup(data1->data, data1->n + data2->n)))
		return (NULL);
	ft_memcpy(new_data->data + data1->n, data2->data, data2->n);
	return (new_data);
}

t_data			*ft_datareplace(t_data **dst_data, t_data **src_data)
{
	ft_datadel(dst_data);
	if (src_data)
	{
		*dst_data = *src_data;
		*src_data = NULL;
	}
	return (*dst_data);
}

t_data			*ft_datafreplace(t_data **dst_data, t_data *src_data)
{
	ft_datadel(dst_data);
	*dst_data = src_data;
	return (*dst_data);
}
