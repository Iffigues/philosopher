NAME=philo_three
SRC= $(wildcard *.c)  ../src/ft_atoi.c ../src/time.c ../src/message.c
OBJ=$(SRC:.c=.o)
CC=gcc -Wall -Wextra -Werror
DIR="-DDIR=3"
INCLUDE= -I ../
all:$(NAME)
$(NAME):$(OBJ) 
	$(CC) $(DIR)  $(OBJ) $(INCLUDE)  -o $(NAME) -pthread  
clean:
	rm -f *.o
	rm -f ../src/*.o
fclean:clean
	rm -f $(NAME)
re:fclean all
push:fclean
	git add .
	git commit -m "hello"
	git push
pull:fclean
	git pull
.PHONY:all clean fclean re
