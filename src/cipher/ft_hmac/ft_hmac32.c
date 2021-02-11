/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 04:40:57 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 05:13:54 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmac_utils.h"

t_data			*ft_hmac_md5(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_md5, HMAC_MD5_BS, key, msg));
}

t_data			*ft_hmac_sha224(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha224, HMAC_SHA224_BS, key, msg));
}

t_data			*ft_hmac_sha256(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha256, HMAC_SHA256_BS, key, msg));
}
