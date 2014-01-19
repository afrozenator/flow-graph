CC=g++
CFLAGS=-std=c++0x -I.

simple_main: simple_main.cc node.o constant_node.o node_utils.o input_node.o add_node.o multiply_node.o
	$(CC) simple_main.cc node.o constant_node.o node_utils.o input_node.o add_node.o multiply_node.o $(CFLAGS) -o simple_main.out

multiply_node.o: multiply_node.cc node.o
	$(CC) -c multiply_node.cc $(CFLAGS)

add_node.o: add_node.cc node.o
	$(CC) -c add_node.cc $(CFLAGS)

input_node.o: input_node.cc node.o
	$(CC) -c input_node.cc $(CFLAGS)

node_utils.o: node_utils.cc node.o
	$(CC) -c node_utils.cc $(CFLAGS)

parameter_node.o: node.o parameter_node.cc
	$(CC) -c parameter_node.cc $(CFLAGS)

constant_node.o: node.o constant_node.cc
	$(CC) -c constant_node.cc $(CFLAGS)

node.o: node.cc
	$(CC) -c node.cc $(CFLAGS)

clean:
	rm -rf *.o; rm -rf *.out
