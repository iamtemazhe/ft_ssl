/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:40:39 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 01:06:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

# include <stdint.h>
# include <stdio.h>

# define PRINT_HEX		(uint8_t)0x00
# define PRINT_HEX_UP	(uint8_t)0x01
# define PRINT_BINARY	(uint8_t)0x02
# define PRINT_DECIMAL	(uint8_t)0x04
# define PRINT_CHAR		(uint8_t)0x08
# define PRINT_ENDL		(uint8_t)0x80

# define BASE_BINARY	(uint8_t)2
# define BASE_DECIMAL	(uint8_t)10
# define BASE_HEX		(uint8_t)16

typedef struct			s_data
{
	const char			*file_name;
	uint8_t				*data;
	size_t				n;
}						t_data;

void					ft_putdata(const t_data *data);
void					ft_putdata_fd(const t_data *data, int fd, uint8_t mode);
void					ft_datadel(t_data **p_data);
void					*ft_datadel_rn(t_data **p_data);

t_data					*ft_datanew(size_t n);
t_data					*ft_datadup(const t_data *src_data);
t_data					*ft_datandup(const t_data *src_data, size_t n);
t_data					*ft_datamemdup(const void *data, size_t n);
t_data					*ft_datastrdup(const char *text);
t_data					*ft_datastrreplace(char **p_text);
t_data					*ft_datajoin(const t_data *data1, const t_data *data2);
t_data					*ft_datareplace(t_data **dst_data, t_data **src_data);
t_data					*ft_datafreplace(t_data **dst_data, t_data *src_data);
t_data					*ft_datarealloc(t_data *dst_data,\
										const t_data *src_data);
t_data					*ft_datarrealloc(t_data *dst_data,\
										const t_data *src_data);
t_data					*ft_datamemrealloc(t_data *dst_data,\
											const void *data, size_t n);
t_data					*ft_datamemrrealloc(t_data *dst_data,\
											const void *data, size_t n);

t_data					*get_data_from_text(const char *text);
t_data					*get_data_from_hex_string(const char *string,\
									const char *data_name, size_t data_size);
t_data					*get_data_from_fd(const char *file_name);
#endif
