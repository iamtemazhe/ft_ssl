/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_op4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:44:29 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/03 14:17:31 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "libft.h"

t_data			*ft_datadup(const t_data *src_data)
{
	t_data		*new_data;

	if (!src_data)
		return (NULL);
	if (!(new_data = ft_datanew(src_data->n)))
		return (NULL);
	ft_memcpy(new_data->data, src_data->data, src_data->n);
	return (new_data);
}

t_data			*ft_datandup(const t_data *src_data, size_t n)
{
	t_data		*new_data;

	if (!src_data)
		return (NULL);
	if (!(new_data = ft_datanew(n)))
		return (NULL);
	ft_memcpy(new_data->data, src_data->data, src_data->n);
	return (new_data);
}

t_data			*ft_datamemdup(const void *data, size_t n)
{
	t_data		*new_data;

	if (!n)
		return (NULL);
	if (!(new_data = ft_datanew(n)))
		return (NULL);
	if (data)
		ft_memcpy(new_data->data, data, n);
	return (new_data);
}

t_data			*ft_datastrdup(const char *text)
{
	t_data		*new_data;

	if (!text)
		return (NULL);
	if (!(new_data = ft_datanew(ft_strlen((char *)text))))
		return (NULL);
	ft_memcpy(new_data->data, text, new_data->n);
	return (new_data);
}

t_data			*ft_datastrreplace(char **p_text)
{
	t_data		*new_data;

	if (!(p_text && *p_text))
		return (NULL);
	if ((new_data = ft_datanew(ft_strlen((char *)*p_text))))
		ft_memcpy(new_data->data, *p_text, new_data->n);
	ft_strdel(p_text);
	return (new_data);
}
