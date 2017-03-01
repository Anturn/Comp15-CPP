// Proj2
// Node.h :  The header file declares all the function and 
// variables, no matter public or private, for  Node.cpp
// Rui Qin
// 11/16/2016

//General Guide:
//This is the class saving all the contents and providing
//some operations to traverse, find and print the strings
//by using the linked list, which each node consists of 
//the "data" struct

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

struct data {
        string word; //The string itself
        string low_word; //Lower case of the word
        int line;    //The line of this string is in
        int key;     //The hash code of the word
        string path; //The path for the file contains this string
        string wholeline; //All the strings one line
        vector<data*> A;  //An vector fo pointer points to "data" struct
        data* next; //The pointer points to the next "data" struct
        
	
};




class Node
{
public:

        Node();  //constructor
        ~Node(); //destructor

        
        void insertNode(string word,string newword,int index,int line,string path,string wholeline);
        //Insert the imformation into the vector of the class
        
        void search_show(string target_word);
        //Seearching the target word in the original case
        //and then print them out with all the imformation
        //used in the mode searching the original word
        void search_show_i(string newTarget);
        //Searching the target word in the lower case
        //and print them out with all the imformation
        //used in the mode searching the word in lower
        //case

        






private:
        data* head;
        //The head pointer points to the array of class
        void print(data* node);
        //print the imformation in the iright format






};








#endif