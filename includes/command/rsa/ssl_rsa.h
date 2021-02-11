/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_rsa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:31:55 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/06 06:53:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_RSA_H
# define SSL_RSA_H

# include "t_ssl.h"

void				ssl_genrsa(t_ssl *ssl, int ac, char **av);
void				ssl_rsa(t_ssl *ssl, int ac, char **av);
void				ssl_rsautl(t_ssl *ssl, int ac, char **av);
#endif
