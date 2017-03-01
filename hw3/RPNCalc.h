// Hw3
// RPNCalc.h : The header file declares all the function and 
// variables, no matter public or private, for RPNCalc.cpp
// Rui Qin
// 9/23/2016

#ifndef RPNCalc_H
#define RPNCalc_H
#include "DoubleStack.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdexcept>


using namespace std;


class RPNCalc
{
public:
        RPNCalc(); // constructor
        ~RPNCalc(); // destructr
        
        void run(); // o a number causes the number to be placed on the stack
                    // o an operator, which is one of the "+", "-", "*", or "/"
                    // causes the top two elements to be popped off the stack, the
                    // operation to be performed on them (addition, subtraction,
                    // multiplication, or division) in the same order as dc, and
                    // the result to be pushed on the top of the stack.
                    // Note:  The result does NOT print.
                    // o "p" or "P" prints the value on the top of the stack.
                    // o "c" or "C" clears the calculator, emptying the stack.
                    // o "f" or "F" followed by the name of a file causes the
                    // contents of the named file to be read and processes as if
                    // they had been typed into the command loop.  If the file
                    // cannot be opened or read, the message "Unable to read
                    // filename\n" (where "filename" is replaces with the name of
                    // the file specified in the command) is printed to cerr.  The
                    // program does not crash or throw an exception.
                    // The command loop then continues reading data from cin.
                    // o "q", which quits the calculator.
                    // o For any other input, echo the offending input and print
                    // ":  unimplemented\n" on cerr.  E. g., "x:  unimplemented"
                    // Then continue accepting input.
        
        
       
private:
        DoubleStack Stack1; 
        //Make a instance of the DoubleStack class called 
        //Stack1
        
        double fir,sec; 
        //The variable used in swap function in order to change 
        //the order of the double poped out
        
        
        string commands1;
        //The commands1 the user or read from txt file, including 
        //string, operations,double and .txt, etc
        
        void run1();
        //run the whole programm and main function is to 
        //receive the input command and execute correspoonding 
        //operation depending on the command given,this is the
        //truncated part from run() function, which contains all 
        //corresponding execution depends on the commands given
        
        
        bool isContinue;
        //The condition decides the while() loop in run() 
        //function whether continues
        
        bool operatorCommand(string command); 
        //If the command is one of the operations, it will run and operate
        //and return true, otherwise, it means the command is not one of 
        //the operations
        
        void swap(); 
        //Make the sequence of the two doubles poped out swap the 
        //order in order to operate properly
        
        
        void toLowerCase(string& Astring); 
        //Transfer the upper string to the lower case one
        
        
        bool got_double(string s, double *resultp); 
        //Decide whether the string is a double number
        //and transfers the string to double and assign 
        //it to another variable
        
        void read_file(); 
        //Read the file user give, including the double and operations normally
        
        void read_file(string Astring);
        //The read file with parameters.Not read input from user
        //anymore,but take the existed string in the txt file as input
        
        void copy_strings_from(istream &infile); 
        //Copy each string of non-whitespace characters from the given 
        //input stream onto standard output (cout), one string per line.
};







#endif