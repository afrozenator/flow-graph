CC=g++
CFLAGS=-std=c++0x -I.

dining_problem_main: dining_problem_main.cc flow_graph.o squared_error_loss_node.o input_node.o constant_node.o multiply_node.o add_node.o weighted_node.o node.o
	$(CC) dining_problem_main.cc flow_graph.o squared_error_loss_node.o input_node.o constant_node.o multiply_node.o add_node.o weighted_node.o node.o -o dining_problem_main $(CFLAGS)

main: main.cc input_node.o constant_node.o multiply_node.o add_node.o weighted_node.o node.o
	$(CC) main.cc input_node.o constant_node.o multiply_node.o add_node.o weighted_node.o node.o -o main $(CFLAGS)

squared_error_loss_function.o: squared_error_loss_function.cc flow_graph.o
	$(CC) -c squared_error_loss_function.cc $(CFLAGS)

squared_error_loss_node.o: squared_error_loss_node.cc node.o
	$(CC) -c squared_error_loss_node.cc $(CFLAGS)

flow_graph.o: flow_graph.cc node.o
	$(CC) -c flow_graph.cc $(CFLAGS)

constant_node.o: constant_node.cc  input_node.o
	$(CC) -c constant_node.cc $(CFLAGS)

input_node.o: input_node.cc node.o
	$(CC) -c input_node.cc $(CFLAGS)

multiply_node.o: multiply_node.cc  node.o
	$(CC) -c multiply_node.cc $(CFLAGS)
 
add_node.o: add_node.cc weighted_node.o
	$(CC) -c add_node.cc $(CFLAGS)

weighted_node.o: weighted_node.cc node.o
	$(CC) -c weighted_node.cc $(CFLAGS)

node.o: node.cc
	$(CC) -c node.cc $(CFLAGS)

clean:
	rm -rf *.o; rm main
