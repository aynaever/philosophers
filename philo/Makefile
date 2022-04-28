# File              : Makefile
# Author            : Aymane N <anaouadi@students.42wolfsburg.de>
# Date              : 17.04.2022
# Last Modified Date: 17.04.2022
# Last Modified By  : Aymane N <anaouadi@students.42wolfsburg.de>

NAME = philo
CFILES = main.c utils.c utils2.c
FLAGS = -Wall -Werror -Wextra -g

all:
	gcc $(CFILES) $(FLAGS) -o $(NAME)

run: all
	./$(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
