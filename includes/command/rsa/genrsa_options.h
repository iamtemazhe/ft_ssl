/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:19:17 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:30:19 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENRSA_OPTIONS_H
# define GENRSA_OPTIONS_H

# include "t_ssl.h"
# include "rsa_const.h"

# define GENRSA_FLG_NUM		(uint8_t)7

static const t_ssl_option	g_genrsa_options[GENRSA_FLG_NUM] = {
	{
		.name = "check",
		.alias = "c",
		.bit = 0,
		.has_val = FALSE
	},
	{
		.name = "help",
		.alias = "h",
		.bit = 1,
		.has_val = FALSE
	},
	{
		.name = "noout",
		.alias = "n",
		.bit = 2,
		.has_val = FALSE
	},
	{
		.name = "modulus",
		.alias = "m",
		.bit = 3,
		.has_val = FALSE
	},
	{
		.name = "text",
		.alias = "t",
		.bit = 4,
		.has_val = FALSE
	},
	{
		.name = "in",
		.alias = "i",
		.bit = 5,
		.has_val = TRUE
	},
	{
		.name = "out",
		.alias = "o",
		.bit = 6,
		.has_val = TRUE
	}
};
#endif
