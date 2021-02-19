NAME=philo_two
SRC= $(wildcard *.c)  ../srct/ft_atoi.c ../srct/time.c ../srct/messagem.c
OBJ=$(SRC:.c=.o)
CC=gcc -DDIR=2 -fsanitize=address -Wall -Wextra -Werror
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
