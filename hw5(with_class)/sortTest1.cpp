// Hw5
// sortTest1.cpp : The file for testing all the functions in sortAlgs.cpp
// Rui Qin
// 10/30/2016


#include "sortAlgs.h"


int main()
{
        sortAlgs A1;
        
        //PASS
        //Those are all the cases that run successfully 
        //A1.run("s1","save");
        //A1.run("s1","print");
        //A1.run("s2","save");
        //A1.run("s2","print");
        //A1.run("s3","save");
        //A1.run("s3","print");
        
        
        //FAIL
        //Test case: wrong number of inputs
        //A1.run();       //no input
        //A1.run("save"); //one input
        //A1.run("s1");   //one input
        //The programm will terminate and give the message
        //tell that wrong number of inputs
        
        //FAIL
        //Test case: wrong inputs
        //A1.run("s5","save");
        //A1.run("s1","savve");
        //Both of the cases will terminate the program 
        //and give the abortion
        
        //PASS
        //Those are all the cases that run successfully 
        //A1.run("s1","save","text1.txt");
        //A1.run("s1","print","text1.txt");
        //A1.run("s2","save","text1.txt");
        //A1.run("s2","print","text1.txt");
        //A1.run("s3","save","text1.txt");
        //A1.run("s3","print","text1.txt");
        
        
        //FAIL
        //Test case: wrong filename/no such file
        //A1.run("s1","print","text");
        //A1.run("s1","print","text1232.txt");
        //The program will terminaye and cerr "Unable to open" because
        //there is no scuh file
        
        //FAIL
        //Test case, corner case: The program will first check the first 
        //two inputs, that is the: sorting mode and output method. If those are
        //already wrong, the program will just terminate and done not care
        //about the .txt name anymore. So program follows the sequence
        //A1.run("s8","print","text");
        //A1.run("s1","prit","text");
        
        
         






















}