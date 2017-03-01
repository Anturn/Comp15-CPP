// Hw5
// sortTest1.cpp : The file for testing all the functions in sortAlgs.cpp
// Rui Qin
// 10/30/2016


#include "sortAlgs.h"


int main()
{
        
        
        //PASS
        //Those are all the cases that run successfully 
        //run("s1","save");
        //run("s1","print");
        //run("s2","save");
        //run("s2","print");
        //run("s3","save");
        //run("s3","print");
        
        
        //FAIL
        //Test case: wrong number of inputs
        //run();       //no input
        //run("save"); //one input
        //run("s1");   //one input
        //The programm will terminate and give the message
        //tell that wrong number of inputs
        
        //FAIL
        //Test case: wrong inputs
        //run("s5","save");
        //run("s1","savve");
        //Both of the cases will terminate the program 
        //and give the abortion
        
        //PASS
        //Those are all the cases that run successfully 
        //run("s1","save","text1.txt");
        //run("s1","print","text1.txt");
        //run("s2","save","text1.txt");
        //run("s2","print","text1.txt");
        //run("s3","save","text1.txt");
        //run("s3","print","text1.txt");
        
        
        //FAIL
        //Test case: wrong filename/no such file
        //run("s1","print","text");
        //run("s1","print","text1232.txt");
        //The program will terminaye and cerr "Unable to open" because
        //there is no scuh file
        
        //FAIL
        //Test case, corner case: The program will first check the first 
        //two inputs, that is the: sorting mode and output method. If those are
        //already wrong, the program will just terminate and done not care
        //about the .txt name anymore. So program follows the sequence
        //run("s8","print","text");
        //run("s1","prit","text");
        
        
         






















}