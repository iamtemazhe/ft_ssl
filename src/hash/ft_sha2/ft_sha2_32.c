/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha2_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:21:14 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/29 11:21:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2_utils_32.h"

t_data				*ft_sha224(const void *data, size_t n)
{
	t_sha2_32		sha2;

	sha2 = (t_sha2_32){.c_h = g_sha224_h, .op.hash_len = T_SHA224_LEN};
	return (sha2_32(&sha2, data, n));
}

t_data				*ft_sha256(const void *data, size_t n)
{
	t_sha2_32		sha2;

	sha2 = (t_sha2_32){.c_h = g_sha256_h, .op.hash_len = T_SHA256_LEN};
	return (sha2_32(&sha2, data, n));
}
