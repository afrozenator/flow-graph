CC=g++
CFLAGS=-std=c++0x -I.

main: main.cc constant_node.o multiply_node.o add_node.o weighted_node.o node.o
	$(CC) main.cc constant_node.o multiply_node.o add_node.o weighted_node.o node.o -o main $(CFLAGS)

constant_node.o: constant_node.cc  node.o
	$(CC) -c constant_node.cc $(CFLAGS)

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
