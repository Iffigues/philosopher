all:build
build:
	make -C philo_one
clean:
	make clean -C philo_one
fclean:
	make fclean -C philo_one
re:
	make re -C philo_one
.PHONY:all clean fclean re
