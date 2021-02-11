/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:22:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:40:49 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENRSA_UTILS_H
# define GENRSA_UTILS_H

# include "ft_ssl.h"
# include "base64_utils.h"
# include "rsa_const.h"
# include "t_rsa.h"

t_bool				get_rsa32prime_n(t_rsa *rsa, uint64_t *num,\
										t_bool is_second);
void				get_rsa32prime(t_rsa *rsa, uint64_t *num, t_bool is_second);
void				construct_rsa_key(t_rsa *rsa);
void				construct_rsa_pkey(t_rsa *rsa);
void				genrsa_help(t_ssl *ssl, t_rsa *rsa);
void				gen_rsa(t_rsa *rsa);
#endif
