NAME = philo
BNAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
HEAD = philo.h
cc = CC
SRC = philo.c argvchecker.c ft_utils.c

all : $(NAME)

$(NAME) : $(SRC)
	$(cc) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(BNAME)

re : fclean all

.PHONY : fclean clean re bonus