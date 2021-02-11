/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:23:46 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 05:09:50 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "libft.h"

static t_data		*data_err(t_data *data, const char *file_name, uint8_t *buf)
{
	if (file_name)
		ft_errno(file_name);
	else if (!data)
		ft_printf("%w%s[Data] Malloc error.%s\n", STDERR, ERR, DEFAULT);
	else
		ft_printf("%w%s[Data] Data malloc error.%s\n", STDERR, ERR, DEFAULT);
	ft_memdel((void **)&buf);
	ft_datadel(&data);
	return (NULL);
}

t_data				*ft_datanew(size_t n)
{
	t_data			*new_data;

	if (!(new_data = (t_data *)malloc(sizeof(t_data))))
		return (data_err(new_data, NULL, NULL));
	if (!(new_data->data = (uint8_t *)ft_memalloc(n)))
		return (data_err(new_data, NULL, NULL));
	new_data->file_name = NULL;
	new_data->n = n;
	return (new_data);
}

t_data				*get_data_from_fd(const char *file_name)
{
	int				fd;
	int64_t			rd;
	int64_t			file_size;
	uint8_t			*buf;
	t_data			*data;

	if (!(data = ft_datanew(0)))
		return (NULL);
	if ((fd = ft_fileopen(file_name, O_RDONLY)) < 0)
		return (data_err(data, file_name, NULL));
	file_size = (fd) ? ft_filesize(fd) : BUF_SIZE;
	if (!(buf = (uint8_t *)malloc(file_size)))
		return (data_err(data, NULL, buf));
	while ((rd = read(fd, buf, file_size)))
	{
		if (rd < 0)
			return (data_err(data, file_name, buf));
		if (!(data->data = (uint8_t *)ft_realloc(data->data, data->n, buf, rd)))
			return (data_err(data, NULL, buf));
		data->n += rd;
	}
	fd = (fd) ? close(fd) : fd;
	data->file_name = file_name;
	ft_memdel((void **)&buf);
	return (data);
}

t_data				*get_data_from_text(const char *text)
{
	t_data			*new_data;

	if (!text)
		return (NULL);
	if (!(new_data = ft_datanew(ft_strlen((char *)text))))
		return (NULL);
	ft_memcpy(new_data->data, text, new_data->n);
	return (new_data);
}
