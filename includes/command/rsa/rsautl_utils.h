/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsautl_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:22:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:23:59 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSAUTL_UTILS_H
# define RSAUTL_UTILS_H

# include "ft_ssl.h"
# include "rsa_const.h"
# include "t_rsa.h"

void				rsautl_help(t_ssl *ssl, t_rsa *rsa);
void				rsa_hexdump(t_rsa *rsa, const t_data *src_data);
void				rsa_it(t_rsa *rsa, t_data *msg, t_bool decrypt_mode);

t_data				*rsa_chinese_decrypt(t_rsa *rsa, const t_data *msg);
t_data				*rsa_crypt(const void *data, size_t n,\
								uint64_t modulus, uint64_t exponent);
t_data				*rsa_clear_msg(t_rsa *rsa, t_data **msg,\
									t_bool decrypt_mode);
t_data				*rsa_clear_outdata(t_rsa *rsa, t_data **outdata,\
										t_bool decrypt_mode);
t_data				*rsa_decrypt(t_rsa *rsa, t_data *msg);
#endif
