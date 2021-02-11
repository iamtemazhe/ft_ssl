/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:24:51 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 08:51:50 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HMAC_UTILS_H
# define HMAC_UTILS_H

# include "libft.h"
# include "hmac_const.h"
# include "t_hmac.h"
# include "hash.h"

typedef struct	s_hmac
{
	uint8_t		i_key_pad[HMAC_MAX_BS];
	uint8_t		o_key_pad[HMAC_MAX_BS];
	uint8_t		block_size;
	t_data		*(*hash)(const void *data, size_t n);
}				t_hmac;

t_data			*hmac(t_data *(hash)(const void *, size_t), uint8_t block_size,
						const t_data *key, const t_data *msg);
#endif
