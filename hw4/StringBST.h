// Hw4
// StringBST.h : The header file declares all the function and 
// variables, no matter public or private, for StringBST.cpp
// Rui Qin
// 10/22/2016

#ifndef STRINGBST_H
#define STRINGBST_H
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

//The basic element as the function as 
//leaf in the binary tree.
struct treeNode
{
        string word;
        int time;
        treeNode *left,*right;
        
        treeNode(){
                    time = 0;
                    word = "";
                    left = NULL;
                    right = NULL;
        }
        
};



class StringBST
{
        
public:

        StringBST(); 
        //constructor
        
        StringBST(string array[] , int size); 
        //constructor with parameters
        
        ~StringBST(); 
        //destructor
        
        bool isEmpty(); 
        //decide whether the tree is empty
        
        void clear();
        //make the current tree into an empty tree
        
        int size();
        //number of strings in the binary tree
        
        void print();
        //print the binary tree in order
        
        void add(string element);
        //add the string to the binary tree in specific
        //location and will the times when encountering
        //duplicate elements
        
        bool remove(string element);
        //remove one target string from tree, if find one,
        //return true, if not then return false
        
        string getMin();
        //return the smallest string in the tree
        
        string getMax();
        //return the largest string in the tree
        
        void removeMin();
        //remove the smallest string in the tree
        
        void removeMax();
        //remove the largest string in the tree
        
        bool contains(string element);
        //whether the tree contains one element
        
        
private:
        
        treeNode* root;
        //the pointer points to the first element
        //of the tree
        
        
        void clear_helper(treeNode* leaf);
        //the recursive version to clear the tree used in
        //function clear()
        
        int size_helper(treeNode* leaf);
        //the recursive version to get how many elements
        //currently in the tree for the function size()
        
        void print_helper(treeNode* leaf);
        //the recursive version to print out the data in 
        //the tree for the function print()
        
        void add_helper(string element, treeNode* leaf);
        //recursive version to add an new element into the
        //tree for function add(string element)
        
        treeNode* remove_helper(string element, treeNode* leaf);
        //the recursive version to take a target (string) as
        //a parameter and returns a boolean. It will find the target 
        //and then proceed to remove one instance of it from the tree
        //for the function remove(string element)
        
        treeNode* getMin_helper(treeNode* leaf);
        //the recursive version to find out the smallest
        //string in the tree for the function getMin()
        
        treeNode* getMax_helper(treeNode* leaf);
        //the recursive version to find out the largest
        //string in the tree for the function getMax()
        
        void removeMin_helper();
        //using the function remove() and getMin()
        //to help find the smallest string and remove it
        
        void removeMax_helper();
        //the function remove() and getMax()
        //to help find the largest string and remove it
        
        bool contains_helper(string element, treeNode* leaf);
        //the recursive version to finds whether the target
        //string is in the tree for the function 
        //contains(string element)
    
   
        
        
        
        
        
        
        
        
        
        
        
        
};


#endif


