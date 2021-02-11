/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hash.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:40:39 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/25 05:24:42 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HASH_H
# define T_HASH_H

# include "libft.h"

typedef struct		s_hash_param
{
	const char		*name;
	t_data			*(*hash)(const void *data, size_t n);
	uint8_t			hash_len;
}					t_hash_param;

typedef struct		s_hash_op
{
	t_data			*hash;
	uint8_t			*data;
	uint8_t			hash_len;
	size_t			len;
}					t_hash_op;
#endif
