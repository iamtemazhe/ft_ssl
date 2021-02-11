/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 04:40:49 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 04:40:51 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hmac_utils.h"

t_data			*ft_hmac_sha512_224(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha512_224, HMAC_SHA512_224_BS, key, msg));
}

t_data			*ft_hmac_sha512_256(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha512_256, HMAC_SHA512_256_BS, key, msg));
}

t_data			*ft_hmac_sha384(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha384, HMAC_SHA384_BS, key, msg));
}

t_data			*ft_hmac_sha512(const t_data *key, const t_data *msg)
{
	return (hmac(&ft_sha512, HMAC_SHA512_BS, key, msg));
}
