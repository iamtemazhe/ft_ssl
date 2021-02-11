/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_const.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:29:48 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/27 02:43:25 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIPHER_CONST_H
# define CIPHER_CONST_H

# define CIPHER_SALT_LEN		BYTE_64
# define CIPHER_MAGIC_LEN		(uint8_t)(CIPHER_SALT_LEN * 2)
# define CIPHER_ITER_COUNT		(uint32_t)10000

# define CIPHER_PBKDF2_S		(uint8_t)(CIPHER_SALT_LEN + BYTE_32)
# define CIPHER_DEFAULT_HASH	"sha256"

# define CIPHERS_NUM			(uint8_t)8

#endif
