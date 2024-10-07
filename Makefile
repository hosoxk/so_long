# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 17:16:13 by yde-rudd          #+#    #+#              #
#    Updated: 2024/10/07 17:16:20 by yde-rudd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	executable, compiler and flags
NAME = so_long
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
PFLAGS = -l Xext -l X11 -l m -l z

#	directories
SRC_DIR = ./sources
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
GET_NEXT_LINE_DIR = ./get_next_line
MLX_DIR = ./minilibx-linux

#	source files
SRC_FILES = $(SRC_DIR)/init.c \
		$(SRC_DIR)/check_map.c \
		$(SRC_DIR)/free.c \
		$(SRC_DIR)/read_map.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/is_map_enclosed.c \
		$(SRC_DIR)/flooding_algo.c \
		$(SRC_DIR)/draw.c \
		$(SRC_DIR)/key_hook.c \
		$(SRC_DIR)/update_player.c \
		$(SRC_DIR)/print_utils.c

#	object files
OBJ_FILES = $(SRC_FILES:.c=.o)

#	libraries
LIBMLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

#	default target: build everything
all: $(LIBFT) $(FT_PRINTF) $(LIBMLX) $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(FT_PRINTF) $(LIBMLX)
	$(CC) $(CFLAGS) $(PFLAGS) $(OBJ_FILES) $(LIBFT) $(FT_PRINTF) $(LIBMLX) -o $(NAME)

#	compile src files to objects files in same directory as source
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBMLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -fr $(OBJ_FILES)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
