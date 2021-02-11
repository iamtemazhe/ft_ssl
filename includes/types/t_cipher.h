/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cipher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:44:19 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/05 14:00:18 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CIPHER_H
# define T_CIPHER_H

# include "libft.h"
# include "t_hash.h"
# include "t_hmac.h"

typedef struct s_cipher_param	t_cipher_param;
typedef struct					s_cipdata
{
	const char					*name;
	uint32_t					iter;
	t_data						*password;
	t_data						*key;
	t_data						*salt;
	t_data						*ivector;
	t_data						*pbkdf2_s;
	t_data						*pbkdf2_u;
	const t_cipher_param		*params;
	const t_hash_param			*hash_params;
	const t_hmac_param			*hmac_params;
	union
	{
		uint32_t				val;
		struct
		{
			t_bool				nopad	: 1;
			t_bool				salted	: 1;
			t_bool				pbkdf2	: 1;
			t_bool				quiet	: 1;
		}						is;
	}							mode;
}								t_cipdata;

struct							s_cipher_param
{
	const char					*name;
	t_data						*(*cipher)(const void *data, size_t n,\
									t_cipdata *cipdata, t_bool decrypt_mode);
	t_bool						is_pad;
	size_t						key_len;
	size_t						ivector_len;
};

typedef struct					s_cipher
{
	const char					*input;
	const char					*output;
	int							fd;
	t_cipdata					cipdata;
	union
	{
		uint32_t				lag;
		struct
		{
			t_bool				a	: 1;
			t_bool				d	: 1;
			t_bool				w	: 1;
		}						lg;
	}							f;
}								t_cipher;
#endif
