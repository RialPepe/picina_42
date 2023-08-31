NAME = rush-02
SRC = printer.c dicts.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
all:
	$(MAKE) $(NAME)
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm -f $(NAME)
fclean:
	$(MAKE) clean
re:
	$(MAKE) fclean
	$(MAKE) all
