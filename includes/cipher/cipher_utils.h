/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:56 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 04:30:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIPHER_UTILS_H
# define CIPHER_UTILS_H

# include "cipher_const.h"
# include "t_ssl.h"
# include "t_cipher.h"
# include "hash.h"
# include "base64_utils.h"
# include "ft_hmac.h"

void			cipdata_init(t_cipdata *cipdata);
void			cipdata_free(t_cipdata *cipdata);
void			cipher_init(t_ssl *ssl, t_cipher *cipher);
void			cipher_help(t_ssl *ssl, t_cipher *cipher);
void			cipher_out(t_cipher *cipher, int prnt);
void			cipher_it(t_cipher *cipher, t_bool decrypt_mode);

t_bool			fill_cipher_params(const t_command *ciphers,\
								const char *cipher_name, t_cipdata *cipdata);
const char		*get_cipher_name(const t_command *ciphers,\
									const char *cipher_name, char c_end);

t_data			*get_salt(t_cipdata *cipdata);
t_data			*get_key(t_cipdata *cipdata, t_bool decrypt_mode);
t_data			*get_password(t_cipdata *cipdata, t_bool decrypt_mode);
#endif
