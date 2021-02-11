/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:44:29 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 05:11:03 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "libft.h"

void			ft_putdata_fd(const t_data *data, int fd, uint8_t mode)
{
	size_t		i;

	i = 0;
	if (!(data && data->data))
		ft_printf("None");
	else if (IS_FLG(mode, PRINT_HEX_UP))
		while (i < data->n)
			ft_fprintf(fd, "%02X", data->data[i++]);
	else if (IS_FLG(mode, PRINT_BINARY))
		while (i < data->n)
			ft_fprintf(fd, "%08b", data->data[i++]);
	else if (IS_FLG(mode, PRINT_DECIMAL))
		while (i < data->n)
			ft_fprintf(fd, "%u", data->data[i++]);
	else if (IS_FLG(mode, PRINT_CHAR))
		i = write(fd, data->data, data->n);
	else
		while (i < data->n)
			ft_fprintf(fd, "%02x", data->data[i++]);
	if (IS_FLG(mode, PRINT_ENDL))
		ft_putchar_fd('\n', fd);
}

void			ft_putdata(const t_data *data)
{
	ft_putdata_fd(data, STDOUT, PRINT_HEX);
}

void			ft_datadel(t_data **p_data)
{
	if (!(p_data && *p_data))
		return ;
	(*p_data)->file_name = NULL;
	ft_memdel((void **)&(*p_data)->data);
	ft_memdel((void **)p_data);
}

void			*ft_datadel_rn(t_data **p_data)
{
	if (!(p_data && *p_data))
		return (NULL);
	(*p_data)->file_name = NULL;
	ft_memdel((void **)&(*p_data)->data);
	ft_memdel((void **)p_data);
	return (NULL);
}
