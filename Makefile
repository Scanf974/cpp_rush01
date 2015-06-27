# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/16 11:13:38 by bsautron          #+#    #+#              #
#    Updated: 2015/06/27 10:47:54 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
NAME = ft_gkrellm
CFLAGS = -Wextra -Wall -Werror

SRC_MAIN = main.cpp

# SRC_CLASS = 

SRC = $(SRC_MAIN)
# SRC += $(addprefix srcs/, $(SRC_CLASS))

# HEADER = 

DIR_HEADERS = -I includes/

OBJ = $(SRC:%.cpp=.obj/%.o)

OBJ_DIR = .obj/ \
		  .obj/srcs/

.PHONY: all libs clean fclean re

all: dor $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ -lncurses
	@echo "\033[32mReady!\033[0m"

dor:
	@mkdir $(OBJ_DIR) 2> /dev/null || env -i

.obj/%.o: %.cpp $(HEADER)
	@echo "\033[33m 	$<"
	@$(CC) $(CFLAGS) -o $@ $(DIR_HEADERS) -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all
