/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:34:34 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/18 04:30:37 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include "libft.h"

t_data				*base64_encode(const void *data, size_t n);
t_data				*base64_decode(const void *data, size_t n);
t_data				*ft_base64(const void *data, size_t n, t_bool is_decode);
#endif
