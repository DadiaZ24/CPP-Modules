SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
NAME = zombie

CC = c++ -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
