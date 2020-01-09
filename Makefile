##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the libmy
##

CC = gcc

RM = rm -f

SRC =	bsq.c \
	bsq_sub.c \
	to_char.c \
	my_get_nbr.c \
	main.c 

OBJ = $(SRC:.c=.o)

NAME = bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
