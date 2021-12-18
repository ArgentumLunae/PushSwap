# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mteerlin <mteerlin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/21 12:25:06 by mteerlin      #+#    #+#                  #
#    Updated: 2021/12/18 15:32:14 by mteerlin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources.mk

NAME	= push_swap

INCL_DIR := incl/
HDR_DIR := hdr/
HDR		:= pushswap.h
SRCSFL	:= sources.txt
SRC_DIR := src/

OBJ_DIR := obj/
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR := $(INCL_DIR)libft/
LIBFT	:= $(LIBFT_DIR)libft.a

AR		?= ar rcs;
LDFLAGS ?= -fsanitize=address -g
CFLAGS	?= -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(LDFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR) bonus

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c $(HDR_DIR)$(HDR)
			@mkdir -p $(dir $@)
			$(CC) -c $< -o $@

clean:
			rm -f $(OBJ_DIR)*.o $(LIBFT_DIR)*.o $(MLX_DIR)*.o
			@rmdir -p $(OBJ_DIR)

fclean:
			$(MAKE) clean
			rm -f $(NAME) $(LIBFT) $(MLX)
re:
			$(MAKE) fclean
			$(MAKE) all
