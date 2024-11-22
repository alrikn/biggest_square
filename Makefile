##
## EPITECH PROJECT, 2024
## My_printf
## File description:
## Makefile
##

LIB_NAME = libmy.a
NAME = setting_up
TEST_BIN = unit_tests

SRC = ./main.c \
	./dimension_array.c \
	./my_is_digit.c \
	./my_numlen.c \
	./finding_square.c \
	./my_str_to_int.c \
	./step_1.c \
	./my_strncpy.c \
	./file_handler.c \
	./my_putstr.c \
	./my_strlen.c \
	./generating_own.c \
	./my_lseek.c \
	./free_array.c \
	./correct_format.c \

TEST_SRC = $(SRC) \
	./tests/test_my_printf.c

CC = gcc
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -g
INCLUDE_PATH = ./include/
LDFLAGS = -I$(INCLUDE_PATH)
TEST_LDFLAGS = $(LDFLAGS) --coverage -lcriterion
DESTINATION = -I$(INCLUDE_PATH) -L. -lmy



all: $(LIB_NAME) $(NAME)

$(NAME): $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(DESTINATION)

$(LIB_NAME): $(OBJ)
	ar -rc $(LIB_NAME) $(OBJ)

$(TEST_BIN):
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_SRC) $(TEST_LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re: fclean $(LIB_NAME) $(NAME)

compile:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS)

coverage: tests_run
	gcovr -r .
	gcovr -r . --branches

.PHONY: all re compile coverage fclean clean
