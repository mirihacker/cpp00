# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 11:14:47 by smiranda          #+#    #+#              #
#    Updated: 2025/03/10 11:17:07 by smiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS = Contact.cpp PhoneBook.cpp main.cpp
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME)	: $(OBJS)
		@$(CC) $(CFLAGS) $^ -o $(NAME)
		@echo '$(NAME) compiled!'

fclean	: clean
		@$(RM) $(NAME)

clean	:
		@$(RM) $(OBJS)

re	:	fclean all

.PHONY	:	all clean fclean re