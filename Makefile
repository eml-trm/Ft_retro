# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 17:37:47 by etermeau          #+#    #+#              #
#    Updated: 2015/06/15 17:37:48 by etermeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror

SRC = Character.class.cpp \
	Enemy.class.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $^

%.o: $(DIRSRC)%.cpp
	@$(CC) $(FLAGS) -o $@ -c $< -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@echo "\033[4;32mDeleted\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[4;32mDeleted\033[0;33m $(NAME)\033[0m"

re: fclean all

