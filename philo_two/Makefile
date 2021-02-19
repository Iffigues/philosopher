NAME=philo_two
SRC= $(wildcard *.c)  ../src/srct/ft_atoi.c ../src/srct/time.c ../src/srct/messagem.c
OBJ=$(SRC:.c=.o)
CC=gcc -DDIR=2 -fsanitize=address -Wall -Wextra -Werror
INCLUDE= -I ../
all:$(NAME)
$(NAME):$(OBJ) 
	$(CC) $(OBJ) $(INCLUDE)  -o $(NAME) -pthread  
clean:
	rm -f *.o
	rm -f ../src/srct/*.o
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
