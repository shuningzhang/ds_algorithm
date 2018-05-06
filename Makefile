
algorithm: data_structure.o main.o
	gcc -g -o algorithm data_structure.o main.o -lpthread

main.o: main.c
	gcc -c -g main.c -o main.o

data_structure.o: data_structure.c data_structure.h
	gcc -c -g data_structure.c
