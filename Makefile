

CC=g++
FLAGS=-std=c++2a

sudoku : sudoku.o
	${CC} sudoku.o -o sudoku
sudoku.o : sudoku.cpp sudoku.h
	${CC} ${FLAGS} -c sudoku.cpp


