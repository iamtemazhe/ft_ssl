/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha2_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:21:14 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/29 11:21:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2_utils_64.h"

t_data				*ft_sha384(const void *data, size_t n)
{
	t_sha2_64		sha2;

	sha2 = (t_sha2_64){.c_h = g_sha384_h, .op.hash_len = T_SHA384_LEN};
	return (sha2_64(&sha2, data, n));
}

t_data				*ft_sha512(const void *data, size_t n)
{
	t_sha2_64		sha2;

	sha2 = (t_sha2_64){.c_h = g_sha512_h, .op.hash_len = T_SHA512_LEN};
	return (sha2_64(&sha2, data, n));
}

t_data				*ft_sha512_224(const void *data, size_t n)
{
	t_sha2_64		sha2;

	sha2 = (t_sha2_64){.c_h = g_sha512_224_h, .op.hash_len = T_SHA512_224_LEN};
	return (sha2_64(&sha2, data, n));
}

t_data				*ft_sha512_256(const void *data, size_t n)
{
	t_sha2_64		sha2;

	sha2 = (t_sha2_64){.c_h = g_sha512_256_h, .op.hash_len = T_SHA512_256_LEN};
	return (sha2_64(&sha2, data, n));
}
