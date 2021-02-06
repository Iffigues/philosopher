NAME=philo_one
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
CC=gcc -Wall -Wextra -Werror -fsanitize=address
DIR="-DDIR=1"
INCLUDE= -I ../
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(DIR) $(INCLUDE) $(OBJ) -o $(NAME) -pthread  
%.o:%.c
	$(CC) $(INCLUDE) -c $< 
clean:
	rm -f *.o
fclean:clean
	rm -f $(NAME)
re:fclean all
.PHONY:all clean fclean re
