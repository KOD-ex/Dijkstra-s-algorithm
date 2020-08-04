all: Dijkstras_algorithm
	
Dijkstras_algorithm: main.o Dijkstras_algorithm.o
	gcc main.o Dijkstras_algorithm.o -o my_binary

main.o: main.c
	gcc -c main.c

Dijkstras_algorithm.o: Dijkstras_algorithm.c
	gcc -c Dijkstras_algorithm.c

clean:
	rm -rf *.o Dijkstras_algorithm