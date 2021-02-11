/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_inout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 14:46:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_params.h"
#include "cipher_utils.h"

void					cipher_help(t_ssl *ssl, t_cipher *cipher)
{
	ft_tprintf(STDERR, GRAY, "%s %s %s %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",\
	"usage:", ssl->prog_name, ssl->command->name,\
	"[-h] [-w] [-d |-e] [-a] [-c] [-i FILE] [-o FILE] [-p PASSWORD] "
	"[-k KEY] [-s SALT] [-v VECTOR] [-m HASH] [-n ITER]\n",\
	"********************** COMMAND FLAGS *********************************\n",\
	"| -a            : Decode/Encode the input/output in cipher           |\n",\
	"| -c            : Disable standard block padding                     |\n",\
	"| -d            : Decrypt mode                                       |\n",\
	"| -e            : Encrypt mode (default)                             |\n",\
	"| -f            : Use Password-Based Key Derivation Function 2       |\n",\
	"| -h            : Print command usage then exit                      |\n",\
	"| -i FILE       : Input file                                         |\n",\
	"| -k KEY        : Key in HEX                                         |\n",\
	"| -m HASH       : Specified HASH to create KEY from PASSWORD         |\n",\
	"| -n ITER       : Iteration count in uint and force use of PBKDF2    |\n",\
	"| -o FILE       : Output file                                        |\n",\
	"| -p PASSWORD   : Password in ASCII                                  |\n",\
	"| -s SALT       : Salt in HEX                                        |\n",\
	"| -v VECTOR     : Initialization vector (iv) VECTOR in HEX           |\n",\
	"| -w            : Print key/salt/iv                                  |\n",\
	"**********************************************************************");
	cipher_out(cipher, SUCCESS);
}

void					cipher_out(t_cipher *cipher, int prnt)
{
	cipdata_free(&cipher->cipdata);
	if (cipher->fd > STDERR)
		close(cipher->fd);
	exit((prnt) ? FAILURE : SUCCESS);
}

void					cipher_init(t_ssl *ssl, t_cipher *cipher)
{
	int16_t				i;

	cipher->f.lag = 0;
	cipher->fd = STDOUT;
	cipher->input = NULL;
	cipher->output = NULL;
	cipdata_init(&cipher->cipdata);
	i = -1;
	while (++i < CIPHERS_NUM)
		if (ssl->command->cipher == g_cipher_params[i].cipher)
		{
			cipher->cipdata.params = &g_cipher_params[i];
			break ;
		}
	cipher->cipdata.name = ssl->command->name;
}

t_bool					fill_cipher_params(const t_command *ciphers,\
									const char *cipher_name, t_cipdata *cipdata)
{
	uint8_t				i;
	const t_command		*cipcom;

	if (!cipher_name)
		return (FALSE);
	i = -1;
	cipcom = NULL;
	while (++i < SSL_CIPHERS_NUM)
		if (!ft_strcmpi(cipher_name, ciphers[i].name))
		{
			cipcom = &ciphers[i];
			break ;
		}
	if (!cipcom || !cipcom->cipher)
		return (FALSE);
	i = 0;
	while (i < CIPHERS_NUM && cipcom->cipher != g_cipher_params[i].cipher)
		i++;
	cipdata->params = &g_cipher_params[i];
	cipdata->name = cipcom->out;
	return (TRUE);
}

const char				*get_cipher_name(const t_command *ciphers,\
											const char *cipher_name, char c_end)
{
	uint8_t				i;

	i = -1;
	while (++i < SSL_CIPHERS_NUM)
		if (!ft_strncmpi(cipher_name, ciphers[i].name,\
			ft_strchr(cipher_name, c_end) - cipher_name))
			return (ciphers[i].out);
	return (NULL);
}
