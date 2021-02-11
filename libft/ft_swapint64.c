/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:19:28 by jwinthei          #+#    #+#             */
/*   Updated: 2020/12/01 18:25:05 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint64_t		ft_swapint64(uint64_t x)
{
	return (((x & 0x00000000000000FFULL) << 56) |\
			((x & 0x000000000000FF00ULL) << 40) |\
			((x & 0x0000000000FF0000ULL) << 24) |\
			((x & 0x00000000FF000000ULL) << 8) |\
			((x & 0x000000FF00000000ULL) >> 8) |\
			((x & 0x0000FF0000000000ULL) >> 24) |\
			((x & 0x00FF000000000000ULL) >> 40) |\
			((x & 0xFF00000000000000ULL) >> 56));
}