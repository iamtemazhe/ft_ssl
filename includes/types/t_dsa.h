/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dsa.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:21:01 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 11:07:10 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DSA_H
# define T_DSA_H

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
		t_bool				i	: 1;
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
	t_dsa_flag				f;
}							t_dsa;
#endif
