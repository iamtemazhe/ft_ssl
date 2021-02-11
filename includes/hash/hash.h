/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:34:34 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/24 02:23:40 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "t_ssl.h"
# include "t_hash.h"
# include "ft_md5.h"
# include "ft_sha2.h"

void				hash(t_ssl *ssl, int ac, char **av);
const t_hash_param	*get_hash_params(const char *hash_name);
#endif
