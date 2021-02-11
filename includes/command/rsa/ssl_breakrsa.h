/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_breakrsa.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:35:35 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:24:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_BREAKRSA_H
# define SSL_BREAKRSA_H

# include "ft_ssl.h"
# include "t_rsa.h"

void					ssl_breakrsa(t_ssl *ssl, int ac, char **av);
#endif
