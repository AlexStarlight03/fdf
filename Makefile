# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <adube@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 09:33:12 by adube             #+#    #+#              #
#    Updated: 2023/09/21 10:05:13 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
BONUS := fdf_bonus

GLFW := -L/Users/$(USER)/.brew/opt/glfw/lib -lglfw

LIBFT := ./lib/libft
LIBFT_AR := $(LIBFT)/libft.a

LIBMLX := ./lib/MLX42
LIBMLX_AR := $(LIBMLX)/build/libmlx42.a
LIBMLX_FLAGS := -ldl $(GLFW) -pthread -lm

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include

SRC_DIR := ./src
OBJ_DIR := ./obj

EXCLUDE_MAIN =	$(SRC_DIR)/main.c \
				$(SRC_DIR)/key_hooks.c
EXCLUDE_BONUS =	$(SRC_DIR)/main_bonus.c \
				$(SRC_DIR)/key_hooks_bonus.c \
				$(SRC_DIR)/display_movetotal_bonus.c

# SRC := $(shell find $(SRC_DIR) -iname "*.c")
SRC_MAIN = $(filter-out $(EXCLUDE_BONUS), $(wildcard $(SRC_DIR)/*.c))
OBJ_MAIN := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_MAIN))

SRC_BONUS = $(filter-out $(EXCLUDE_MAIN), $(wildcard $(SRC_DIR)/*.c))
OBJ_BONUS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))

CC := gcc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
RM := rm -rf

MK_C := $(MAKE) -C

# *********************************** RULES ********************************** #

all: $(LIBMLX_AR) $(LIBFT_AR) $(NAME)
	@echo "-- fdf created --"

$(LIBMLX_AR):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && $(MK_C) $(LIBMLX)/build -j4

$(LIBFT_AR):
	@$(MK_C) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ_DIR) $(OBJ_MAIN)
	@$(CC) $(OBJ_MAIN) $(LIBMLX_AR) $(LIBMLX_FLAGS) $(LIBFT_AR) $(HEADERS) -o $(NAME)

$(OBJ_DIR):
	@mkdir $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIBMLX)/build
	@$(MK_C) $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@$(MK_C) $(LIBFT) fclean

re: fclean all

bonus: $(LIBMLX_AR) $(LIBFT_AR) $(BONUS)
	@echo "-- fdf_bonus created --"

$(BONUS): $(OBJ_DIR) $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBMLX_AR) $(LIBMLX_FLAGS) $(LIBFT_AR) $(HEADERS) -o $(BONUS)

.PHONY: all, clean, fclean, re, bonus

# VALGRIND #

PARAM = test.ber

val: $(NAME)
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes -s \
	./$(NAME) $(PARAM)
