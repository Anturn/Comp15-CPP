// Hw5

// sortAlgs.h : The header file declares all the function and 
// variables, no matter public or private, for  sortAlgs.cpp
// Rui Qin
// 10/30/2016

#ifndef SORTALGS_H
#define SORTALGS_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class sortAlgs
{
public:

        sortAlgs();  //constructor
        ~sortAlgs(); //destructor
        void run(string mode,string output);
        //run the programm with parameters
        void run(string mode,string output,string filename);
        //run the programm with three parameters










private:
        vector<int> vec;
        //a vector implrments with integers


        void which_alg(string mode);
        //Determing which mode is used among "s1","s2" and "s3"
        
        void which_output(string output,string origin,string mode);
        //Determing what kind of output
        
        string txtName(string origin,string mode,int number);
        //combining all the required elements to format the
        //txt name
        
        void insertionSort();
        //Insertion sort in Group 1
        
        
        void shellSort();
	//Shell sort in Group 2
        
        
        void quickSort(vector<int>& vec,int left, int right);
        //Quick sort in Group 2
        
        
        void copy_strings_from(istream &infile);
        //Copy each string of non-whitespace characters from the 
        //given input stream onto standard output (cout), one int 
        //per line.












};


#endif

