/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hmac.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 04:57:56 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 05:24:52 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HMAC_H
# define T_HMAC_H

# include "libft.h"

typedef struct	s_hmac_param
{
	const char	*name;
	t_data		*(*hmac)(const t_data *key, const t_data *msg);
	uint8_t		block_size;
	uint8_t		hmac_len;
}				t_hmac_param;
#endif
