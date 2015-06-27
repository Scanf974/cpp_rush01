# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/16 11:13:38 by bsautron          #+#    #+#              #
#    Updated: 2015/06/27 18:02:37 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
NAME = ft_gkrellm
CFLAGS = -Wextra -Wall -Werror

SRC_MAIN = main.cpp

SRC_CLASS = GKrellM.class.cpp \
			Hostname.class.cpp \
			AModule.class.cpp \
			Date.class.cpp \
			Osinfo.class.cpp

SRC = $(SRC_MAIN)
SRC += $(addprefix srcs/, $(SRC_CLASS))

HEADER_SRC = AModule.class.hpp \
			 Cpu.class.hpp \
			 Date.class.hpp \
			 GKrellM.class.hpp \
			 Hostname.class.hpp \
			 IMonitorDisplay.class.hpp \
			 IMonitorModule.class.hpp \
			 NetworkThroughput.class.hpp \
			 Osinfo.class.hpp \
			 RAM.class.hpp

HEADER = $(addprefix includes/, $(HEADER_SRC))

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
