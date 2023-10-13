# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <adube@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 09:33:12 by adube             #+#    #+#              #
#    Updated: 2023/10/13 13:42:15 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus


LIBFT := ./lib/libft
LIBFT_AR := $(LIBFT)/libft.a

LIBMLX := ./lib/MLX42
LIBMLX_AR := $(LIBMLX)/build/libmlx42.a
LIBMLX_FLAGS := -ldl $(GLFW) -pthread -lm
OPEN_GL		=	-framework Cocoa -framework OpenGL -framework IOKit
GLFW		=	-lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"

HEADER_DIR	=	./include
HEADER_LIST	=	fdf.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

SRC_DIR := ./src
OBJ_DIR := ./obj

SRCS_LIST	=	breseham.c color_scheme.c errors.c main.c get_map.c hooks.c init.c parsing.c position.c utils.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

CC := gcc
CFLAGS := -Wextra -Wall -Werror -g
RM := rm -rf


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

PARAM = test.fdf

val: $(NAME)
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes -s \
	./$(NAME) $(PARAM)
