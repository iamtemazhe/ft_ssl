/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:16:35 by hgysella          #+#    #+#             */
/*   Updated: 2021/02/02 00:41:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int		ft_pr_right(t_pf *pf, int w, int i, char c)
{
	while (w-- > 0)
		pf->str[i++] = c;
	return (i);
}

int		ft_printstr(char **str, t_pf *pf)
{
	int		i;
	int		len;
	int		j;
	char	a;

	if (!(len = ft_strlen(*str)) && (pf->flg & MNUL))
		len++;
	if (!(pf->flg & MACC) || pf->tpc != 's')
		pf->acc = len;
	j = get_max3(pf->acc, pf->wid, len);
	if (!(pf->str = ft_strnew(j)))
		exit(ft_strerr(-2, str));
	if (pf->wid)
		pf->wid -= (len > pf->acc) ? pf->acc : len;
	a = (pf->flg & FLG0) ? '0' : ' ';
	i = (pf->flg & FLGM) ? 0 : ft_pr_right(pf, pf->wid, 0, a);
	j = 0;
	while (pf->acc-- > 0 && len-- > 0)
		pf->str[i++] = str[0][j++];
	i = (pf->flg & FLGM) ? ft_pr_right(pf, pf->wid, i, ' ') : i;
	pf->count += write(pf->fildes, pf->str, i);
	return (ft_strerr(0, str));
}

int		isflg(int c)
{
	if (c == '-' || c == '+' || ft_isdigit(c) ||\
		c == '#' || c == '*' || c == '.' || c == ' ')
		return (1);
	return (0);
}

int		get_max3(int a, int b, int c)
{
	int d;

	d = (a > b) ? a : b;
	return ((d > c) ? d : c);
}
