/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:47:11 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/18 04:03:39 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_CONST_H
# define MD5_CONST_H

# include "libft.h"
# include "t_data.h"
# include "t_hash.h"

# define MD5_ROUND			(uint8_t)64
# define MD5_BLOCK			(uint8_t)(BIT_32 * 2)

# define T_MD5_LEN			(uint8_t)(128 / BYTE_SIZE)

#endif
