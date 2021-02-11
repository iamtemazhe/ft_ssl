/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:36:18 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 14:37:59 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64_utils.h"

void			base64_print(t_data *cip, int fd, t_bool decode_mode)
{
	size_t		i;

	i = 0;
	if (decode_mode)
		i = write(fd, cip->data, cip->n);
	else
	{
		while (i + BASE64_NUM < cip->n)
			i += write(fd, cip->data + i, BASE64_NUM) +\
					write(fd, "\n", 1) - 1;
		i += write(fd, cip->data + i, cip->n - i);
		i += write(fd, "\n", 1);
	}
}

void			base64_it(t_data *msg, int fd, t_bool decode_mode)
{
	t_data		*cip;

	if (!msg)
		return ;
	if ((cip = ft_base64(msg->data, msg->n, decode_mode)))
		base64_print(cip, fd, decode_mode);
	ft_datadel(&msg);
	ft_datadel(&cip);
}

t_data			*ft_base64(const void *data, size_t n, t_bool is_decode)
{
	return ((is_decode) ? base64_decode(data, n) : base64_encode(data, n));
}
