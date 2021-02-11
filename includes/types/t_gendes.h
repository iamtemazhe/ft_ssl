/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gendes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:58:59 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 10:59:23 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GENDES_H
# define T_GENDES_H

# include "libft.h"
# include "t_ssl.h"
# include "t_hash.h"

typedef union				u_dsa_flag
{
	uint32_t				lag;
	struct
	{
		t_bool				h	: 1;
		t_bool				n	: 1;
		t_bool				m	: 1;
		t_bool				t	: 1;
		t_bool				o	: 1;
	}						lg;
}							t_dsa_flag;

typedef struct				s_dsa
{
	const char				*input;
	const char				*output;
	int						fd;
	uint16_t				bits;
	uint64_t				p;
	uint64_t				q;
	uint64_t				g;
	uint64_t				x;
	uint64_t				y;
	t_data					*key;
	t_data					*pkey;
	t_dsa_flag				f;
	const t_hash_param		*hash_params;
}							t_dsa;
#endif
