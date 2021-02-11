/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:51:08 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 03:51:47 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_hexdump_fd(int fd, const void *data, size_t n,\
									uint8_t n_bytes)
{
	size_t			i;
	uint8_t			buff[UINT8_MAX];
	const uint8_t	*u8data;

	i = -1;
	u8data = (const uint8_t *)data;
	while (++i < n)
	{
		if (!(i % n_bytes))
		{
			if (i && buff[n_bytes])
				ft_fprintf(fd, "  %s\n", buff);
			ft_fprintf(fd, "%08x:", i);
		}
		ft_fprintf(fd, " %02x", u8data[i]);
		buff[i % n_bytes] = (ft_isprint(u8data[i])) ? u8data[i] : '.';
	}
	if (i % n_bytes)
		buff[i % n_bytes] = 0;
	while (i++ % n_bytes)
		ft_putstr_fd("   ", fd);
	ft_fprintf(fd, "  %s\n", buff);
}
