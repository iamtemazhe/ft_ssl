/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_gendsa.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 04:25:35 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:28:59 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_GENDSA_H
# define SSL_GENDSA_H

# include "t_ssl.h"

void				ssl_gendsa(t_ssl *ssl, int ac, char **av);
#endif
