/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakrsa_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 03:32:09 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 14:04:54 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "breakrsa_utils.h"

void			breakrsa_help(t_ssl *ssl, t_rsa *rsa)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name, "[-h] [-t] [-n] [-ko FILE] ",\
	"[-s] [-i CIPHERTEXT_FILE] [-o FILE] PUBKEY_FILE\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -h  | -help             : Print command usage then exit            |\n",\
	"| -m  | -modulus          : Print key modulus                        |\n",\
	"| -n  | -noout            : Don't print key out                      |\n",\
	"| -t  | -text             : Print key in text                        |\n",\
	"| -i  | -in FILE          : Input file fir CIPHERTEXT                |\n",\
	"| -o  | -out FILE         : Output file for decrypted CIPHERTEXT     |\n",\
	"| -ko | -keyout FILE      : Output file for Private key              |\n",\
	"| -s  | -show             : Show decrypted CIPHERTEXT                |\n",\
	"**********************************************************************");
	rsa_out(rsa, SUCCESS);
}
