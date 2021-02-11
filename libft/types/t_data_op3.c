/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_op3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:23:46 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/23 00:22:34 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_data.h"
#include "libft.h"

static size_t		get_data_size(const char *data_name, size_t data_size,\
									size_t current_size)
{
	if (!data_size)
		return (current_size);
	if (current_size < data_size)
		ft_printf("%w%s%s is too short. Padding with zero bytes.%s\n",\
					STDERR, WARN, data_name, DEFAULT);
	else if (current_size > data_size)
		ft_printf("%w%s%s is too long. Ignoring excess.%s\n",\
					STDERR, WARN, data_name, DEFAULT);
	return (data_size);
}

static size_t		get_hex_string_size(const char **p_string,\
										const char *data_name)
{
	size_t			i;
	const char		*string;

	string = *p_string;
	if (!(string = ft_getstrp(string)))
		return (0);
	if ((*string == '0') && (ft_tolower(*(string + 1)) == 'x'))
		string += 2;
	i = 0;
	while (string[i] && ft_ishex(string[i]))
		i++;
	*p_string = string;
	if (string[i] && !ft_iswhitespace(string[i]))
		ft_printf("%w%s%s is invalid hex value.%s\n",\
					STDERR, ERR, data_name, DEFAULT);
	else if (!i)
		ft_printf("%w%s%s is empty.%s\n", STDERR, ERR, data_name, DEFAULT);
	else
		return (i);
	return (0);
}

t_data				*get_data_from_hex_string(const char *string,\
										const char *data_name, size_t data_size)
{
	size_t			i;
	const char		*p_string;
	t_data			*new_data;

	if (!(i = get_hex_string_size(&string, data_name)))
		return (NULL);
	p_string = string + i - 1;
	data_size = get_data_size(data_name, data_size, (i + 1) / 2);
	if (!(new_data = ft_datanew(data_size)))
		return (NULL);
	i = 0;
	while ((string < p_string) && (i < new_data->n))
	{
		new_data->data[i] = SHIFTL(ft_fromhex(*(string++)), 4);
		new_data->data[i++] |= ft_fromhex(*(string++));
	}
	if (string == p_string)
		new_data->data[i] = SHIFTL(ft_fromhex(*string), 4);
	return (new_data);
}
