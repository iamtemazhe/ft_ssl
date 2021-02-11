/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:43:19 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/24 02:50:02 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_UTILS_H
# define HASH_UTILS_H

# include "ft_ssl.h"
# include "hash_const.h"

# define FLG_S		(uint8_t)0x0001
# define FLG_P		(uint8_t)0x0002
# define FLG_IN		(uint8_t)0x0004

typedef union		u_hash_f
{
	uint8_t			lag;
	struct
	{
		t_bool		q	: 1;
		t_bool		r	: 1;
		t_bool		s	: 1;
	}				lg;
}					t_hash_f;
#endif
