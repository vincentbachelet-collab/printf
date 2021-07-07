# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 14:33:18 by vbachele          #+#    #+#              #
#    Updated: 2021/07/07 14:52:08 by vbachele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=			libftprintf.a

SRC_PATH=		src/

LIBFT_PATH=		libft/

LIBFT_LIB=		libft.a

SRC_FILES=		ft_printf.c \
				ft_gestionflag.c \
				ft_gestionflag2.c \
				ft_putnbr.c \
				ft_printf.c \
				ft_printfputnbr_base.c \
				ft_gestion_conversions.c \
				Ft_utils_gestion_Conversion.c \
				ft_Utils_Gestion_String.c \
				ft_utilsprintf.c \
				ft_Utils_Gestion_Caractere.c \
				ft_Utils_Gestion_Decimal1.c \
				ft_Utils_Gestion_Decimal2.c \
				ft_Utils_Gestion_Decimal3.c \
				ft_Utils_Gestion_Pointeur.c \
				ft_Utils_Gestion_Unsigned.c \
				ft_Utils_Gestion_Unsigned2.c \
				ft_Utils_Gestion_Hexadecimal_x_X1.c \
				ft_Utils_Gestion_Hexadecimal_x_X2.c \

SRC_OBJS=		${SRC_FILES:.c=.o}

CC= 			gcc

CFLAGS=			-Wall -Wextra -Werror

RM=				rm -f

AR=				ar rcs

LIBFT_OBJS=		${LIBFT_PATH}*.o

LIBFTMAKE=		$(MAKE) -C ${LIBFT_PATH} bonus

all:			${NAME}

${NAME}:    	${SRC_OBJS} pmake
				${AR} ${NAME} ${SRC_OBJS} ${LIBFT_OBJS}

pmake:
				${LIBFTMAKE}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRC_OBJS}

fclean: 		clean
				${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re pmake

# NAME= libftprintf.a

# FLAG= -Wall -Wextra -Werror

# SRC=		ft_printf.c \
# 			ft_gestionflag.c \
# 			ft_isprint.c \
# 			ft_putnbr.c \
# 			ft_printfputnbr_base.c \
# 			Ft_utils_gestion_Conversion.c \
# 			ft_utils_gestion_conversion2.c \
# 			ft_utilsprintf.c

# LIBFT_OBJ=	libft/*.o

# OBJ=		$(SRC:.c=.o)

# all:		$(NAME)

# $(LIBFTMAKE)=	$(MAKE) -C libft/ bonus

# $(NAME):	$(OBJ) lmake
# 			@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
# 			@ranlib $(NAME)

# %.o: %.c
# 			@gcc $(FLAG) -c $< -o $@
			
# lmake:	
# 			$(LIBFTMAKE)

# clean:
# 			make -C libft/ clean
# 			@rm -f $(OBJ)

# fclean:		clean
# 			@rm -f $(NAME) 

# re:			fclean all

# .PHONY:		all, clean, fclean, re, lmake