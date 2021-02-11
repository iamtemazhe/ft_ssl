/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_const.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:23:54 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/18 04:04:18 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2_CONST_H
# define SHA2_CONST_H

# include "libft.h"
# include "t_data.h"
# include "t_hash.h"

# define SHA2_ROUND_32		(uint8_t)64
# define SHA2_ROUND_64		(uint8_t)80
# define SHA2_BLOCK_32		(uint8_t)(BIT_32 * 2)
# define SHA2_BLOCK_64		(uint8_t)(BIT_64 * 2)

# define T_SHA224_LEN		(uint8_t)(224 / BYTE_SIZE)
# define T_SHA256_LEN		(uint8_t)(256 / BYTE_SIZE)
# define T_SHA384_LEN		(uint8_t)(384 / BYTE_SIZE)
# define T_SHA512_LEN		(uint8_t)(512 / BYTE_SIZE)
# define T_SHA512_224_LEN	(uint8_t)(224 / BYTE_SIZE)
# define T_SHA512_256_LEN	(uint8_t)(256 / BYTE_SIZE)

#endif
