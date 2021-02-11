/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_params.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 04:25:58 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 11:29:15 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSA_PARAMS_H
# define DSA_PARAMS_H

# include "t_ssl.h"
# include "t_dsa.h"
# include "dsa_const.h"

static const t_data			g_dsa_key_sline = {
	.file_name = "private key",
	.data = (uint8_t *)_DSA_KEY_SLINE,
	.n = _DSA_KEY_SLEN
};

static const t_data			g_dsa_key_eline = {
	.file_name = "private key",
	.data = (uint8_t *)_DSA_KEY_ELINE,
	.n = _DSA_KEY_ELEN
};
#endif
