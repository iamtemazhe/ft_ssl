/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 01:23:06 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 12:24:30 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_CONST_H
# define SSL_CONST_H

# include <stdint.h>

# include "cipher_const.h"

# define INVALID_COM		(int8_t)-1
# define INVALID_FLG		(int8_t)-2
# define INVALID_ARG    	(int8_t)-3
# define INVALID_INT    	(int8_t)-4
# define INVALID_HASH    	(int8_t)-5
# define MISSING_VALUE		(int8_t)-6

# define SSL_FLG_HAS_VAL	(uint32_t)0x80000000

# define COMMANDS_IN_ROW	(uint8_t)4
# define USAGE				(uint8_t)0x0001
# define INFO				(uint8_t)0x0002
# define HELP				(uint8_t)0x0004

# define SSL_COMMANDS_NUM	(uint8_t)10
# define SSL_HASHES_NUM		(uint8_t)7
# define SSL_CIPHERS_ALIAS	(uint8_t)7
# define SSL_CIPHERS_NUM	(uint8_t)(CIPHERS_NUM + SSL_CIPHERS_ALIAS)

#endif
