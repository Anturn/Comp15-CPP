// Proj1
// PackStation.cpp : The .cpp file holds all the funcion declared in PackStation.h
// Rui Qin
// 9/30/2016

#include <iostream>
#include "PackStation.h"
using namespace std;



//Constructor which will set the initial time and
//number of items to 0 
PackStation::PackStation()
{
        totalTime = 0;
        totalItem = 0;
        
        currentTime = 0;
        currentItem = 0;
}

//Destructor without any operation
PackStation::~PackStation()
{

}


//getTime()
//Purpose:get the total time of all orders
//currentlly in the queue
//Arguments:none
//Return:(int)the total time
int PackStation::getTime()
{
        return currentTime;
        //Get the current time
        
}


//total_item()
//Purpose:get the total items currentlly in the queue
//Arguments:none
//Return:none
//Supplement: This function here count how many orders
//will be processed, including the order is being processed
//It use the total time reduces the current time, we then 
//get the time spent on the orders which are already processed.
//We then dequeue the orders in the station one by one, until
//the time is equal, then we know how many items in the station
int PackStation::getItem()
{
        int size = totalItem;
        int processedTime=0;
        int processedItem=0;
        processedTime = totalTime - currentTime;
        if(size ==0){
                return 0;
        }
        int i = 0;
        int time = queueStation.traverse(i).pack_duration;
        processedItem = 1;
        while(processedTime > time){
                processedItem++;
                i++;
                time+=queueStation.traverse(i).pack_duration;
     
        }
        if(time > processedTime){
                return size - processedItem +1;
        }
        return size - processedItem;
        

}



//AddOrder(Order Aorder)
//Purpose:Enqueue a new Order into the queue
//Arguments: A order struct
//Return:none
void PackStation::AddOrder(Order Aorder)
{
        totalTime+=Aorder.pack_duration;
        //The total time of all the orders that 
        //in PackStation
        currentTime+=Aorder.pack_duration;
        //The time that current order being processed
        totalItem++;
        //All the orders in PackStation
        queueStation.Enqueue(Aorder);
        //Enqueue that order
        
}



//ReduceTime(int time_units)
//Purpose:Reduce the time when the Order is processing 
//in the FetchStation
//Arguments:(int)the time Order spent in the FetchStation
//Return:none
void PackStation::ReduceTime(int time_units)
{
        currentTime-= time_units;
        //The current time should reduce the time 
        //the order being fetched in the FetchStation
        if(currentTime <= 0)
                currentTime = 0;
        //If the current time is smaller or equal to
        //0, taht means there is no order in  this
        //FetchStation, thus the current time should be 
        //0
   

}



















