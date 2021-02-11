/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rsa.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:21:01 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 06:21:11 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RSA_H
# define T_RSA_H

# include "libft.h"
# include "t_ssl.h"
# include "t_cipher.h"

typedef union				u_rsa_flag
{
	uint32_t				lag;
	struct
	{
		t_bool				c	: 1;
		t_bool				h	: 1;
		t_bool				n	: 1;
		t_bool				m	: 1;
		t_bool				t	: 1;
		t_bool				i	: 1;
		t_bool				o	: 1;
		t_bool				bi	: 1;
		t_bool				bo	: 1;
		t_bool				fi	: 1;
		t_bool				fo	: 1;
		t_bool				pi	: 1;
		t_bool				po	: 1;
		t_bool				ki	: 1;
		t_bool				ko	: 1;
		t_bool				e	: 1;
		t_bool				d	: 1;
		t_bool				x	: 1;
		t_bool				s	: 1;
	}						lg;
}							t_rsa_flag;

typedef struct				s_rsa
{
	const char				*input;
	const char				*output;
	const char				*input_file;
	const char				*output_file;
	int						fd;
	t_bool					quiet;
	t_bool					is_inform_der;
	t_bool					is_outform_der;
	uint8_t					primes;
	uint16_t				bits;
	uint64_t				p;
	uint64_t				q;
	uint64_t				e;
	uint64_t				d;
	uint64_t				dp;
	uint64_t				dq;
	uint64_t				iq;
	uint64_t				n;
	t_data					*key;
	t_data					*pkey;
	t_rsa_flag				f;
	t_cipdata				cipdata_in;
	t_cipdata				cipdata_out;
	const t_command			*ciphers;
}							t_rsa;
#endif
