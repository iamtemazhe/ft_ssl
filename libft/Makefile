# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:26:35 by jwinthei          #+#    #+#              #
#    Updated: 2021/02/06 10:08:32 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC = 	ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c		\
	  	ft_memmove.c	ft_memchr.c		ft_memcmp.c		ft_strlen.c			\
	  	ft_strdup.c		ft_strcpy.c		ft_strncpy.c	ft_strlcpy.c		\
	  	ft_strcat.c		ft_strncat.c	ft_strlcat.c	ft_strchr.c			\
	  	ft_strrchr.c	ft_strstr.c		ft_strnstr.c	ft_strcmp.c			\
	  	ft_strncmp.c	ft_atoi.c		ft_isalpha.c	ft_isdigit.c		\
	  	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_toupper.c		\
	  	ft_tolower.c	ft_strcmpi.c	ft_strncmpi.c	ft_display_file.c	\
	  	ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c			\
	  	ft_strclr.c		ft_striter.c	ft_striteri.c	ft_strmap.c			\
	  	ft_strmapi.c	ft_strequ.c		ft_strnequ.c	ft_strsub.c			\
	  	ft_strjoin.c	ft_strtrim.c	ft_strsplit.c	ft_itoa.c			\
	  	ft_putchar.c	ft_putstr.c		ft_putnbr.c		ft_putendl.c		\
	  	ft_putchar_fd.c	ft_putstr_fd.c	ft_putnbr_fd.c	ft_putendl_fd.c		\
	  	ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c			\
	  	ft_lstiter.c	ft_lstmap.c		ft_putchari.c	ft_putchari_fd.c	\
	  	ft_pow.c		ft_sqrt.c		ft_isprime.c	ft_swap.c			\
	  	ft_strlchr.c	ft_nstrnew.c	ft_strrealloc.c	ft_fabs.c			\
	  	get_next_line.c	ft_strerr.c		ft_nstrerr.c	ft_puterr.c			\
	  	ft_putnendl.c	ft_chrcnt.c		ft_strfnew.c	ft_abs.c			\
	  	ft_wcsnew.c		ft_wcsdup.c		ft_wcsdel.c		ft_err.c			\
	  	ft_realloc.c	ft_memdup.c		ft_memjoin.c	ft_memsub.c			\
		ft_masserr.c	ft_nmasserr.c	ft_memnset.c	ft_strcsub.c		\
		ft_errno.c		ft_putupper.c	ft_putlower.c	ft_strcrealloc.c	\
	  	ft_labs.c		ft_modpow.c		pratoi.c		pratoi_hex.c		\
	  	ft_swapint32.c	ft_swapint64.c	ft_pswap.c		ft_u64from8.c		\
	  	ft_u32from8.c	ft_u8from32.c	ft_u8from64.c	ft_u8from_any.c		\
	  	ft_filesize.c	ft_fileopen.c	ft_rand.c		ft_iswhitespace.c	\
	  	ft_ishex.c		ft_getstrp.c	ft_fromhex.c	ft_patoi.c			\
		ft_memxor.c		ft_fileexist.c	ft_isprime_mr.c	ft_gcd.c			\
		ft_max.c		ft_getmemp.c	ft_modmult.c	ft_modmult_inv.c	\
		ft_bitlen.c		ft_hexdump_fd.c

CST = 	t_data_op1.c	t_data_op2.c	t_data_op3.c	t_data_op4.c		\
	  	t_data_op5.c	t_data_op6.c

PRF =	ft_printf.c		itoa_base.c 	output.c		printstr.c 			\
	  	printf.c		types_analis.c	numeric_processing.c

INC_D =	includes/
TYP_D =	types/
PRF_D =	ft_printf/

SRC_C =	$(SRC)\
		$(addprefix $(PRF_D), $(PRF))\
		$(addprefix $(TYP_D), $(CST))

OBJ = 	$(SRC_C:.c=.o)
CFLAGS+=-O2 -Wall -Wextra -Werror -Wno-unused-result -I $(INC_D)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(PBJ)
	ranlib $(NAME)

clean:
	@rm -f *.o
	@make -C $(PRF_D) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all
