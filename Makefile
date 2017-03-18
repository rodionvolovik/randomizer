NAME = random
SRC = randomizer.c
CC = gcc -Wall -Werror -Wextra

.phony: all clean fclean re

all:
	$(CC) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: fclean all