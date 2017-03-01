// Proj1
// Orderqueue.cpp : The .cpp file holds all the funcion declared in Orderqueue.h
// Rui Qin
// 9/30/2016

#include <iostream>
#include <stdexcept>
#include "Orderqueue.h"
using namespace std;


//This is the default constructor takes no parameters
//and initializes an empty sequence. It does not return
//anything.
Orderqueue::Orderqueue()
{
	head = 0;
	tail = 0;
	num_struct = 0;
	// num_struct initialized as 0 since there is no 
        // Order in the sequence
	
	capacity = CAPACITY; //capacity initialized as constant CAPACITY
	OrderQueue = new Order[capacity];
	// create a sequence with specific initial size
	
	
	
}

//This is the default constructor with parameters
//and initializes an empty sequence with a specific size. 
//It does not return anything.
Orderqueue::Orderqueue(int givenSpace)
{
	head = 0;
	tail = 0;
	num_struct = 0;
	// num_struct initialized as 0 since there is no 
        // Order in the sequence
	
	capacity = givenSpace; //capacity initialized as constant CAPACITY
	OrderQueue = new Order[capacity];
	// create a sequence with specific size
	
	
	
}







//This is a destructor that destroys/deletes/recycles the
//heap-allocated data in the current sequence.
Orderqueue::~Orderqueue()
{
	delete[] OrderQueue;
}


//isEmpty()
//Purpose: It decides whether the sequence is empty
//Arguments: none
//Return:(boolean)true if the sequence is empty, false if not
bool Orderqueue::isEmpty()
{
        return(num_struct == 0);
}


//isFull()
//Purpose: It decides whether the sequence is fulled
//Arguments: none
//Return:(boolean)true if the sequence is fulled, false if not
bool Orderqueue::isFull()
{
	return(num_struct==capacity);
}




//clear()
//Purpose: It makes the sequence into an empty sequence
//Arguments:none
//Return:none
void Orderqueue::clear()
{
        head = 0;
       	tail = 0;
        num_struct= 0;
}


//size()
//Purpose: Decides how many Order in the sequence
//Arguments:none
//Return:number of Order in the sequence
int Orderqueue::size()
{
        return num_struct;
}

//Dequeue()
//Purpose: Removes the first Order of the queue and
//returns it back
//Arguments: none
//Return:(Order)the first Order of the queue
Order Orderqueue::Dequeue()
{
	if(isEmpty()){
	
		throw runtime_error("empty_stack");
	}else{
		Order Aorder;
		Aorder = OrderQueue[head];
		head = (head+1)%capacity;
		num_struct--;
		return Aorder;
	}
	
}

//Enqueue()
//purpose: takes an element (Order) and puts it at the back of the queue
//Arguments:none
//Return:none
void Orderqueue::Enqueue(Order Aorder)
{
	ensureCapacity();
	OrderQueue[tail] = Aorder;
	tail = (tail+1)%capacity;
	num_struct++;
}

//ensureCapacity()
//purpose: make sure there is enough space in the queue
//Arguments:none
//Return:none
void Orderqueue::ensureCapacity()
{
	if(!isFull()){   /////////////////////////
		return;
		
	}else{
	
		Order* temp = new Order[capacity*2];
		for(int i = 0; i < capacity;i++){
		
			temp[i] = OrderQueue[(head+i)%capacity];
		}
		delete[] OrderQueue;
		OrderQueue = temp;
		head = 0;
		tail = num_struct;
		capacity*=2;
		
	}
}





//traverse()
//Porpose:give a index and return the Order in the queue
//Arguments:(int)the index 
//Return:(Order)a Order in the queue
Order Orderqueue::traverse(int index)
{
	return OrderQueue[(head+index)%capacity];
	
	
	
	
}



















