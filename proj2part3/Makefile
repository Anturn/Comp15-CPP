#
# Makefile for proj1
#
#

CXX      = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra
LDFLAGS  = -g3




gerp: Node.o hashTable.o FSTree.o DirNode.o main.o 
	${CXX} ${LDFLAGS} -o gerp Node.o hashTable.o main.o FSTree.o DirNode.o


Node.o:			 Node.cpp Node.h 
hashTable.o: hashTable.cpp hashTable.h Node.h FSTree.h 
main.o:			 main.cpp   hashTable.h






