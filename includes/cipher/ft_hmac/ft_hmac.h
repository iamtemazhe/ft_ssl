/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:24:51 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 05:28:53 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAC_H
# define FT_HMAC_H

# include "t_data.h"
# include "t_hmac.h"
# include "hmac_const.h"

t_data				*ft_hmac_md5(const t_data *key, const t_data *msg);
t_data				*ft_hmac_sha224(const t_data *key, const t_data *msg);
t_data				*ft_hmac_sha256(const t_data *key, const t_data *msg);
t_data				*ft_hmac_sha384(const t_data *key, const t_data *msg);
t_data				*ft_hmac_sha512_224(const t_data *key, const t_data *msg);
t_data				*ft_hmac_sha512_256(const t_data *key, const t_data *msg);
t_data				*ft_hmac_sha512(const t_data *key, const t_data *msg);
t_data				*hmac(t_data *(hash)(const void *, size_t),\
						uint8_t block_size, const t_data *key,\
						const t_data *msg);

const t_hmac_param	*get_hmac_params(const char *hash_name);
#endif
