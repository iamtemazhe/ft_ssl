/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakrsa_options.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 03:15:30 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 14:05:42 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BREAKRSA_OPTIONS_H
# define BREAKRSA_OPTIONS_H

# include "t_ssl.h"
# include "rsa_const.h"

# define BREAKRSA_FLG_NUM	(uint8_t)10

static const t_ssl_option	g_breakrsa_options[BREAKRSA_FLG_NUM] = {
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
	},
	{
		.name = "inform",
		.alias = "fi",
		.bit = 9,
		.has_val = TRUE
	},
	{
		.name = "passin",
		.alias = "pi",
		.bit = 11,
		.has_val = TRUE
	},
	{
		.name = "keyout",
		.alias = "ko",
		.bit = 14,
		.has_val = TRUE
	},
	{
		.name = "show",
		.alias = "s",
		.bit = 18,
		.has_val = FALSE
	}
};
#endif
