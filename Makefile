CC=g++
CFLAGS=-std=c++0x -I.

main: main.cc constant_node.o multiply_node.o add_node.o node.o
	$(CC) main.cc constant_node.o multiply_node.o add_node.o node.o -o main $(CFLAGS)

constant_node.o: constant_node.cc
	$(CC) -c constant_node.cc $(CFLAGS)

multiply_node.o: multiply_node.cc
	$(CC) -c multiply_node.cc $(CFLAGS)
 
add_node.o: add_node.cc
	$(CC) -c add_node.cc $(CFLAGS)

node.o: node.cc
	$(CC) -c node.cc $(CFLAGS)

clean:
	rm -rf *.o
