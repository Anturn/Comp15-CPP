// Proj1
// FetchStation.h : The header file declares all the function and 
// variables, no matter public or private, for FetchStation.cpp
// Rui Qin
// 9/30/2016


#ifndef FETCHSTATION
#define FETCHSTATION

#include "Order.h"
#include "PackStation.h"
using namespace std;

//General Guide:
//This FetchStation class is the place to take in Order
//from the queue which reads all the data from file and save
//them in queue. The Processing function takes one Order each 
//time, then collect the needed data -- time, finally decides
//which PackStation the Order will go depending on which mode 
//the user chooses

//Relation with "PackStation":
//The FetchStation is more like a upper level of PackStation,
//FetchStation will decide which PackStation is the right place
//to put the Order due to different mode. 

//Method behind:
//There are three different functions, each of which is the mode
//given by the user. The pressing()


class FetchStation
{

public:
        
        FetchStation();  // Constructor
        ~FetchStation(); // Destructor        
        
        
        void initialize(int Number);
        //Take the given nuber which is 
        //the number of Pack Station and initialize
        //an array of packstation class
        Order Processing(Order Aorder,string ModeName,int arriveTime);
        //The function takes in an Order each time and 
        //collect more data like pack_duration and fetch_duration
        //to do time operation
        
        
        
private:
        
        PackStation* ps; //The pointer points to the PackStation
        Order new_order; //The Order type varibal gets the order outside
        
        int Num_PS;        //The number of PackStation
        int processedItem; //The item being processed in FetchStation
        int FetchTime;     //The total time that orders already being fetched 
        
        void  Mode_ITEMS();
        //This mode checks each pack station and
        //find the one with least item and then add the 
        //order to that pack station
  
        void  Mode_TIME() ; 
        //This mode checks each pack station and
        //find the one with least time and then add the 
        //order to that pack station
  
        void  Mode_ROBIN(); 
        //This mode add the order in sequence

        void whichMode(string ModeName);
        //Easy function decides which mode will use depends on the
        //string given

        void waitingFS(int arriveTime);
        //Compare the arrive time with the total fetch time
        //that all the orders before it, if arrive time is bigger, 
        //the fetch station will wait until the order arrives. If 
        //the total ferch time is bigger, the order will wait until
        //all the orders are fetched
        
        int TimeCount();
        //Count all the time including fetch duration, pack duration
        //the time the order wait in the fetch station and pack station




        
        
        
};


#endif