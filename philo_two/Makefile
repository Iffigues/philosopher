NAME=philo_two
SRC= $(wildcard *.c)  ../src/ft_atoi.c ../src/time.c ../src/message.c
OBJ=$(SRC:.c=.o)
CC=gcc -DDIR=2 -Wall -Wextra -Werror
INCLUDE= -I ../
all:$(NAME)
$(NAME):$(OBJ) 
	$(CC) $(OBJ) $(INCLUDE)  -o $(NAME) -pthread  
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
