##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for compiling lib
##

SRC	=	my_strcmp.c	\
		size_map.c	\
		my_strcpy.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
