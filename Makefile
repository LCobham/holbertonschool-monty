CC = gcc
SRC = main.c opcode_functions.c get_opcode.c opcode_functions2.c advanced.c advanced2.c queue.c 
OBJ = ${SRC:.c=.o}
DEPS = monty.h
NAME = monty
CFLAGS = -Wall -Werror -Wextra -pedantic -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
	make clean

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $^

run:
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: clean
clean: ; $(RM) $(OBJ)
