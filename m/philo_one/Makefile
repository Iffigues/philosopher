NAME=philo_one
SRC= $(wildcard *.c)  ../src/srco/ft_atoi.c ../src/srco/time.c ../src/srco/message.c
OBJ=$(SRC:.c=.o)
CC=gcc -Wall -Wextra -Werror -fsanitize=address
DIR="-DDIR=1"
INCLUDE= -I ../
all:$(NAME)
$(NAME):$(OBJ) 
	$(CC) $(DIR)  $(OBJ) $(INCLUDE)  -o $(NAME) -pthread  
clean:
	rm -f *.o
	rm -f ../src/srco/*.o
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
