##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile that compiles your libmy
##
CC	=	gcc

SRC	=	$(wildcard *.c)

OFILES  =	$(SRC:.c=.o)

NAME    =	libmy.a

CPY_HEADER = my.h

DIR_INCLUDE = ../../include

CFLAGS  =   -Wall -I../../include

all:	create_include_dir copymyheader copyLib

create_include_dir:
	mkdir -p $(DIR_INCLUDE)

copyLib: $(NAME)
	cp $(NAME) ../

copymyheader: $(CPY_HEADER)
	cp $(CPY_HEADER) $(DIR_INCLUDE)

$(NAME):	$(OFILES)
	    $(AR) -rc $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re:
	fclean $(NAME)

.PHONY:  all clean fclean re
