all: a.out

a.out: problem-4-3.o ../../utils/binary-search-tree-node.o ../../utils/linked-list.o
	g++ -o a.out problem-4-3.o ../../utils/binary-search-tree-node.o ../../utils/linked-list.o

problem-4-3.o: problem-4-3.cc

../../utils/binary-search-tree-node.o: ../../utils/binary-search-tree-node.h ../../utils/binary-search-tree-node.cc 
../../utils/linked-list.o: ../../utils/linked-list.h ../../utils/linked-list.cc 

clean:
	rm -f ../../utils/binary-search-tree-node.o ../../utils/linked-list.o problem-4-3.o a.out