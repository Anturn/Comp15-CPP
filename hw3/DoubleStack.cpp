// DoubleStack.cpp : The .cpp file holds all the funcion declared in DoubleStack.h
// Rui Qin
// 9/13/2016

#include <iostream>
#include <stdexcept>
#include "DoubleStack.h"
using namespace std;



//This is the default constructor takes no parameters
//and initializes an empty sequence. It does not return
//anything.
DoubleStack::DoubleStack()
{
        head = -1;
        capacity = CAPACITY; //capacity initialized as constant CAPACITY
        
        num_double = 0;  
        // num_elements initialized as 0 since there is no 
        // char in the sequence
        
        doubleSequence = new double[CAPACITY]; 
        // create a sequence with specific size
        
}



//The second constructor takes an array of doubles and an
//integer specifying the size of the array as parameters and
//creates a stack initialized so that the elements of the array
//are on the stack with the array's element 0 pushed on first
//and it's (size - 1)st element at the top of the stack.
DoubleStack::DoubleStack(double array[],int size)
{
        
        head = -1;
        capacity = size; //capacity initialized as size
        
        num_double = 0;  
        // num_elements initialized as 0 since there is no 
        // char in the sequence
        
        doubleSequence = new double[size]; 
        
        for(int i = 0; i < size ; i++){
        
                doubleSequence[i] = array[i];
                head++;
                num_double++;
        }
        
}




//This is a destructor that destroys/deletes/recycles the
//heap-allocated data in the current sequence.
DoubleStack::~DoubleStack()
{
        delete[] doubleSequence;
}





bool DoubleStack::isEmpty()
{
        return(num_double == 0);
}



//clear()
//Purpose: It makes the sequence into an empty sequence
//Arguments:none
//Return:none
void DoubleStack::clear()
{
        head = -1;
        num_double = 0;
}


//size()
//Purpose: Decides how many char in the sequence
//Arguments:none
//Return:number of char in the sequence
int DoubleStack::size()
{
        return num_double;
}


//first()
//Purpose: Return the first char of the sequence, if it is empty
//then throws a exception
//Arguments:none
//Return:(char) the first char of the sequence
double DoubleStack::top()
{
        if (isEmpty()){
                throw runtime_error("empty_stack");
        }
        return doubleSequence[head];
}


//pop()
//purpose: It removes and returns the first element (double) 
//on the stack.If the stack is empty it throws a C++ "runtime_error" 
//exception with the message "empty_stack"
//Arguments:none
//Return:(double) the first element on the stack
double DoubleStack::pop()
{
        if(isEmpty()){
                throw runtime_error("empty_stack");
                
        }else{
        double A;
        A = doubleSequence[head--];
        num_double--;
        return A;
        }
}


//push()
//purpose: takes an element (double) and puts it on the top of the stack
//Arguments:none
//Return:none
void DoubleStack::push(double Adouble)
{
        ensureCapacity();
        doubleSequence[++head] = Adouble;
        num_double++;
        
        
}


//ensureCapacity()
//purpose: make sure there is enough space in the sequence
//Arguments:none
//Return:none
void DoubleStack::ensureCapacity()
{
        if(num_double <= capacity){
                return;
        }else{
                capacity = capacity*2;
                double* temp = new double[capacity];
                for(int i=0; i < num_double ; i++){
                
                        temp[i] = doubleSequence[i];
                }
                delete[] doubleSequence;
                doubleSequence = temp;

                
        }
}















