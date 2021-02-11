/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:36:18 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/31 08:30:40 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64_utils.h"

static void			base64_post_encode(const uint8_t *buf, t_bool second_word,\
										t_data *cipher, size_t j)
{
	cipher->data[j++] = g_base64_h[SHIFTR(buf[0], 2)];
	if (second_word)
	{
		cipher->data[j++] = g_base64_h[BASE64_WORD2(buf[0], buf[1])];
		cipher->data[j++] = g_base64_h[BASE64_WORD3(buf[1], 0)];
	}
	else
	{
		cipher->data[j++] = g_base64_h[BASE64_WORD2(buf[0], 0)];
		cipher->data[j++] = '=';
	}
	cipher->data[j] = '=';
}

t_data				*base64_encode(const void *data, size_t n)
{
	size_t			i;
	size_t			j;
	size_t			len;
	t_data			*cipher;
	const uint8_t	*buf;

	len = ((n + BASE64_BYTES - 1) / BASE64_BYTES) * BASE64_WORDS;
	if (!data || !n || len < n || !(cipher = ft_datanew(len)))
		return (NULL);
	buf = (uint8_t *)data;
	j = 0;
	i = BASE64_BYTES - 1;
	while (i < n)
	{
		cipher->data[j++] = g_base64_h[BASE64_WORD1(buf[i - 2])];
		cipher->data[j++] = g_base64_h[BASE64_WORD2(buf[i - 2], buf[i - 1])];
		cipher->data[j++] = g_base64_h[BASE64_WORD3(buf[i - 1], buf[i])];
		cipher->data[j++] = g_base64_h[BASE64_WORD4(buf[i])];
		i += BASE64_BYTES;
	}
	if (j < cipher->n)
		base64_post_encode(&buf[i - 2], (i - 1) < n, cipher, j);
	return (cipher);
}

static t_data		*base64_pre_decode(const void *data, size_t n,\
										t_data **buf)
{
	size_t			i;
	size_t			j;
	size_t			len;
	const uint8_t	*u8data;

	i = -1;
	j = 0;
	u8data = (uint8_t *)data;
	while (++i < n)
		if (!ft_iswhitespace(u8data[i]))
		{
			if (g_unbase64_h[u8data[i]] >= 0)
				(*buf)->data[j++] = u8data[i];
			else
				return (NULL);
		}
	(*buf)->n = j;
	if (!(*buf)->n || ((*buf)->n % BASE64_WORDS))
		return (NULL);
	len = (((*buf)->n + BASE64_WORDS - 1) / BASE64_WORDS) * BASE64_BYTES;
	i = (*buf)->n - 1;
	while ((*buf)->data[i--] == '=')
		if ((*buf)->data[i] == '=' || !(g_unbase64_h[(*buf)->data[i]] & 0x3))
			len--;
	return (ft_datanew(len));
}

static void			base64_post_decode(t_data *buf, size_t i,\
										t_data *decoded, size_t j)
{
	if (j < decoded->n)
		decoded->data[j++] = SHIFTL(g_unbase64_h[buf->data[i - 4]], 2) |\
							SHIFTR(g_unbase64_h[buf->data[i - 3]], 4);
	if (j < decoded->n)
		decoded->data[j++] = SHIFTL(g_unbase64_h[buf->data[i - 3]], 4);
	if (i == buf->n)
	{
		decoded->data[j - 1] |= SHIFTR(g_unbase64_h[buf->data[i - 2]], 2);
		if (j < decoded->n)
			decoded->data[j] = SHIFTL(g_unbase64_h[buf->data[i - 2]], 6) |\
										g_unbase64_h[buf->data[i - 1]];
	}
}

t_data				*base64_decode(const void *data, size_t n)
{
	size_t			i;
	size_t			j;
	t_data			*decoded;
	t_data			*buf;

	if (!data || !n || !(buf = ft_datanew(n)))
		return (NULL);
	if ((decoded = base64_pre_decode(data, n, &buf)))
	{
		j = 0;
		i = BASE64_WORDS;
		while (i < buf->n - BASE64_WORDS + 1)
		{
			decoded->data[j++] = SHIFTL(g_unbase64_h[buf->data[i - 4]], 2) |\
								SHIFTR(g_unbase64_h[buf->data[i - 3]], 4);
			decoded->data[j++] = SHIFTL(g_unbase64_h[buf->data[i - 3]], 4) |\
								SHIFTR(g_unbase64_h[buf->data[i - 2]], 2);
			decoded->data[j++] = SHIFTL(g_unbase64_h[buf->data[i - 2]], 6) |\
										g_unbase64_h[buf->data[i - 1]];
			i += BASE64_WORDS;
		}
		base64_post_decode(buf, i, decoded, j);
	}
	ft_datadel(&buf);
	return (decoded);
}
