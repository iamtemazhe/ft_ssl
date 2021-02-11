/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:08:36 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/12 21:27:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIPHER_H
# define CIPHER_H

# include "t_ssl.h"
# include "ft_base64.h"
# include "ft_des.h"

void				cipher(t_ssl *ssl, int ac, char **av);
#endif
