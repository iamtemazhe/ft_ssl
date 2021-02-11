/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_permutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:29:47 by jwinthei          #+#    #+#             */
/*   Updated: 2021/01/20 19:52:24 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des_utils.h"

inline uint64_t		initial_permutation(uint64_t u64block)
{
	return (permutation(g_des_ip, DES_BLOCK, u64block, BIT_64));
}

inline uint64_t		final_permutation(uint64_t u64block)
{
	return (permutation(g_des_fp, DES_BLOCK, u64block, BIT_64));
}

inline uint64_t		expansion_permutation(uint32_t u32block)
{
	return (permutation(g_des_ep, DES_EP_SIZE, u32block, BIT_32));
}

inline uint32_t		substitution_permutation(uint64_t u48block)
{
	return (permutation(g_des_sp, DES_SP_SIZE, u48block, BIT_32));
}

inline uint64_t		round_key_permutation(uint64_t u64block)
{
	return (permutation(g_des_rkp, DES_RKP_SIZE, u64block, BIT_64));
}
