// Proj1
// Orderqueue.h : The header file declares all the function and 
// variables, no matter public or private, for Orderqueue.cpp
// Rui Qin
// 9/30/2016





#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include "Order.h"

//General Guide:
//This class is really important because it is the
//place to save the Order in the queue and has a lot 
//of operations within which can be used in other class
//or functions easily to deal with the data in the queue


//Relation with "PackStation" and initially data implementions:
//At the beginning of the programm, the programm will read in 
//data (Order: struct type), the Orderqueue is the place to 
//save those initial generated data, which is easily operate due
//to its other useful functions. Meawhile, it has relation with
//PackStation class, which will also save the sorted Order in the 
//queue.

//Method behind:
//The class here is to make a queue and to add data by "Enqueue"
//and take out data by "Dequeue". The queue will also expand if 
//running out of space. It has one more important function 
//"traverse(int index)", which will return data saved in queue 
//depending on the given index




const int CAPACITY = 5; // The default capacity of the sequence


class Orderqueue
{
public:
	
	Orderqueue(); // constructor
	~Orderqueue(); // desctructor
	Orderqueue(int givenSpace); //constructor with parameters
	
	bool isEmpty(); // Decide whether the sequence is empty
	bool isFull();  // Decide whether the sequence is fulled
	void clear();   // Makes the current queue into a empty stack
	int  size();    // Return the size of the queue
	
	Order Dequeue(); // Removes the first Order of the queue and 
			 // returns it back
	
	void Enqueue(Order Aorder);  
	// Takes an Order and puts it back of the queue
	
	
private:
	
	Order* OrderQueue;
	// the pointer points to the Order struct
	
	int num_struct;
	// the total number of structs in the queue
	
	int capacity;
	// the total size of the current Orderqueue
	
	int head;
	//the index of struct that is the first moved into queue
	
	int tail;
	//the index of struct that is the last moved into queue
	
	
	void ensureCapacity();
	//make sure there is enough space for Order
	
	
	Order traverse(int index);
	//give a index and return a Order type in the queue
	
	
	
	
	
	
	
	
	
};






#endif