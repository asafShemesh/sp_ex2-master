all:connections

connections: my_graph.o my_mat.o
	gcc -Wall my_graph.o my_mat.o -o connections

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -c my_graph.c 

my_mat.o: my_mat.c
	gcc -Wall -c my_mat.c 

clean:
	rm *.o connections 

.PHONY : .clean all
