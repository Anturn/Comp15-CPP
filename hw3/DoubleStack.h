// Hw3
// DoubleStack.h : The header file declares all the function and 
// variables, no matter public or private, for DoubleStack.cpp
// Rui Qin
// 9/23/2016

#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H
const int CAPACITY = 5; // The default capacity of the sequence




class DoubleStack
{
public:
        DoubleStack(); // constructor
        DoubleStack(double array[],int size); // constructor with parameters
        ~DoubleStack(); // desctructor
        
        bool isEmpty(); // Decide whether the data is empty
        void clear(); // Makes the current stack into a empty stack
        int  size(); // Return the size of the stack
        double top(); // Return the top element on the stack
        double pop(); // Removes the first element on the stack
        
        void push(double Adouble); 
        // Takes an element and puts it on the top of the stack
        
private:
        double* doubleSequence; 
        // the pointer points to the DoubleStack
        
        int num_double; 
        // number of double on the stack
        
        int capacity;   
        // the total size of the current CharSequence
        
        int head;       
        // the index of string that is the last moved into stack
        
        void ensureCapacity(); 
        // Always make sure there is enough space for double

        
        
        
        
        
        
};


#endif