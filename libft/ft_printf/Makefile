# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:26:35 by jwinthei          #+#    #+#              #
#    Updated: 2021/02/03 17:44:48 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_printf.c		itoa_base.c		output.c	printstr.c	\
		printf.c		types_analis.c	numeric_processing.c

INCL= 	../includes/
OBJ = 	$(SRC:.c=.o)
CFLAGS+=-O2 -Wall -Wextra -Werror -I $(INCL)

all: $(OBJ)

clean:
	@rm -f *.o

fclean : clean

re: fclean all
