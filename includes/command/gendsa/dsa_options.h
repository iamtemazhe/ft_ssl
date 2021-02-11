/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_options.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 04:26:58 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 11:08:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSA_OPTIONS_H
# define DSA_OPTIONS_H

# include "t_ssl.h"
# include "dsa_const.h"

# define DSA_FLG_NUM		(uint8_t)7

static const t_ssl_option	g_dsa_options[DSA_FLG_NUM] = {
	{
		.name = "help",
		.alias = "h",
		.bit = 0,
		.has_val = FALSE
	},
	{
		.name = "noout",
		.alias = "n",
		.bit = 1,
		.has_val = FALSE
	},
	{
		.name = "modulus",
		.alias = "m",
		.bit = 2,
		.has_val = FALSE
	},
	{
		.name = "text",
		.alias = "t",
		.bit = 3,
		.has_val = FALSE
	},
	{
		.name = "in",
		.alias = "i",
		.bit = 4,
		.has_val = TRUE
	},
	{
		.name = "out",
		.alias = "o",
		.bit = 5,
		.has_val = TRUE
	}
};
#endif
