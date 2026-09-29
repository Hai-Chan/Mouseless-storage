#variables for update

CC = gcc 
CFLAGS = -std=c89 -Wall -Wextra -pedantic

#target that runs when type 'make'
all: store

#target to complie
store: store.c
	$(CC) $(CFLAGS) store.c -o store 

#target to safely reset directory by removing executable and txt file
clean:
	rm -f store inventory.txt temp.txt 
