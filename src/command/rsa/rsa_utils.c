/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:07:10 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/07 22:30:34 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rsa_utils.h"

static t_bool	ge32prime(t_rsa *rsa, uint64_t *num, t_bool is_second)
{
	if (ft_isprime_mr(*num, 1) && (!is_second || (is_second &&\
		*num != rsa->p && SHIFTR(*num * rsa->p, rsa->bits - 1))))
	{
		write(STDERR, "+", 1);
		return (TRUE);
	}
	else if (!(*num = ft_rand(RSA_PRIME_MIN, UINT32_MAX)))
		rsa_out(rsa, FAILURE);
	else
		write(STDERR, ".", 1);
	*num |= SHIFTL((uint64_t)1, (rsa->bits / 2) - 1) | 1;
	return (FALSE);
}

void			get_rsa32prime(t_rsa *rsa, uint64_t *num, t_bool is_second)
{
	uint8_t		k;

	while (TRUE)
		if (k == RSA_PRIME_K)
			break ;
		else if (ge32prime(rsa, num, is_second))
			k++;
		else
			k = 0;
	write(STDERR, "\n", 1);
}

t_bool			get_rsa32prime_n(t_rsa *rsa, uint64_t *num, t_bool is_second)
{
	uint8_t		c;
	uint8_t		k;

	c = 0;
	ft_fprintf(STDERR, "num = %zu\n", *num);
	while (TRUE)
	{
		if (k == RSA_PRIME_K)
			break ;
		else if (ge32prime(rsa, num, is_second))
			k++;
		else
		{
			k = 0;
			if (++c > RSA_PRIME_MAX_K)
				return (FALSE);
		}
	}
	write(STDERR, "\n", 1);
	return (TRUE);
}

static t_bool	rsa_check_prime(t_rsa *rsa)
{
	if (!ft_isprime_mr(rsa->p, RSA_PRIME_K))
		ft_tprintf(rsa->fd, WARN, "RSA key error: p not prime\n");
	else if (!ft_isprime_mr(rsa->q, RSA_PRIME_K))
		ft_tprintf(rsa->fd, WARN, "RSA key error: q not prime\n");
	else
		return (TRUE);
	return (FALSE);
}

void			check_rsa_key(t_rsa *rsa)
{
	int			e;

	e = 0;
	if (!rsa->f.lg.c || !rsa->key || !rsa_check_prime(rsa))
		return ;
	if (!ft_isprime_mr(rsa->e, RSA_PRIME_K))
		e = ft_tprintf(rsa->fd, WARN, "RSA key error: bad e value\n");
	if (rsa->n != (rsa->p * rsa->q))
		e = ft_tprintf(rsa->fd, WARN, "RSA key error: n does not equal p q\n");
	if (rsa->d != ft_modmult_inv(rsa->e, (rsa->p - 1) * (rsa->q - 1)))
		e = ft_tprintf(rsa->fd, WARN,\
						"RSA key error: d e not congruent to 1\n");
	if (rsa->dp != (rsa->d % (rsa->p - 1)))
		e = ft_tprintf(rsa->fd, WARN, "RSA key error: dp not congruent to d\n");
	if (rsa->dq != (rsa->d % (rsa->q - 1)))
		e = ft_tprintf(rsa->fd, WARN, "RSA key error: dq not congruent to d\n");
	if (rsa->iq != ft_modmult_inv(rsa->q, rsa->p))
		e = ft_tprintf(rsa->fd, WARN, "RSA key error: iq not inverse of q\n");
	if (!e)
		ft_tprintf(rsa->fd, OK, "RSA key ok\n");
}
