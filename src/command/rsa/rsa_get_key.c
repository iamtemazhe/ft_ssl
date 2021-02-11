/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_get_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:31:03 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 13:30:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsa_params.h"

static uint64_t		get_asn_len(t_rsa *rsa, t_data *raw_key)
{
	uint64_t		bytes_len;
	uint64_t		raw_key_len;

	bytes_len = (*raw_key->data & 0x80) ? (*raw_key->data & 0x7F) : 1;
	if (!bytes_len || raw_key->n < bytes_len + 1)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid length prefix.\n"));
	raw_key_len = (*raw_key->data & 0x80) ?\
					ft_u64from8(raw_key->data + 1, bytes_len) : *raw_key->data;
	if (!raw_key_len || raw_key->n < raw_key_len + 1)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid key length.\n"));
	raw_key->data += bytes_len;
	raw_key->n -= bytes_len;
	return (raw_key_len);
}

static uint64_t		get_asn64int(t_rsa *rsa, t_data *raw_key)
{
	uint64_t		bytes_len;
	uint64_t		u64num;

	if (*raw_key->data != ASN_TAG_INT)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid integer tag.\n"));
	raw_key->data += 1;
	if ((bytes_len = get_asn_len(rsa, raw_key)) > (RSA_BYTES + 1))
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Invalid number size for %s.\n", RSA_NAME));
	if (*raw_key->data & 0x80)
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Invalid number padding format.\n"));
	u64num = ft_ufrom8(raw_key->data + ((bytes_len > RSA_BYTES) ? 1 : 0),\
						bytes_len);
	raw_key->data += bytes_len;
	raw_key->n -= bytes_len;
	return (u64num);
}

static void			validate_asn(t_rsa *rsa, t_data **p_key,\
									const t_data *sline, const t_data *eline)
{
	t_data			key;
	uint8_t			*p8u;

	if (!(*p_key = get_data_from_fd(rsa->input)))
		rsa_out(rsa, FAILURE);
	if (rsa->is_inform_der)
		return ;
	key.data = (uint8_t *)ft_getcmpmemp((*p_key)->data, (*p_key)->n,\
										sline->data, sline->n);
	if (!key.data || key.data[sline->n] != '\n')
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Invalid %s start line.\n", sline->file_name));
	if (!(p8u = (uint8_t *)ft_getrcmpmemp((*p_key)->data, (*p_key)->n,\
									eline->data, eline->n)) || p8u[-1] != '\n')
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Invalid %s end line.\n", eline->file_name));
	key.data += sline->n + 1;
	key.n = (uint64_t)(p8u - key.data) - 1;
	if ((int64_t)key.n <= 0)
		rsa_out(rsa, ft_tprintf(STDERR, ERR,\
								"Invalid %s data.\n", eline->file_name));
	rsa_pem_decode(rsa, p_key, &key);
}

void				get_rsa_key(t_rsa *rsa)
{
	t_data			raw_key;

	validate_asn(rsa, &rsa->key, &g_rsa_key_sline, &g_rsa_key_eline);
	raw_key.data = rsa->key->data;
	raw_key.n = rsa->key->n - 1;
	if (rsa->key->n < RSA_KEY_MIN_LEN)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid key data.\n"));
	if (*(raw_key.data++) != ASN_TAG_SEQUENCE)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid sequence tag.\n"));
	raw_key.n = get_asn_len(rsa, &raw_key);
	get_asn64int(rsa, &raw_key);
	rsa->n = get_asn64int(rsa, &raw_key);
	rsa->e = get_asn64int(rsa, &raw_key);
	rsa->d = get_asn64int(rsa, &raw_key);
	rsa->p = get_asn64int(rsa, &raw_key);
	rsa->q = get_asn64int(rsa, &raw_key);
	rsa->dp = get_asn64int(rsa, &raw_key);
	rsa->dq = get_asn64int(rsa, &raw_key);
	rsa->iq = get_asn64int(rsa, &raw_key);
	rsa->bits = ft_bitlen(&rsa->n, sizeof(rsa->n));
}

void				get_rsa_pkey(t_rsa *rsa)
{
	t_data			raw_key;

	validate_asn(rsa, &rsa->pkey, &g_rsa_pkey_sline, &g_rsa_pkey_eline);
	raw_key.data = rsa->pkey->data;
	raw_key.n = rsa->pkey->n - 1;
	if (rsa->pkey->n < RSA_PKEY_MIN_LEN)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid public key data.\n"));
	if (*(raw_key.data++) != ASN_TAG_SEQUENCE)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid sequence tag.\n"));
	raw_key.n = get_asn_len(rsa, &raw_key) - g_rsa_pkey_sequence.n + 1;
	if (ft_memcmp(raw_key.data,\
		g_rsa_pkey_sequence.data, g_rsa_pkey_sequence.n))
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid public sequence tag.\n"));
	raw_key.data += g_rsa_pkey_sequence.n;
	if (*(raw_key.data++) != ASN_TAG_SEQUENCE_P)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid sequence tag.\n"));
	get_asn_len(rsa, &raw_key);
	raw_key.data += 1;
	raw_key.n -= 2;
	if (*(raw_key.data++) != ASN_TAG_SEQUENCE)
		rsa_out(rsa, ft_tprintf(STDERR, ERR, "Invalid sequence tag.\n"));
	get_asn_len(rsa, &raw_key);
	rsa->n = get_asn64int(rsa, &raw_key);
	rsa->e = get_asn64int(rsa, &raw_key);
	rsa->bits = ft_bitlen(&rsa->n, sizeof(rsa->n));
}
