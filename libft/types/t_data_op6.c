/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_op6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:42:27 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 01:29:41 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "libft.h"

t_data			*ft_datarealloc(t_data *dst_data, const t_data *src_data)
{
	if (!src_data)
		return (dst_data);
	if (!dst_data)
		return (ft_datadup(src_data));
	dst_data->data = ft_realloc(dst_data->data, dst_data->n,\
								src_data->data, src_data->n);
	dst_data->n += src_data->n;
	if (!dst_data->data)
		ft_datadel(&dst_data);
	return (dst_data);
}

t_data			*ft_datarrealloc(t_data *dst_data, const t_data *src_data)
{
	if (!src_data)
		return (dst_data);
	if (!dst_data)
		return (ft_datadup(src_data));
	dst_data->data = ft_rrealloc(dst_data->data, dst_data->n,\
								src_data->data, src_data->n);
	dst_data->n += src_data->n;
	if (!dst_data->data)
		ft_datadel(&dst_data);
	return (dst_data);
}

t_data			*ft_datamemrealloc(t_data *dst_data,\
									const void *data, size_t n)
{
	if (!n)
		return (dst_data);
	if (!dst_data)
		return (ft_datamemdup(data, n));
	dst_data->data = ft_realloc(dst_data->data, dst_data->n, data, n);
	dst_data->n += n;
	if (!dst_data->data)
		ft_datadel(&dst_data);
	return (dst_data);
}

t_data			*ft_datamemrrealloc(t_data *dst_data,\
									const void *data, size_t n)
{
	if (!n)
		return (dst_data);
	if (!dst_data)
		return (ft_datamemdup(data, n));
	dst_data->data = ft_rrealloc(dst_data->data, dst_data->n, data, n);
	dst_data->n += n;
	if (!dst_data->data)
		ft_datadel(&dst_data);
	return (dst_data);
}
