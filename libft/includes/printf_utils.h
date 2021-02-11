/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 00:39:15 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/04 01:31:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "libft.h"
# include "ft_printf.h"

# define MALL		0x4000
# define MNUL		0x2000
# define FLGM		0x1000
# define FLGP		0x0800
# define FLGE		0x0400
# define FLGS		0x0200
# define FLG0		0x0100
# define MACC		0x0080
# define MOD2		0x0040
# define MODH		0x0020
# define MODL		0x0010
# define MODUL		0x0008
# define MODJ		0x0004
# define MODZ		0x0002
# define TYPUP		0x0001

typedef struct		s_pf
{
	short int		flg;
	int				wid;
	int				acc;
	int				count;
	int				fildes;
	char			tpc;
	char			*str;
}					t_pf;

void				type_analis(va_list ap, t_pf *pf);
void				nbr_round_ld(unsigned char nbr, const char *base,\
															t_pf *pf, int i);
void				print_str(const char *format, va_list ap, t_pf *pf);

int					isflg(int c);
int					get_max3(int a, int b, int c);
int					ft_base_analis(const char *base);
int					ft_printstr(char **str, t_pf *pf);
int					ft_pr_left(t_pf *pf, short int sgn, int len_s);
int					ft_pr_right(t_pf *pf, int w, int i, char c);
unsigned long long	nbr_round_ll(long double nbr, const char *base, t_pf *pf,\
																int len_b);

char				*base_analis(char *base, t_pf *pf);
char				*ft_itoa_base_ll(unsigned long long nbr,\
											char **base, t_pf *pf);
char				*ft_itoa_base_ld(long double nbr,\
											char **base, t_pf *pf);
#endif
