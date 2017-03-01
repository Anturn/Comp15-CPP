// Proj1
// FetchStation.h : The header file declares all the function and 
// variables, no matter public or private, for FetchStation.cpp
// Rui Qin
// 9/30/2016


#ifndef FETCHSTATION
#define FETCHSTATION



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
	
	void Prcessing(Order Aorder);
	//The function takes in an Order each time and 
	//collect more data like pack_duration and fetch_duration
	//to do time operation
	
	void whichMode(string ModeName);
	//Easy function decides which mode will use depends on the
	//string given
	
	
	
	
private:
	
	int totalTime; //The 

	void Mode_ITEMS(); //FEWEST_ITEMS mode
	void Mode_TIME();  //SHORTEST_TIME
	void Mode_ROBIN(); //ROUND_ROBIN






	
	
	
};


#endif