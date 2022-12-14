CC = gcc
SRC =
OBJ = ${SRC:.c=.o}
DEPS = monty.h
NAME = monty
CFLAGS = -Wall -Werror -Wextra -pedantic -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
	clean

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $^

run:
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: clean
clean: ; $(RM) $(OBJ)
