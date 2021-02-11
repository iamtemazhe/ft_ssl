/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_get_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:59:23 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/09 13:31:07 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsa_utils.h"
#include "dsa_params.h"

static uint64_t		get_asn_len(t_dsa *dsa, t_data *raw_key)
{
	uint64_t		bytes_len;
	uint64_t		raw_key_len;

	bytes_len = (*raw_key->data & 0x80) ? (*raw_key->data & 0x7F) : 1;
	if (!bytes_len || raw_key->n < bytes_len + 1)
		dsa_out(dsa, ft_tprintf(STDERR, ERR, "Invalid length prefix.\n"));
	raw_key_len = (*raw_key->data & 0x80) ?\
					ft_u64from8(raw_key->data + 1, bytes_len) : *raw_key->data;
	if (!raw_key_len || raw_key->n < raw_key_len + 1)
		dsa_out(dsa, ft_tprintf(STDERR, ERR, "Invalid key length.\n"));
	raw_key->data += bytes_len;
	raw_key->n -= bytes_len;
	return (raw_key_len);
}

static uint64_t		get_asn64int(t_dsa *dsa, t_data *raw_key)
{
	uint64_t		bytes_len;
	uint64_t		u64num;

	if (*raw_key->data != ASN_TAG_INT)
		dsa_out(dsa, ft_tprintf(STDERR, ERR, "Invalid integer tag.\n"));
	raw_key->data += 1;
	if ((bytes_len = get_asn_len(dsa, raw_key)) > (DSA_BYTES + 1))
		dsa_out(dsa, ft_tprintf(STDERR, ERR,\
								"Invalid number size for %s.\n", DSA_NAME));
	if (*raw_key->data & 0x80)
		dsa_out(dsa, ft_tprintf(STDERR, ERR,\
								"Invalid number padding format.\n"));
	u64num = ft_ufrom8(raw_key->data + ((bytes_len > DSA_BYTES) ? 1 : 0),\
						bytes_len);
	raw_key->data += bytes_len;
	raw_key->n -= bytes_len;
	return (u64num);
}

static void			validate_asn(t_dsa *dsa, t_data **p_key,\
									const t_data *sline, const t_data *eline)
{
	t_data			key;
	uint8_t			*p8u;

	if (!(*p_key = get_data_from_fd(dsa->input)))
		dsa_out(dsa, FAILURE);
	key.data = (uint8_t *)ft_getcmpmemp((*p_key)->data, (*p_key)->n,\
										sline->data, sline->n);
	if (!key.data || key.data[sline->n] != '\n')
		dsa_out(dsa, ft_tprintf(STDERR, ERR,\
								"Invalid %s start line.\n", sline->file_name));
	if (!(p8u = (uint8_t *)ft_getrcmpmemp((*p_key)->data, (*p_key)->n,\
									eline->data, eline->n)) || p8u[-1] != '\n')
		dsa_out(dsa, ft_tprintf(STDERR, ERR,\
								"Invalid %s end line.\n", eline->file_name));
	key.data += sline->n + 1;
	key.n = (uint64_t)(p8u - key.data) - 1;
	if ((int64_t)key.n <= 0)
		dsa_out(dsa, ft_tprintf(STDERR, ERR,\
								"Invalid %s data.\n", eline->file_name));
	if (!ft_datafreplace(p_key,\
								base64_decode(key.data, key.n)))
		dsa_out(dsa, ft_tprintf(STDERR, ERR, "Base64 decode error.\n"));
}

void				get_dsa_key(t_dsa *dsa)
{
	t_data			raw_key;

	validate_asn(dsa, &dsa->key, &g_dsa_key_sline, &g_dsa_key_eline);
	raw_key.data = dsa->key->data;
	raw_key.n = dsa->key->n - 1;
	if (dsa->key->n < DSA_KEY_MIN_LEN)
		dsa_out(dsa, ft_tprintf(STDERR, ERR, "Invalid key data.\n"));
	if (*(raw_key.data++) != ASN_TAG_SEQUENCE)
		dsa_out(dsa, ft_tprintf(STDERR, ERR, "Invalid sequence tag.\n"));
	raw_key.n = get_asn_len(dsa, &raw_key);
	get_asn64int(dsa, &raw_key);
	dsa->p = get_asn64int(dsa, &raw_key);
	dsa->q = get_asn64int(dsa, &raw_key);
	dsa->g = get_asn64int(dsa, &raw_key);
	dsa->y = get_asn64int(dsa, &raw_key);
	dsa->x = get_asn64int(dsa, &raw_key);
	dsa->bits = ft_bitlen(&dsa->p, sizeof(dsa->p));
}
