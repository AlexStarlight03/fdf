# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <adube@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 09:33:12 by adube             #+#    #+#              #
#    Updated: 2023/10/20 20:21:58 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

FRAMEWORK :=-framework OpenGL -framework AppKit

LIBFT := ./lib/libft
LIBFT_AR := $(LIBFT)/libft.a

MLX := ./lib/minilibx_macos
MLX_A := $(MLX)/libmlx.a

HEADERS	:= -I ./include -I $(MLX)/include -I $(LIBFT)/include

SRC_DIR := ./src

OBJ_DIR := ./obj

SRC_MAIN =	$(SRC_DIR)/main.c \
				$(SRC_DIR)/hooks.c \
				$(SRC_DIR)/breseham.c \
				$(SRC_DIR)/get_map.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/window.c \
				$(SRC_DIR)/positions.c \
				$(SRC_DIR)/colors.c \
				$(SRC_DIR)/parsing_utils.c \
				$(SRC_DIR)/color_modes.c 


OBJ_MAIN := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_MAIN))

CC := gcc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
RM := rm -rf

MK_C := $(MAKE) -C

# *********************************** RULES ********************************** #

all: $(MLX_A) $(LIBFT_AR) $(NAME)
	@echo "-- fdf created --"

$(MLX_A):
	@$(MAKE) -s -C $(MLX) $(FRAMEWORK)

$(LIBFT_AR):
	@$(MK_C) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ_DIR) $(OBJ_MAIN)
	@$(CC) $(OBJ_MAIN) $(MLX_A) $(LIBFT_AR) $(HEADERS) -o $(NAME) $(FRAMEWORK)

$(OBJ_DIR):
	@mkdir $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(MLX)/build
	@$(MK_C) $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME) 
	@$(MK_C) $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re, bonus

