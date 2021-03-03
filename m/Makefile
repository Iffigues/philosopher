all:build
build:
	make -C philo_one
	make -C philo_two
	make -C philo_three
clean:
	make clean -C philo_one
	make clean -C philo_two
	make clean -C philo_three
fclean:
	make fclean -C philo_one
	make fclean -C philo_two
	make fclean -C philo_three
re:
	make re -C philo_one
	make re -C philo_two
	make re -C philo_three
push:fclean
	git add .
	git commit -m "hello"
	git push
pull:fclean
	git pull
.PHONY:all clean fclean re
