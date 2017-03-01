// Hw4
// Alphabetizer.h : The header file declares all the function and 
// variables, no matter public or private, for  Alphabetizer.cpp
// Rui Qin
// 10/22/2016

#ifndef ALPHABETIZER_H
#define ALPHABETIZER_H

#include "StringBST.h"
#include <fstream>



class Alphabetizer
{

public:
        Alphabetizer();  // constructor
        ~Alphabetizer(); // destructor
        
        void run();
        //read string from command lines one by one 
        //as the user types, first the string for the mode, 
        //second then all the strings needed to sort. Then, 
        //print out the sorted strings in a format according 
        //to the mode the requriments
        
        void run(string filename, string order);
        //get the file name and using the stream to take them 
        //out to save into the binary tree. Then prints them out
        //as sorted according to the mode given and the format







private:
        StringBST BST1;
        //One instance of the StringBST class
        
        string mode;
        //the mode, "f" is the mode print out the string
        //from smallest to largest."r" prints out the mode
        //reversely
        
        void print_inOrder();
        //get min each time and prints out, then
        //deletes it. Processing until the binary
        //tree is empty
        
        void print_reversedOrder();
        //get max each time and prints out, then
        //deletes it. Processing until the binary
        //tree is empty
        
        void copy_strings_from(istream &infile);
        //Copy each string of non-whitespace characters from the 
        //given input stream onto standard output (cout), one string 
        //per line.





};


#endif