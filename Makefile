# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mteerlin <mteerlin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/21 12:25:06 by mteerlin      #+#    #+#                  #
#    Updated: 2021/09/02 16:36:21 by mteerlin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCL_DIR := incl/
HDR_DIR := hdr/
HDR		:= $(wildcard $(HDR_DIR)*.h)
SRC_DIR := src/
TMP		:= $(wildcard $(SRC_DIR)*.c)
SRC		:= $(TMP:$(SRC_DIR)%=%)

OBJ_DIR := obj/
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR := $(INCL_DIR)libft/
LIBFT	:= $(LIBFT_DIR)libft.a

CFLAGS	?= -Wall -Wextra -Werror -fsanitize=address -g

all: 		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
			$(CC) $(CFLAGS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

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
