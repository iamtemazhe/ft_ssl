# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 17:33:40 by jwinthei          #+#    #+#              #
#    Updated: 2021/02/11 11:26:31 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSL =		ft_ssl
LIB =		libft.a

SRC_D =		src/
LIB_D =		libft/
SSL_D =		$(SRC_D)
HASH_D =	$(SRC_D)hash/
MD5_D =		$(HASH_D)ft_md5/
SHA2_D =	$(HASH_D)ft_sha2/
CIPHER_D =	$(SRC_D)cipher/
BASE64_D =	$(CIPHER_D)ft_base64/
HMAC_D =	$(CIPHER_D)ft_hmac/
DES_D =		$(CIPHER_D)ft_des/
COMMAND_D =	$(SRC_D)command/
RSA_D =		$(COMMAND_D)rsa/
GENDSA_D =	$(COMMAND_D)gendsa/

INC_D =		includes/
INC_LIB = 	$(LIB_D)$(INC_D)
INC_TYPES =	$(INC_D)types/
INC_HASH = 	$(INC_D)hash/
INC_MD5 = 	$(INC_HASH)ft_md5/
INC_SHA2 = 	$(INC_HASH)ft_sha2/
INC_CIPHER =$(INC_D)cipher/
INC_BASE64 =$(INC_CIPHER)ft_base64/
INC_HMAC =	$(INC_CIPHER)ft_hmac/
INC_DES =	$(INC_CIPHER)ft_des/
INC_COMMAND=$(INC_D)command/
INC_RSA =	$(INC_COMMAND)rsa/
INC_GDSA =	$(INC_COMMAND)gendsa/

SSL_S =		ft_ssl.c			ssl_out.c			ssl_utils.c
HASH_S =	hash.c				hash_utils.c
MD5_S = 	ft_md5.c			md5_utils.c
SHA2_S = 	sha2_32.c			sha2_utils_32.c		ft_sha2_32.c\
			sha2_64.c			sha2_utils_64.c		ft_sha2_64.c
CIPHER_S =	cipher.c			cipher_inout.c		cipher_utils.c\
			cipdata.c			cipdata_key.c
BASE64_S =	ft_base64.c			base64_utils.c
HMAC_S =	ft_hmac.c			ft_hmac32.c			ft_hmac64.c
DES_S =		ft_des.c			ft_des_feedback.c\
			ft_des3.c			ft_des3_feedback.c\
			des.c				des_utils.c			des_permutation.c
RSA_S =		ssl_genrsa.c		rsa_inout.c			rsa_utils.c\
			rsa_print.c			rsa_key.c			rsa_get_key.c\
			ssl_rsa.c			rsa_des.c\
			ssl_rsautl.c		rsa.c\
			ssl_breakrsa.c		breakrsa_utils.c
GENDSA_S =	ssl_gendsa.c		dsa_inout.c			dsa_utils.c\
			dsa_print.c			dsa_key.c			dsa_get_key.c
COMMAND_S =	ssl_rand.c			ssl_prime.c			ssl_hexdump.c\
			ssl_gendes.c


LIB_C =		$(wildcard $(LIB_D)*.c $(LIB_D)*/*.c)
MD5_C = 	$(addprefix $(MD5_D), $(MD5_S))
SHA2_C = 	$(addprefix $(SHA2_D), $(SHA2_S))
HASH_C = 	$(addprefix $(HASH_D), $(HASH_S))\
			$(MD5_C) $(SHA2_C)
BASE64_C =	$(addprefix $(BASE64_D), $(BASE64_S))
HMAC_C =	$(addprefix $(HMAC_D), $(HMAC_S))
DES_C =		$(addprefix $(DES_D), $(DES_S))
CIPHER_C =	$(addprefix $(CIPHER_D), $(CIPHER_S))\
			$(BASE64_C) $(HMAC_C) $(DES_C)
RSA_C =		$(addprefix $(RSA_D), $(RSA_S))
GENDSA_C = 	$(addprefix $(GENDSA_D), $(GENDSA_S))
COMMAND_C =	$(addprefix $(COMMAND_D), $(COMMAND_S))\
			$(RSA_C) $(GENDSA_C)
SSL_C =		$(addprefix $(SSL_D), $(SSL_S))\
			$(HASH_C) $(CIPHER_C) $(COMMAND_C)
SSL_O = 	$(SSL_C:.c=.o)
LIB_O = 	$(LIB_C:.c=.o)

FLG	=		-Wall -Wextra -Werror
FLG	+=		-Wno-unused-result
MATH_LIB = 	-lm
CFLAGS =	-O3 $(FLG) $(MATH_LIB) -I $(INC_LIB)\
			-I $(INC_D) -I $(INC_TYPES)\
			-I $(INC_HASH) -I $(INC_MD5) -I $(INC_SHA2)\
			-I $(INC_CIPHER) -I $(INC_BASE64) -I $(INC_HMAC) -I $(INC_DES)\
			-I $(INC_COMMAND) -I $(INC_RSA) -I $(INC_GDSA)

all: $(LIB) $(SSL)

allc: all clean CLR

$(LIB):
	@make -C $(LIB_D)

$(SSL):	$(LIB_O) $(SSL_O)
	gcc -O2 -o $(SSL) $(SSL_O) $(CFLAGS) -L $(LIB_D) -lft

clean:
	@find ./ -name "*.o" -type f -delete
	@make -s -C $(LIB_D) clean

fclean: clean
	@rm -f $(SSL)
	@make -s -C $(LIB_D) fclean

re: fclean all

CLR:
	clear

norm:
	@$(MAKE) -s fclean
	norminette $(INC_D) $(SRC_D) $(LIB_D)

normq:
	@$(MAKE) -s norm | grep Error -B 1 || echo "Success!"
