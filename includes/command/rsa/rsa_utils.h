/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:44:19 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:23:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSA_UTILS_H
# define RSA_UTILS_H

# include "t_rsa.h"
# include "rsa_const.h"
# include "genrsa_utils.h"
# include "rsautl_utils.h"
# include "cipher_utils.h"

void				rsa_init(t_ssl *ssl, t_rsa *rsa);
void				rsa_out(t_rsa *rsa, int prnt);
void				rsa_print(t_rsa *rsa);
void				rsa_help(t_ssl *ssl, t_rsa *rsa);
void				rsa_pem_encode(t_rsa *rsa, const t_data *key,\
								const t_data *sline, const t_data *eline);
void				rsa_pem_decode(t_rsa *rsa, t_data **p_key, t_data *key);
void				check_rsa_key(t_rsa *rsa);
void				get_rsa_key(t_rsa *rsa);
void				get_rsa_pkey(t_rsa *rsa);

void				ssl_genrsa(t_ssl *ssl, int ac, char **av);
void				ssl_rsa(t_ssl *ssl, int ac, char **av);
#endif
