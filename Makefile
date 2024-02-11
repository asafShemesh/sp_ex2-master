all:my_graph my_Knapsack

my_graph: my_graph.o my_mat.o
	gcc -Wall my_graph.o my_mat.o -o my_graph

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -c my_graph.c 

my_Knapsack.o: my_Knapsack.c
	gcc -Wall -c my_Knapsack.c 

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -c my_mat.c 

clean:
	rm *.o my_graph my_Knapsack

.PHONY : .clean all
