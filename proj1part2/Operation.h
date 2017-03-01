// Proj1
// Operation.h : The header file declares all the function and 
// variables, no matter public or private, for Operation.cpp
// Rui Qin
// 9/30/2016


#ifndef OPERATION_H
#define OPERATION_H

#include "Parser.h"
#include "FetchStation.h"

class Operation
{
        

public:

        Operation(string filename,int size,string Name);
        //Coustructor with parameters, which will initialize the
        //mode and the number of pack station. Meanwhile, it will 
        //also read in the string in the file and save all the 
        //information into the Order struct
        
        void run();
        //Get the size of the total order and 
        //loop through many times to take out an order
        //each time then deal with time and information
        //the struct has, and finally print out all the
        //information
                
                
        
        
private:
        
        Orderqueue AllOrder; 
        //an Orderqueue class
        int AllOrder_size = 0; 
        //The size of the queue which contains all
        //the orders read from the file
        
        int num_PS; 
        //number of Packing Station given by the user
        FetchStation FS; 
        //A FetchStation class with the number of pack stations 
        string ModeName;
        //The mode name given by the user
        
        void printOut(Order order1);
        //Take in a Order type and get all the time
        //information it saves and print out//
        
        void printResult();
        //print out the final result such as the
        //min,max and mean time and the total number of 
        //orders being processed
        
        int totalTime = 0;
        //The total time
        int min_elapsed_time = 2^15-1;
        //The minimum time
        //(A really big number initially to prevent the 
        // number it compared with is bigger than this value)
        int max_elapsed_time = -1;
        //The maximum time
        int mean_elapsed_time = 0 ;
        //The mean time
        
        void min_result(Order Aorder);
        //find out the minimum time of one order
        void max_result(Order Aorder);
        //find out the maximum time of one order
        void total_result(Order Aorder);
        //find out the total time of all orders
        void result(Order Aorder);
        //combine all the results above to get
        //the result
        
        
        
        
};



#endif


