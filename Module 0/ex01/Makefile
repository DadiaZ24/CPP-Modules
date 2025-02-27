# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 14:02:06 by ddias-fe          #+#    #+#              #
#    Updated: 2025/02/27 15:50:59 by ddias-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Contact.cpp PhoneBook.cpp main.cpp

NAME = phonebook

CC = c++ -Wall -Werror -Wextra  -std=c++98
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
