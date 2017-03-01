// Proj1
// FetchStation.cpp : The .cpp file holds all the funcion declared in FetchStation.h
// Rui Qin
// 9/30/2016

#include <iostream>
#include "FetchStation.h"


//constructor: Initialize the Number of
//pack stations and the total fetching time 
//and the total number of items that being 
//processed
FetchStation::FetchStation()
{
        Num_PS = 0;
        processedItem = 0;
        FetchTime = 0;
}

//desctructor: Do not contain anything 
FetchStation::~FetchStation()
{
}



//initialize(int Number)
//Purpose: Take the given nuber which is 
//the number of Pack Station and initialize
//an array of packstation class
//Arguments:(int)number of pack stations
//Return:none
void FetchStation::initialize(int Number)
{
        ps = new PackStation[Number];
        Num_PS = Number;
}




//whichMode(string ModeName)
//Purpose:A simple function decides which mode
//is gonna be used
//Arguments:(string)The mode name given
//Return:none
void FetchStation::whichMode(string ModeName)
{
        if (ModeName == "FEWEST_ITEMS"){
                Mode_ITEMS();
        }else if (ModeName == "SHORTEST_TIME"){
                Mode_TIME();
        }else if(ModeName == "ROUND_ROBIN"){
                Mode_ROBIN();
        }
        
}




//Mode_TIME()
//Purpose:This mode checks each pack station and
//find the one with least time and then add the 
//order to that pack station
//Arguments:none
//Return:none
void FetchStation::Mode_TIME()
{
        int PS_index = 0;
        int time = ps[0].getTime();
 
        for(int i=1 ; i < Num_PS ; i++){
                if(ps[i].getTime() < time){
                        time = ps[i].getTime();
                        PS_index = i;
                }
        }
        //The loop here finds out the PackStation with
        //the shortest time
        for(int j=0 ; j < Num_PS ; j++){
                ps[j].ReduceTime(new_order.fetch_duration);
        }
        //The loop here reduce the fetch duration of the
        //order because all the PackStation will
        //wait that much time until the next order get 
        //fetched
        
        new_order.PS_waitingTime = ps[PS_index].getTime();
        //How much time the order will wait in the PackStation
        //until it can be packed
        ps[PS_index].AddOrder(new_order);
        //Finally,add the pack_duration of the order into that 
        //specific PackStation
        
        
        
        
}

//Mode_ITEMS()
//Purpose:This mode checks each pack station and
//find the one with least item and then add the 
//order to that pack station
//Arguments:none
//Return:none
void FetchStation::Mode_ITEMS()
{
        int PS_index = 0;
        int item = ps[0].getItem();
        for(int i=1 ; i < Num_PS ; i++){
                if(ps[i].getItem() < item){
                        item = ps[i].getItem();
                        PS_index = i;
                }
        }
        //The loop here finds out the PackStation with
        //the fewest items
        
        for(int j=0 ; j < Num_PS ; j++){
                ps[j].ReduceTime(new_order.fetch_duration);
        }
        new_order.PS_waitingTime = ps[PS_index].getTime();
        ps[PS_index].AddOrder(new_order);
        
        
        
        
        
        

}

//Mode_ROBIN()
//Purpose:This mode add the order in sequence
//Arguments:none
//Return:none
void FetchStation::Mode_ROBIN()
{
        int PS_index;
        PS_index = processedItem % Num_PS;
        
        //By using the modulus, we can deliver the
        //order by sequence
        
        for(int j=0 ; j < Num_PS ; j++){
                ps[j].ReduceTime(new_order.fetch_duration);
        }
        
        new_order.PS_waitingTime = ps[PS_index].getTime();
        ps[PS_index].AddOrder(new_order); 

}




//Processing(Order Aorder,string ModeName)
//Purpose:Take the order in, run the whichMode() function
//with parameters given and add one to the variable
//processedItem to keep tracking the number of orders being 
//processed
//Argument:(Order)the order given,(string)the mode name
//Return:none
Order FetchStation::Processing(Order Aorder,string ModeName,int arriveTime)
{
        new_order = Aorder;  
        //Private variable get the value in
        //order to use it in the whole class
        whichMode(ModeName);
        //Decide which mode is gonna be used
        
        processedItem++;
        //How many items being processed, which will be used
        //in mode ROBIN
        waitingFS(arriveTime);
 
        new_order.total_time = TimeCount();
        //Get the total time
        FetchTime+=new_order.fetch_duration;
        //The time that the fetch_station spend on 
        //orders which are already processed
        return new_order;
 
        
}


//waitingFS()
//Purpose:Compare the arrive time with the total fetch time
//that all the orders before it, if arrive time is bigger, 
//the fetch station will wait until the order arrives. If 
//the total ferch time is bigger, the order will wait until
//all the orders are fetched
//Arguments:none
//Return:none
void FetchStation::waitingFS(int arriveTime)
{
        int arrivalTime = new_order.arrival_timestamp;
        if(arrivalTime <= FetchTime){
        
                new_order.FS_waitingTime = FetchTime-arrivalTime+arriveTime;
        }else{
        
                new_order.FS_waitingTime = 0 ;
        }
        
}



//TimeCount()
//Purpose:Count all the time including fetch duration, pack duration
//the time the order wait in the fetch station and pack station
//Arguments:none
//Return:none
int FetchStation::TimeCount()
{
        int totalTime;
        totalTime = new_order.FS_waitingTime + new_order.fetch_duration +
        new_order.pack_duration  + new_order.PS_waitingTime;
        //The total time consists with four seperate time
        return totalTime;
}















