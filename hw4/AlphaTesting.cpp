// Hw4
// AlphaTesting.cpp : The file for testing all the functions in Alphabetizer.cpp
// Rui Qin
// 10/26/2016

#include "Alphabetizer.h"

int main()
{
          //Test for the run(), which will run the  "interactive" mode,
          //which user manually type in the words and the mode, then the 
          //read in the "f" and "r" two different mode be executed and the 
          //strings, then prints out the sorted strings. The function will
          //give error messages and end up the programm when given wrong
          //messages not "f" or "r"
          
          //Alphabetizer A;
          //A.run();
          
          //I comment them after testing
          
          
          
          
          //Test for the run(string filename, string order). First, ask for
          //the mode and filename from the user and then run the programm then
          //prints out the sorted strings. Because the main.cpp will check the
          //readability of the input from the command line, so there are no 
          //check here
          string mode;
          string filename;
          
          cout << "Please give the mode, \"f\" or \"r\" " <<endl;
          cin >> mode;
          cout << "Please give a file, normally with the form .txt" <<endl;
          cin >> filename;
          
          Alphabetizer B;
          B.run(filename,mode);
          
          
          
          return 0;





}