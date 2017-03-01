// Proj2
// hashTable.h : The header file declares all the function and 
// variables, no matter public or private, for  hashTable.cpp
// Rui Qin
// 11/16/2016

//General Guide:
//This class includes the "Node.h" file and "FSTree.h" file, 
//while is the class saves all the strings. meanwhile it
//has two important funtions in public, the first one "run1()"
//is the function query the command from the user, the
//other one "run1()" is the function which try to find
//path of the corrent file given a pointer points to  
//a directory Node
//In all, the class here is the place:
//1.ask the command, query from the user
//2.given a pointer points to a directory and save
//all the files and directories into a tree
//3.collect all the words from all available files
//and save them into the array, which also will
//call the "Node.cpp" to save them
//4.Search for the target word through calling the
//operation from "Node.cpp" class
//5.Print out all the words that user asks
//6.Repeating Query until user quits the programm



#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

#include "FSTree.h"
#include "Node.h"

const int VECTORSIZE = 1000;
//The fixed size of the hash table

class hashTable
{
public:
        hashTable();  
        //Constructor
        
        ~hashTable(); 
        //Destructor
        
        void run(DirNode* leaf,string prefix);
        //First find out whether there are directories or files
        //in the source directory.Then find the files and print them all
        //out, find the directory run the programm again by recursion.
        
        void run1();
        //Collect the imformation from the command line
        //and ask the user the specific command to run next
        
        



private:

        
        Node* vec; 
        //This is the vector hash table with the number of
        //the original word
        Node* vec1;
        //This is the vector hash table with the number of 
        //the lower case word
	
        
        string parent_name(DirNode* leaf);
        //Find out all the parent directory given a single file 
        
        void read(string filename,string path);
        //read in a file and prepare to take out all the words
        //in it 
        
        void copy_strings_from(istream &infile,string path);
        //Copy each string of non-whitespace characters from the 
        //given input stream onto standard output (cout), one int 
        //per line.
        
        void insert(string word,int line,string path,string wholepath);
        //Insert a new word into a hash table with all the imformation required
        
        int hash(string word);
        //Transform a strong into a number as an index
        
        string toLC(string word);
        //Transfer a word into a lower case one
        
        void mode(string target);
        //This is the mode that looks for the original word 
        
        void mode_i(string target);
        //This is the mode that looks for insensitive word also
        
        
        


};

#endif
