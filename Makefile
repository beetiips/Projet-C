CC :=gcc
FLAGS := -std=c99 -Wall -Werror -Wextra

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c shapes.c
	$(CC) $(FLAGS) -c cli.c
	$(CC) $(FLAGS) -c linked_list.c
	$(CC) $(FLAGS) shapes.o cli.o main.o linked_list.o -o main
