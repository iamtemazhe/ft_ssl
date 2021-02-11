/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_inout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 02:51:36 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"

void			genrsa_help(t_ssl *ssl, t_rsa *rsa)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name,\
	"[-h] [-c] [-t] [-m] [-n] [-i FILE] [-o FILE]\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -c  | -check            : Verify key consistency                   |\n",\
	"| -h  | -help             : Print command usage then exit            |\n",\
	"| -m  | -modulus          : Print RSA key modulus                    |\n",\
	"| -n  | -noout            : Don't print key out                      |\n",\
	"| -t  | -text             : Print key in text                        |\n",\
	"| -i  | -in FILE          : Input file                               |\n",\
	"| -o  | -out FILE         : Output file                              |\n",\
	"**********************************************************************");
	rsa_out(rsa, SUCCESS);
}

void			rsa_help(t_ssl *ssl, t_rsa *rsa)
{
	ft_tprintf(STDERR, GRAY, "%s %s %s %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",\
	"usage:", ssl->prog_name, ssl->command->name,\
	"[-h] [-c] [-t] [-m] [-n] [-bi] [-fi FORMAT] [-i FILE] [-pi PASSWORD] ",\
	"[-bo] [-fo FORMAT] [-o FILE] [-des] [-po PASSWORD]\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -*  | -des              : Any supported cipher (-des for example)  |\n",\
	"| -c  | -check            : Verify key consistency                   |\n",\
	"| -h  | -help             : Print command usage then exit            |\n",\
	"| -m  | -modulus          : Print RSA key modulus                    |\n",\
	"| -n  | -noout            : Don't print key out                      |\n",\
	"| -t  | -text             : Print key in text                        |\n",\
	"| -i  | -in FILE          : Input file                               |\n",\
	"| -o  | -out FILE         : Output file                              |\n",\
	"| -bi | -pubin            : Expect Public key in input file          |\n",\
	"| -bo | -pubout           : Output Public key                        |\n",\
	"| -fi | -inform FORMAT    : Input FORMAT [PEM | DER]                 |\n",\
	"| -fo | -outform FORMAT   : Output FORMAT [PEM | DER]                |\n",\
	"| -pi | -passin PASSWORD  : Input file PASSWORD in ASCII             |\n",\
	"| -po | -passout PASSWORD : Output file PASSWORD in ASCII            |\n",\
	"**********************************************************************");
	rsa_out(rsa, SUCCESS);
}

void			rsautl_help(t_ssl *ssl, t_rsa *rsa)
{
	ft_tprintf(STDERR, GRAY, "usage: %s %s %s%s%s%s%s%s%s%s%s%s%s%s%s\n",\
	ssl->prog_name, ssl->command->name,\
	"[-h] [-x] [-e | -d] [-ki FILE] [-fi FORMAT] [-bi] [-i FILE] [-o FILE]\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -e  | -encrypt          : Encrypt with RSA Public key              |\n",\
	"| -d  | -decrypt          : Decrypt with RSA Private key             |\n",\
	"| -h  | -help             : Print command usage then exit            |\n",\
	"| -i  | -in FILE          : Input file                               |\n",\
	"| -o  | -out FILE         : Output file                              |\n",\
	"| -x  | -hexdump          : Hex dump output in RSA format            |\n",\
	"| -bi | -pubin            : Expect Public key in input file          |\n",\
	"| -fi | -inform FORMAT    : Input FORMAT [PEM | DER]                 |\n",\
	"| -ki | -inkey FILE       : Input file RSA KEY                       |\n",\
	"| -pi | -passin PASSWORD  : Input file PASSWORD in ASCII             |\n",\
	"**********************************************************************");
	rsa_out(rsa, SUCCESS);
}

void			rsa_out(t_rsa *rsa, int prnt)
{
	ft_datadel(&rsa->key);
	ft_datadel(&rsa->pkey);
	cipdata_free(&rsa->cipdata_in);
	cipdata_free(&rsa->cipdata_out);
	if (rsa->fd > STDERR)
		close(rsa->fd);
	exit((prnt) ? FAILURE : SUCCESS);
}

void			rsa_init(t_ssl *ssl, t_rsa *rsa)
{
	rsa->f.lag = 0;
	rsa->fd = STDOUT;
	rsa->quiet = FALSE;
	rsa->is_inform_der = FALSE;
	rsa->is_outform_der = FALSE;
	rsa->input = NULL;
	rsa->output = NULL;
	rsa->input_file = NULL;
	rsa->output_file = NULL;
	rsa->key = NULL;
	rsa->pkey = NULL;
	rsa->bits = RSA_BITS;
	rsa->primes = RSA_PRIMES;
	rsa->p = 0;
	rsa->q = 0;
	rsa->e = RSA_DEFAULT_E;
	rsa->ciphers = ssl->ciphers;
	cipdata_init(&rsa->cipdata_in);
	cipdata_init(&rsa->cipdata_out);
	rsa->cipdata_in.mode.is.quiet = TRUE;
	rsa->cipdata_in.hash_params = get_hash_params(RSA_HASH_DEFAULT);
	rsa->cipdata_out.mode.is.quiet = rsa->cipdata_in.mode.is.quiet;
	rsa->cipdata_out.hash_params = rsa->cipdata_in.hash_params;
}
