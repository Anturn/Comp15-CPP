// Proj1
// FetchStation.cpp : The .cpp file holds all the funcion declared in FetchStation.h
// Rui Qin
// 9/30/2016

#include <iostream>
#include "FetchStation.h"
using namespace std;





void FetchStation::whichMode(string ModeName)
{
	if (ModeName == "FEWEST_ITEMS")
		Mode_ITEMS();
	else if (ModeName == "SHORTEST_TIME")
		Mode_TIME();
	else if(ModeName == "ROUND_ROBIN")
		Mode_ROBIN();
	
	
}





void FetchStation::Mode_TIME()
{
	
	
	
	
	
	

}


void FetchStation::Mode_ITEMS()
{
	
	
	
	
	
	

}


void FetchStation::Mode_ROBIN()
{
	
	
	
	
	
	


}








void Prcessing(Order Aorder)
{
	int timeConsuming = Aorder.fetch_duration;
	for(int i = 0 ; i < units; i ++){
		
	}
	

}
















