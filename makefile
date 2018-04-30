NAME = fillit
SRC = check.c thirdpart.c resolve.c parsing.c ./libft/ft_strdel.c ./libft/ft_strsplit.c ./libft/ft_memdel.c ./libft/ft_strlen.c ./libft/ft_strsub.c
OBJ = check.o thirdpart.o resolve.o parsing.o ft_strdel.o ft_strsplit.o ft_memdel.o ft_strlen.o ft_strsub.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc $(OBJ) -o $(NAME)
clean:
	/bin/rm -Rf $(OBJ)
fclean: clean
	/bin/rm -Rf $(NAME)
	/bin/rm -Rf ./libft/libft.a
re: fclean all
