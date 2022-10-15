# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

sudoku_checker: sudoku_checker.o
	$(CC) $(CFLAGS) -o sudoku_checker sudoku_checker.o

sudoku_checker.o: sudoku_checker.cpp
	$(CC) $(CFLAGS) -c sudoku_checker.cpp

clean:
	rm -rf sudoku_checker sudoku_checker.o
