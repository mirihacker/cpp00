# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 11:14:47 by smiranda          #+#    #+#              #
#    Updated: 2025/03/10 16:22:54 by smiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRC_DIR = ./src/
INC_DIR = ./inc/
SRCS = Contact.cpp PhoneBook.cpp main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NEW_SRCS = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(NEW_SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

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