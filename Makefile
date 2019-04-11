##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## main Makefile
##

SRC	=	src/my_sokoban.c	\
		src/annex_my_sokoban.c	\
		src/stock_map.c	\
		src/event.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include/ -Wall -Wextra

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(SRC) $(LIB) $(CPPFLAGS) -lncurses

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean

fclean:	clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY:	all clean fclean re
