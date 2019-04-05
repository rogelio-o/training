all: a.out

a.out: problem-4-5.o ../../utils/binary-search-tree-node.o
	g++ -o a.out problem-4-5.o ../../utils/binary-search-tree-node.o

problem-4-5.o: problem-4-5.cc

../../utils/binary-search-tree-node.o: ../../utils/binary-search-tree-node.h ../../utils/binary-search-tree-node.cc 

clean:
	rm -f ../../utils/binary-search-tree-node.o problem-4-5.o a.out