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
	./utils/my_is_digit.c \
	./utils/my_numlen.c \
	./utils/my_strncat.c \
	./utils/my_memcpy.c \
	./utils/my_str_to_int.c \
	./utils/my_strlen.c \
	./utils/my_strncpy.c \
	./utils/my_lseek.c \
	./utils/my_cooler_putstr.c \
	./array_handlers/finding_square.c \
	./array_handlers/dimension_array.c \
	./error_management/step_1.c \
	./array_handlers/file_handler.c \
	./array_handlers/generating_own.c \
	./error_management/free_array.c \
	./error_management/correct_format.c \

TEST_SRC = $(SRC) \
	./tests/test_my_printf.c

CC = clang
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -O3
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

## flame graph of where the time goes (needs perf)
## override the map with: make flame_check FLAME_ARGS="path/to/map"
FLAME_ARGS_GENERATE ?= 10000 "......o......o....o..........o......o."
FLAME_ARGS_PARSE ?= example_files/maps/intermediate_map_1000_1000_2

#now flame check will do one where it generates (called flame_gen.svg) and one where it parses (called flame_parse.svg)
#both will happen when flame check is called, but you can also call them separately with flame_gen and flame_parse

flame_check: flame_gen flame_parse

flame_gen: CFLAGS += -g -fno-omit-frame-pointer
flame_gen: re
	mkdir -p docs
	perf record -g --call-graph dwarf ./$(NAME) $(FLAME_ARGS_GENERATE) > /dev/null
	perf script > out.perf
	./graph_test/stackcollapse-perf.pl out.perf > out.folded
	./graph_test/flamegraph.pl --width 2000 out.folded > docs/flame_gen.svg
	rm -f out.perf out.folded perf.data perf.data.old

flame_parse: CFLAGS += -g -fno-omit-frame-pointer
flame_parse: re
	mkdir -p docs
	perf record -g --call-graph dwarf ./$(NAME) $(FLAME_ARGS_PARSE) > /dev/null
	perf script > out.perf
	./graph_test/stackcollapse-perf.pl out.perf > out.folded
	./graph_test/flamegraph.pl --width 2000 out.folded > docs/flame_parse.svg
	rm -f out.perf out.folded perf.data perf.data.old

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

.PHONY: all re compile coverage fclean clean flame_check
