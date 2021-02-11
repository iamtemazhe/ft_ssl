/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_options.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:19:17 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:23:30 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSA_OPTIONS_H
# define RSA_OPTIONS_H

# include "t_ssl.h"
# include "rsa_const.h"

# define RSA_FLG_NUM		(uint8_t)13

static const t_ssl_option	g_rsa_options[RSA_FLG_NUM] = {
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
	},
	{
		.name = "pubin",
		.alias = "bi",
		.bit = 7,
		.has_val = FALSE
	},
	{
		.name = "pubout",
		.alias = "bo",
		.bit = 8,
		.has_val = FALSE
	},
	{
		.name = "inform",
		.alias = "fi",
		.bit = 9,
		.has_val = TRUE
	},
	{
		.name = "outform",
		.alias = "fo",
		.bit = 10,
		.has_val = TRUE
	},
	{
		.name = "passin",
		.alias = "pi",
		.bit = 11,
		.has_val = TRUE
	},
	{
		.name = "passout",
		.alias = "po",
		.bit = 12,
		.has_val = TRUE
	}
};
#endif
