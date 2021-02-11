/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_gendes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:27:11 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:27:12 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_GENDES_H
# define SSL_GENDES_H

# include "ft_ssl.h"

static const char		g_gendes_flags[] = "fkmnohpsv";

void					ssl_gendes(t_ssl *ssl, int ac, char **av);
#endif
