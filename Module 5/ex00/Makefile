SRC = main.cpp src/Bureaucrat.cpp src/Cat.cpp src/WrongAnimal.cpp src/WrongCat.cpp
NAME = Bureaucrat

CC = c++ -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
