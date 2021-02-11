/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:04:36 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 11:32:52 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"
#include "rsautl_options.h"

t_data				*rsa_chinese_decrypt(t_rsa *rsa, const t_data *msg)
{
	size_t			i;
	uint64_t		u64block;
	uint64_t		mp;
	uint64_t		mq;
	t_data			*outdata;

	i = ((msg->n + BYTE_64 - 1) / BYTE_64) * BYTE_64;
	if (!(outdata = ft_datanew(i)))
		return (NULL);
	i = 0;
	while (i < outdata->n)
	{
		u64block = ft_u64from8(msg->data + i, BYTE_64);
		mp = ft_modpow(u64block, rsa->dp, rsa->p);
		mq = ft_modpow(u64block, rsa->dq, rsa->q);
		u64block = (mp < mq) ? (((rsa->q + rsa->p - 1) / rsa->p) * rsa->p) : 0;
		u64block = ft_modmult((mp + u64block - mq), rsa->iq, rsa->p);
		u64block = (mq + (u64block * rsa->q)) % rsa->n;
		ft_u8from64(outdata->data + i, ft_swapint64(u64block));
		i += BYTE_64;
	}
	return (outdata);
}

t_data				*rsa_crypt(const void *data, size_t n,\
								uint64_t modulus, uint64_t exponent)
{
	size_t			i;
	uint64_t		u64block;
	const uint8_t	*u8data;
	t_data			*outdata;

	i = ((n + BYTE_64 - 1) / BYTE_64) * BYTE_64;
	if (!(outdata = ft_datanew(i)))
		return (NULL);
	u8data = (uint8_t *)data;
	i = 0;
	while (i < outdata->n)
	{
		u64block = ft_u64from8(u8data + i, BYTE_64);
		u64block = ft_modpow(u64block, exponent, modulus);
		ft_u8from64(outdata->data + i, ft_swapint64(u64block));
		i += BYTE_64;
	}
	return (outdata);
}

t_data				*rsa_clear_msg(t_data **msg, t_bool decrypt_mode)
{
	size_t			i;
	t_data			*tmp;
	size_t			pad_n;

	if (!(msg && *msg && !decrypt_mode))
		return (*msg);
	i = 0;
	tmp = NULL;
	pad_n = ((*msg)->n + RSA_PKSC_LEN + RSA_BYTES - 1) / RSA_BYTES;
	pad_n *= RSA_BYTES;
	while (i < (*msg)->n && !((*msg)->data[i] & 0x80))
		i++;
	if (i < (*msg)->n)
		ft_tprintf(STDERR, ERR, "Binary files is not supported\n");
	else if ((tmp = ft_datanew(pad_n)) &&\
		ft_rand_fill(tmp->data + RSA_PKSC_SLEN,\
						pad_n - (*msg)->n - RSA_PKSC_LEN, 1, INT8_MAX))
	{
		tmp->data[1] = RSA_PKSC1T2;
		ft_memcpy(tmp->data + pad_n - (*msg)->n, (*msg)->data, (*msg)->n);
	}
	ft_datadel(msg);
	*msg = tmp;
	return (tmp);
}

t_data				*rsa_clear_outdata(t_rsa *rsa, t_data **outdata,\
										t_bool decrypt_mode)
{
	t_data			*tmp;
	size_t			pad_n;

	tmp = NULL;
	if (!(outdata && *outdata && decrypt_mode))
		return (*outdata);
	pad_n = (size_t)(ft_strchr((char *)(*outdata)->data + RSA_PKSC_SLEN, 0) -\
									(char *)(*outdata)->data) + RSA_PKSC_ELEN;
	if ((*outdata)->n % RSA_BYTES || (*outdata)->data[0] ||\
		(*outdata)->data[1] != RSA_PKSC1T2 || (*outdata)->n == (pad_n - 1))
	{
		if (!rsa->quiet)
			ft_tprintf(STDERR, ERR, "RSA PKCS decoding error");
	}
	else
		tmp = ft_datamemdup((*outdata)->data + pad_n, (*outdata)->n - pad_n);
	ft_datadel(outdata);
	*outdata = tmp;
	return (tmp);
}

void				rsa_it(t_rsa *rsa, t_data *msg, t_bool decrypt_mode)
{
	t_data			*outdata;

	if (!(msg = rsa_clear_msg(&msg, decrypt_mode)))
		rsa_out(rsa, FAILURE);
	outdata = rsa_crypt(msg->data, msg->n, rsa->n,\
							(decrypt_mode) ? rsa->d : rsa->e);
	ft_datadel(&msg);
	if (!(outdata = rsa_clear_outdata(rsa, &outdata, decrypt_mode)))
		rsa_out(rsa, FAILURE);
	if (rsa->output && (rsa->fd = ft_fileopen(rsa->output, O_CREAT)) <= 0)
		rsa_out(rsa, ft_errno(rsa->output));
	if (rsa->f.lg.x)
		rsa_hexdump(rsa, outdata);
	else
		ft_putdata_fd(outdata, rsa->fd, PRINT_CHAR);
	ft_datadel(&outdata);
	if (rsa->output)
		close(rsa->fd);
}
