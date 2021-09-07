# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mteerlin <mteerlin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/21 12:25:06 by mteerlin      #+#    #+#                  #
#    Updated: 2021/09/07 11:55:44 by mteerlin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCL_DIR := incl/
HDR_DIR := hdr/
HDR		:= pushswap.h
SRCSFL	:= sources.txt
SRC_DIR := src/
SRC		:= $(shell cat $(sources.txt))

OBJ_DIR := obj/
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR := $(INCL_DIR)libft/
LIBFT	:= $(LIBFT_DIR)libft.a

CFLAGS	?= -Wall -Wextra -Werror -fsanitize=address -g

all: 		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR) bonus

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c $(HDR_DIR)$(HDR)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ_DIR)*.o $(LIBFT_DIR)*.o $(MLX_DIR)*.o
			@rmdir -p $(OBJ_DIR)

fclean:
			$(MAKE) clean
			rm -f $(NAME) $(LIBFT) $(MLX)
re:
			$(MAKE) fclean
			$(MAKE) all
