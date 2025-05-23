SRC = main.cpp Sed.cpp
NAME = sed

CC = c++ -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
