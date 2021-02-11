/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 04:48:06 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:33:29 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSA_UTILS_H
# define DSA_UTILS_H

# include "t_dsa.h"
# include "dsa_const.h"
# include "hash.h"

void				dsa_init(t_dsa *dsa);
void				dsa_out(t_dsa *dsa, int prnt);
void				dsa_print(t_dsa *dsa);
void				gendsa_help(t_ssl *ssl, t_dsa *dsa);
void				get_dsa64prime(t_dsa *dsa, uint64_t *num,\
									t_bool is_second, uint64_t max_val);
void				construct_dsa_key(t_dsa *dsa);
void				get_dsa_key(t_dsa *dsa);
void				gen_dsa(t_dsa *dsa);
#endif
