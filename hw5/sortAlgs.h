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


        
        void insertionSort(vector<int> &vec);
        //Insertion sort in Group 1
        
        
        void shellSort(vector<int> &vec);
        //Shell sort in Group 2
        
        
        void quickSort(vector<int>& vec,int left, int right);
        //Quick sort in Group 2
        
        void quickSort_helper(vector<int>& vec,int left, int right);
        //Recursive version for quick sort, the helper function
        //for the quickSort function
     


#endif

