/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:21:06 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/29 11:21:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA2_H
# define FT_SHA2_H

# include "t_data.h"

t_data				*ft_sha224(const void *data, size_t n);
t_data				*ft_sha256(const void *data, size_t n);
t_data				*ft_sha384(const void *data, size_t n);
t_data				*ft_sha512(const void *data, size_t n);
t_data				*ft_sha512_224(const void *data, size_t n);
t_data				*ft_sha512_256(const void *data, size_t n);
#endif
