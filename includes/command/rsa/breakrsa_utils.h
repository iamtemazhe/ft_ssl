/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakrsa_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 03:33:44 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:28:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BREAKRSA_UTILS_H
# define BREAKRSA_UTILS_H

# include "ft_ssl.h"
# include "t_rsa.h"
# include "rsa_utils.h"

void				breakrsa_help(t_ssl *ssl, t_rsa *rsa);
t_data				*break_rsa(t_rsa *rsa);
#endif
