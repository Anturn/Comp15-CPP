#include <iostream>

#include "heap.h"

using namespace std;

Heap::Heap()
{
	heap        = new string[INIT_SIZE];
	heapSize    = 0;
	maxCapacity = INIT_SIZE;
}

// destructor
Heap::~Heap()
{
	// TODO: your code here
}

Heap::Heap(string list[], int listSize)
{

	heap        = new string[listSize + 1];
	maxCapacity = listSize + 1;
	// Remember our implementation of a heap
	// starts at 1 not zero, so we store a
	// nonce value, the empty string, at index 0.
	// Don't use the fact that "" is there, because
        // we want to support the empty string as a data, 
        // element.  Just remember index 0 is not used
	heap[0] = "";

	// copy the unsorted list over
	for (int i = 0; i < listSize; i++) {
		heap[i + 1] = list[i];
	}
	heapSize = listSize;

	// use the build heap function
	// to make it a heap
	buildHeap();
}

// doesn't really work
// as the upHeap function
// is not implemented as it
// is nearly the same as the
// down heap funciton

void Heap::insert(string s)
{
        // NB:  We don't use slot 0 in the array.
        // The array is thus already of size (heapSize + 1)
        // But we want to add one more element, so we
        // need an array of size (heapSize + 2)
        ensureCapacity(heapSize + 2);

	// location to insert is heapSize + 1
	// (Recall, 0th location not used)
	heap[heapSize + 1] = s;
	heapSize++;

	// heapsize points to index of last element now
	// reheap or upHeap to fix
	upHeap(heapSize);
}

/*
 * return smallest element in heap
 */
string Heap::min()
{
        // TODO:  your code here
}

/*
 * remove and return smallest element in heap
 */
string Heap::removeMin()
{

	
	for (int i = 0 ; i < heapsize ; i++){
	
		
	}
	// TODO: your code here

}

/*
 * return size of heap
 */
int Heap::size()
{
	return heapSize;
}

void Heap::downHeap(int location)
{
	if (leftChild(location) < heap [location]){
	
		if (rightChild(location) < leftChild(location)){
		
			int temp = rightChild(location);
			heap[location * 2 + 1] = heap[location];
			heap[location] = temp;

		}
	
		int temp1 = leftChild(location);
		heap[index*2] = heap[location];
		heap[location] = temp1;
	}
	
	
	// TODO: your code here

}

/*
 * not provided, as it is similar to downHeap.
 * write if you wish, but it is not mandatory for this lab.
 */
void Heap::upHeap(int location)
{
	(void) location; // Removes compiler warning about unused variable.
}

void Heap::buildHeap()
{

	// TODO: your code here

}

int Heap::leftChild(int index)
{
	return index * 2;
}

int Heap::rightChild(int index)
{
	return (index * 2) + 1;

}

int Heap::parent(int index)
{
	return index / 2;
}

/* 
 * Same as always:  make sure that heap array has at least
 * the desired capacity.
 */
void Heap::ensureCapacity(int desiredCapacity)
{
        if (maxCapacity >= desiredCapacity)
                return;  // Nothing to do:  array is big enough

        // otherwise, need to expand
        int     newCapacity = max(desiredCapacity, 2 * maxCapacity + 2);
        string *newArray    = new string[newCapacity];

        for (int i = 0; i < heapSize + 1; ++i)
                newArray[i] = heap[i];

        maxCapacity = newCapacity;
        delete [] heap;
        heap = newArray;
}
