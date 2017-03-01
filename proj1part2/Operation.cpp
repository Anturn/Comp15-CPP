// Proj1
// Operaion.cpp : The .cpp file holds all the funcion declared in Operation.h
// Rui Qin
// 9/30/2016

#include <iostream>
#include <stdexcept>
#include "Operation.h"
using namespace std;



//Coustructor with parameters, which will initialize the
//mode and the number of pack station. Meanwhile, it will 
//also read in the string in the file and save all the 
//information into the Order struct
Operation::Operation(string filename,int size,string Name)
{
        
        num_PS = size;
        FS.initialize(num_PS);
        ModeName = Name;
        Parser p(filename);
        
        while(!p.is_done()){
        
                Order order = p.read_order();
                AllOrder.Enqueue(order);
        }
}


//run()
//Purpose:Get the size of the total order and 
//loop through many times to take out an order
//each time then deal with time and information
//the struct has, and finally print out all the
//information
//Arguments:none
//Return:none
void Operation::run()
{
        
        AllOrder_size = AllOrder.size();
        int arriveTime = AllOrder.traverse(0).arrival_timestamp;
        for(int i=0;i<AllOrder_size;i++){
                Order A = AllOrder.Dequeue();
                if(i==0)
                        A = FS.Processing(A,ModeName,0);
                else 
                        A = FS.Processing(A,ModeName,arriveTime);
                
        result(A);
        //Collect the data about time
        printOut(A);
        //Print out every single order's imformation
                
        }
        printResult();
        //Print out the final result
        
}



//orintOut(Order order1)
//Purpose:Take in a Order type and get all the time
//information it saves and print out
//Arguments:(Order)A new order
//Return:none
void Operation::printOut(Order order1)
{
        
        int id = order1.id;
        int arrival_timestamp = order1.arrival_timestamp;
        int fetch_duration = order1.fetch_duration;
        int pack_duration = order1.pack_duration;
        int total_time = order1.total_time;
        cout<< "<Order(" << id << ") arrival_timestamp = "<< arrival_timestamp;
        cout<< " fetch_duration = " << fetch_duration << " pack_duration = ";
        cout<< pack_duration << " total_time = " << total_time << ">" << endl;
        
        
}


//printResult()
//Purpose:print out the final result such as the
//min,max and mean time and the total number of 
//orders being processed
//Arguments:none
//Return:none
void Operation::printResult()
{
        cout << "min elapsed time " << min_elapsed_time << " minutes" <<endl;
        cout << "max elapsed time " << max_elapsed_time << " minutes" <<endl;
        cout << "mean elapsed time "<< mean_elapsed_time << " minutes"<<endl;
        cout << AllOrder_size << " orders processed" << endl;
        
}





//min_result(Order Aorder)
//Purpose:find out the minimum time of one order
//Arguments:(Order)one order type as Order
//Return:none
void Operation::min_result(Order Aorder)
{
        if(Aorder.total_time <= min_elapsed_time){
        
                min_elapsed_time = Aorder.total_time;
        
        }
        
        
}



//max_result(Order Aorder)
//Purpose:find out the maximum time of one order
//Arguments:(Order)one order type as Order
//Return:none
void Operation::max_result(Order Aorder)
{
        if(Aorder.total_time >= max_elapsed_time){
        
                max_elapsed_time = Aorder.total_time;
        
        }
        
        
}


//total_result(Order Aorder)
//Purpose:find out the total time of all orders
//Arguments:(Order)one order type as Order
//Return:none
void Operation::total_result(Order Aorder)
{
        totalTime+=Aorder.total_time;
}



//result(Order Aorder)
//Purpose:combine all the results above to get
//the result
//Arguments:(Order)one order type as Order
//Return:none
void Operation::result(Order Aorder)
{
        min_result(Aorder);
        max_result(Aorder);
        total_result(Aorder);
        mean_elapsed_time = totalTime/AllOrder_size;
}





