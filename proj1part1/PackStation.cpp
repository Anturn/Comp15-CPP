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



//setTime()
//Purpose: Count the total time of all the order
//currentlly in the queue
//Arguments:none
//Return:none
void PackStation::setTime()
{
	if(queueStation.isEmpty){
	
		currentTime = 0;
	}else{
	
		int size = currentItem;
		for(int i = 0; i < size; i++){
		
			currentTime = queueStation.traverse(i).pack_duration;
			/////////////////////////////////////////////////////
		}
	}
}


//getTime()
//Purpose:get the total time of all orders
//currentlly in the queue
//Arguments:none
//Return:(int)the total time
int getTime()
{
	setTime();
	return currentTime
	
}


//total_item()
//Purpose:get the total items currentlly in the queue
//Arguments:none
//Return:none
void PackStation::getItem()
{
	currentItem = queueStation.size();
}



//AddOrder(Order Aorder)
//Purpose:Enqueue a new Order into the queue
//Arguments: A order struct
//Return:none
void PackStation::AddOrder(Order Aorder)
{
	totalTime+=Aorder.pack_duration;
	totalItem++;
	queueStation.Enqueue(Aorder);
	
}



//ReduceTime(int time_units)
//Purpose:Reduce the time when the Order is processing 
//in the FetchStation
//Arguments:(int)the time Order spent in the FetchStation
//Return:none
void PackStation::ReduceTime(int time_units)
{
	currentTime-= time_units;
	if(currentTime <= 0)
		currentTime = 0;

}



















