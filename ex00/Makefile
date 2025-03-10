# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 17:36:56 by smiranda          #+#    #+#              #
#    Updated: 2025/03/10 15:34:31 by smiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC_DIR = ./src/
SRCS = megaphone.cpp
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
NEW_SRCS = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(NEW_SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME)	: $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo '$(NAME) compiled!'

clean	:
		@$(RM) $(OBJS)

fclean	: clean
		@$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re