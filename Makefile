NAME = philo
CFLAGS = -Wall -Wextra -Werror
HEAD = philo.h
cc = CC
SRC = philo.c argvchecker.c ft_utils.c ft_onewhile.c

all : $(NAME)

$(NAME) : $(SRC)
	$(cc) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all

.PHONY : fclean clean re bonus