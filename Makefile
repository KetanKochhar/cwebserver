CC = gcc
FLAGS = -Wall -Wextra
FILE = req/*.c

all:
	@$(CC) $(FLAGS) main.c $(FILE) -o app


clean:
	@rm -rfv app
