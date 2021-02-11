/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsa_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:02:13 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/08 09:40:08 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsa_utils.h"

static t_bool	get64prime(t_dsa *dsa, uint64_t *num,\
							t_bool is_second, uint64_t max_val)
{
	if (ft_isprime_mr(*num, 1) && (!is_second ||\
		(is_second && *num != dsa->q && SHIFTR(*num, BIT_64 - 1))))
	{
		write(STDERR, "+", 1);
		return (TRUE);
	}
	else if (!(*num = ft_rand((is_second) ? MAX_UINT16 : DSA_PRIME_MIN,\
								(max_val) ? max_val : MAX_UINT64)))
		dsa_out(dsa, FAILURE);
	else
		write(STDERR, ".", 1);
	*num |= 1;
	return (FALSE);
}

void			get_dsa64prime(t_dsa *dsa, uint64_t *num,\
								t_bool is_second, uint64_t max_val)
{
	uint8_t		k;

	while (TRUE)
		if (k == DSA_PRIME_K)
			break ;
		else if (get64prime(dsa, num, is_second, max_val))
			k++;
		else
			k = 0;
	write(STDERR, "\n", 1);
}
