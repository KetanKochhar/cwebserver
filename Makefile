CC = gcc
FLAGS = -Wall -Wextra

all:
	@$(CC) $(FLAGS) main.c -o app


clean:
	@rm -rfv app
