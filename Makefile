# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:39:50 by jaewpark          #+#    #+#              #
#    Updated: 2022/03/16 20:10:00 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
MINLBX_DIR = ./minilibx/

SRC_FILES = color.c \
			control_key.c \
			control_mouse.c \
			fern.c \
			fractols.c \
			info.c \
			main.c \
			render.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MINLBX = $(addprefix $(MINLBX_DIR), libmlx.a)

# all rule
all: obj  $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(INC_DIR) -o $@ -c $<
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
	@clear
	@echo "\033[32m║▌│█║▌│ \033[0m\033[73m█║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.5
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌\033[0m\033[73m║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.5
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█\033[0m\033[73m║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.5
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║\033[0m\033[73m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.5
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \033[0m\033[33m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.5
	@clear
	@$(CC) $(FLAGS) $(MLX) -o $(NAME) $(OBJ)
	@echo "═════════•°• $(NAME) generated •°•═════════"
	@sleep 1
	@echo
	@echo "\033[01;31m⎹⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴\
	⎴⎴⎴⎴⎴⎴⎴⎴⎴⎸"
	@echo "\033[01;31m⎹ \033[0m\033[07;37m   Fract-ol Menu              \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹ \033[0m\033[01;32m    ./fractol                 \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵\
	⎵⎵⎵⎵⎵⎵⎵⎵⎵⎸"
	@echo
	@echo "\033[07;37m   MENU USAGE   \033[0m"
	@echo "\033[01;36m   Keys  : [ESC]       -> Exit      \033[0m"
	@echo "\033[01;36m   Keys  : [W, S]      -> Select      \033[0m"
	@echo "\033[01;36m   Keys  : [Enter]     -> Show Fract-ol\033[0m"
	@echo "\033[01;36m   Keys  : [BACKSPACE] -> Return Menu\033[0m"
	@echo
	@echo "\033[07;37m   JULIA & MANDELBROT USAGE   \033[0m"
	@echo "\033[01;36m   Mouse : [L-Click]    -> Freeze / Activate \033[0m \
	\033[01;33m [JULIA] \033[0m"
	@echo "\033[01;36m   Mouse :  Moving      -> Change            \033[0m \
	\033[01;33m [JULIA] \033[0m"
	@echo "\033[01;36m   Mouse : [R-Click]    -> Colorize \033[0m"
	@echo "\033[01;36m   Mouse : [SCROLL]     -> Zoom      \033[0m"
	@echo "\033[01;36m   Keys  : [↑, ↓, →, ←] -> Move      \033[0m"
	@echo
	@echo "\033[07;37m   SECRET USAGE   \033[0m"
	@echo "\033[01;36m   Keys  : [R]         -> Random      \033[0m"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(MINLBX_DIR) clean
	@echo "═════════•°• Objects removed •°•═════════"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "═════════•°• $(NAME) removed •°•═════════"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
