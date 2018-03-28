#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 13:14:13 by dchirkin          #+#    #+#              #
#    Updated: 2017/04/11 13:17:42 by dchirkin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fdf

LIBNAME	=	libft.a
SRC		=	bbrf.c			\
			count.c			\
			driving.c		\
			ft_atoi_mod.c	\
			izometr.c		\
			key_press.c		\
			mouse.c			\
			pov.c			\
			qqqq.c			\
			split.c			\
			val_sr.c

OBJ		=	$(subst .c,.o,$(SRC))
HEADER	=	fdf.h
FLS		=	-Wall -Wextra -Werror
FLSMLX	=	-lmlx -framework OpenGL -framework AppKit
VPATH	=	includes:libft:src
all:		$(NAME)
$(NAME):	$(OBJ) $(LIBNAME)
			gcc $(FLS) $(OBJ) -o $(NAME) libft/$(LIBNAME) $(FLSMLX)
$(LIBNAME):
			make -C ./libft/
%.o:		%.c $(HEADER)
			gcc $(FLS) -c -o $@ $< -I ./includes
clean:
			@make -C ./libft clean
			@echo "cleaned" libft
			@/bin/rm -rf $(OBJ) *~
			@echo "cleaned" $(NAME)
fclean:		clean
			@make -C ./libft fclean
			@echo "fcleaned" libft/$(LIBNAME)
			@/bin/rm -f $(NAME)
			@echo "fcleaned" $(NAME)
re:			fclean all
