/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:21:32 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 07:27:02 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data			*ft_randn(size_t n)
{
	int			fd;
	t_data		*data;

	if (!n)
		return (NULL);
	if ((fd = open(RAND_DIR, O_RDONLY)) < 0)
	{
		ft_errno(RAND_DIR);
		return (NULL);
	}
	if (!(data = ft_datanew(n)))
		return (NULL);
	if (read(fd, data->data, data->n) < 0)
	{
		ft_errno(RAND_DIR);
		ft_datadel(&data);
	}
	close(fd);
	return (data);
}

uint64_t		ft_rand(uint64_t lower, uint64_t upper)
{
	int			fd;
	uint64_t	num;

	if ((!lower && !upper) || upper < lower)
		return (0);
	if ((fd = open(RAND_DIR, O_RDONLY)) < 0)
	{
		ft_errno(RAND_DIR);
		return (0);
	}
	num = 0;
	if (read(fd, &num, BYTE_64) < 0)
		ft_errno(RAND_DIR);
	else
		num = num % (upper - lower + 1) + lower;
	close(fd);
	return (num);
}

t_uint128		ft_rand128(t_uint128 lower, t_uint128 upper)
{
	int			fd;
	t_uint128	num;

	if ((!lower && !upper) || upper < lower)
		return (0);
	if ((fd = open(RAND_DIR, O_RDONLY)) < 0)
	{
		ft_errno(RAND_DIR);
		return (0);
	}
	num = 0;
	if (read(fd, &num, BYTE_128) < 0)
		ft_errno(RAND_DIR);
	else
		num = num % (upper - lower + 1) + lower;
	close(fd);
	return (num);
}

uint64_t		ft_rand_prime(uint64_t lower, uint64_t upper,\
								uint8_t bits, uint32_t k)
{
	int			fd;
	int			rd;
	uint64_t	num;

	if ((!lower && !upper) || upper < lower || !(bits && k) || bits > BIT_64)
		return (0);
	if ((fd = open(RAND_DIR, O_RDONLY)) < 0 && ft_errno(RAND_DIR))
		return (0);
	num = 0;
	while ((rd = read(fd, &num, bits / BYTE_SIZE)) > 0)
	{
		num = num % (upper - lower + 1) + lower;
		num |= SHIFTL((uint64_t)1, bits - 1) | 1;
		if (ft_isprime_mr(num, k))
			break ;
	}
	close(fd);
	if (rd < 0 && ft_errno(RAND_DIR))
		return (0);
	return (num);
}

void			*ft_rand_fill(void *dst, size_t n,\
								uint8_t lower, uint8_t upper)
{
	int			fd;
	int			rd;
	size_t		i;
	uint8_t		*u8dst;

	if (!(dst && n))
		return (dst);
	i = 0;
	u8dst = (uint8_t *)dst;
	if ((fd = open(RAND_DIR, O_RDONLY)) > 0)
		while ((rd = read(fd, &u8dst[i], 1)) > 0)
		{
			u8dst[i] = u8dst[i] % (upper - lower + 1) + lower;
			if (++i == n)
				break ;
		}
	if (fd <= 0 || close(fd) < 0 || rd < 0)
		ft_errno(RAND_DIR);
	else
		return (dst);
	return (NULL);
}
