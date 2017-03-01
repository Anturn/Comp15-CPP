// Proj1
// PackStation.h : The header file declares all the function and 
// variables, no matter public or private, for PackStation.cpp
// Rui Qin
// 9/30/2016

#ifndef PACKSTATION_H
#define PACKSTATION_H
#include "Orderqueue.h"

//General Guide:
//This PackStation is the place to pack all the 
//Orders it is assigned.It has its own functions
//to count the total time of the current Order and
//the number of Order in the queue now.

//Relation with "FetchStation":
//There is a really important function 
//AddOrder(Order Aorder), it relates to the "FetchStation" 
//class which is the place to decide put Order in which 
//stations depending different mode. The PackStation is 
//the place to collect Order from upper level -- "FetchStation"
//class.

//The different PackStation receives different goods and
//count the time and size, return back those imformation.

//Include Orderqueue:
//It contain other class "Orderqueue" as member because the
//PackStation will also save Order in the queue in order to 
//further use and operate with the Order in the queue
class PackStation
{
        
public:
        
        PackStation(); // constructor
        ~PackStation();// destructor
        
        
        int getTime(); 
        //The total time of order currentlly in the queue
        int getItem();
        // The orders currentlly in the queue
        
        void AddOrder(Order Aorder); 
        // Enqueue a new Order into the queue
        
        void ReduceTime(int time_units); 
        //The time when the Order is processing 
        //in the FetchStation
        
        
private:
        Orderqueue queueStation; 
        //A new instance of Orderqueue class
        
        
        int currentTime;
        // The total time of order currentlly in the queue
        int currentItem;
        // The orders currentlly in the queue
        
        int totalTime;  
        // The total time of all orders being
        // processed
        
        int totalItem; 
        // The total items of all orders being
        // processed
        
        
        
        
        
};


#endif