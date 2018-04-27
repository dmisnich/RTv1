# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 12:37:43 by dmisnich          #+#    #+#              #
#    Updated: 2018/01/26 11:39:24 by dmisnich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

CC = gcc

FLAGS = -Wall -Wextra -Werror

CFLAGS = -I ./include/ \
					-I Frameworks/SDL2.framework/Headers


SRCS =	src/main.c \
		src/vector_operation.c \
		src/ray.c \
		src/init.c \
		src/sphere.c \
		src/plane.c \
		src/cylindre.c \
		src/cone.c \



OBJ = $(SRCS:.c=.o)

#libft
LFT_DIR = ./libft/
LFT_LNK = -L $(LFT_DIR) -lft

#sdl
SDL_LNK = -framework SDL2 -F ./Frameworks/
SDL2_P	= -rpath @loader_path/Frameworks/

all: $(NAME)

debug:
	$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) $(LFT_LNK) $(SDL_LNK)
derun: debug
	lldb ./$(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_DIR)
	@$(CC) -o $(NAME) $(FLAGS) $(CFLAGS) $(SDL2_P) $(SDL_LNK) $(LFT_LNK) $(OBJ) -g

clean:
	@make -C $(LFT_DIR) clean
	@rm -f src/*.o
	@rm -rf ./*.dSYM

norme:
	@echo "|--------------------------------------------------|"
	@echo "|-------------------Checking header files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./include
	@echo "|--------------------------------------------------|"
	@echo "--------------------Checking source files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./src

fclean: clean
	@make -C $(LFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.SILENT:
