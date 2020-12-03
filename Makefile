NAME=philo_one/philo_one
SRC =	main.c src/time.c src/ft_atoi.c src/ft_peer.c src/opt.c src/time.c philo_one/begin.c philo_one/fork.c philo_one/one.c 
OBJ=$(SRC:.c=.o)
OBJ := $(subst philo_one, ./, $(OBJ))
OBJ := $(subst src/, ./, $(OBJ))
CC=gcc -Wall -Wextra -Werror
INCLUDE= -I ./
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME) -pthread 
%.o:%.c
	$(CC) $(INCLUDE) -c $< 
clean:
	rm -f *.o
fclean:clean
	rm -f $(NAME)
re:fclean all
.PHONY:all clean fclean re

