/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsautl_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:19:17 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 04:23:52 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSAUTL_OPTIONS_H
# define RSAUTL_OPTIONS_H

# include "t_ssl.h"
# include "rsa_const.h"

# define RSAUTL_FLG_NUM		(uint8_t)10

static const t_ssl_option	g_rsautl_options[RSAUTL_FLG_NUM] = {
	{
		.name = "help",
		.alias = "h",
		.bit = 1,
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
		.name = "inkey",
		.alias = "ki",
		.bit = 13,
		.has_val = TRUE
	},
	{
		.name = "encrypt",
		.alias = "e",
		.bit = 15,
		.has_val = FALSE
	},
	{
		.name = "decrypt",
		.alias = "d",
		.bit = 16,
		.has_val = FALSE
	},
	{
		.name = "hexdump",
		.alias = "x",
		.bit = 17,
		.has_val = FALSE
	}
};
#endif
