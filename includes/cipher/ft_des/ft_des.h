/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:23:27 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/23 07:57:42 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
# define FT_DES_H

# include "t_data.h"
# include "t_cipher.h"

t_data		*ft_des(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des_ecb(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des_cbc(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des_cfb(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des_ofb(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);

t_data		*ft_des3(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des3_ecb(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des3_cbc(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des3_cfb(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
t_data		*ft_des3_ofb(const void *data, size_t n, t_cipdata *cipdata,\
						t_bool decrypt_mode);
#endif
