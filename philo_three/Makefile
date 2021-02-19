NAME=philo_three
SRC= $(wildcard *.c)  ../src/srcf/ft_atoi.c ../src/srcf/time.c ../src/srcf/messagef.c
OBJ=$(SRC:.c=.o)
CC=gcc -DDIR=3  -Wall -Wextra -Werror
INCLUDE= -I ../
all:$(NAME)
$(NAME):$(OBJ) 
	$(CC) $(OBJ) $(INCLUDE)  -o $(NAME) -pthread  
clean:
	rm -f *.o
	rm -f ../src/srcf/*.o
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
