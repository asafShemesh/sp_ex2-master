all:my_graph my_knapsack

my_graph: my_graph.o my_mat.o
	gcc -Wall my_graph.o my_mat.o -o my_graph

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -c my_graph.c 

my_knapsack.o: my_knapsack.c
	gcc -Wall -c my_knapsack.c 

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -c my_mat.c 

clean:
	rm *.o my_graph 

.PHONY : .clean all
