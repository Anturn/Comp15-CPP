// Hw4
// BSTTtesting.cpp : The file for testing all the functions in StringBST.cpp
// Rui Qin
// 10/26/2016

#include "StringBST.h"


int main()
{
        
        //Testing for constructor with parameters to initialize
        //the binary tree
        cout << "We have an array of strings ";
        cout << "A[] = {\"daad\",\"a\",\"apple\",\"cat\"} " <<endl;
        cout << "and an instance of StringBST called BST1 by using";
        cout << "the constructors" << endl;
        cout << "with parameters StringBST BST1(A,4) ";
        cout << "We then prints out the sorted outcome:" << endl;
        
        string A[] = {"daad","a","apple","cat"};
        StringBST BST1(A,4);
        BST1.print();
        //The sorted outcome should be a apple cat daad

        //Generating an instance of StringBST class, using
        //the constructor without any parameters. We get an
        //empty tree now
        cout << "\nGenerating an instance of StringBST class, using";
        cout << "the constructor without any parameters: StringBST BST2 " ;
        cout << endl;
        StringBST BST2;

        //Test for isEmpty() function by using empty tree
        cout << "Because the tree is empty now, so the function isEmpty() ";
        cout << "will return true that is:  ";
        cout << BST2.isEmpty() << endl;
        //Now the tree is just initialized, should be empty.
        //So the BST.isEmpty() should be true
        
        //Test for size() function by using empty tree
        int size_BST2 = BST2.size();
        cout << "The size of the empty tree should be 0 by calling the";
        cout << "function size(), the size is actually: " << size_BST2 << endl;
        //The tree now is empty, so the size of the tree is
        //0
        
        //Test for print() and clear() function by using empty tree
        cout << "Because there is nothing here, just print out the bracket:\n"; 
        BST2.print();
        BST2.clear();
        //For this two functions, because there are no strings
        //in the tree, so nothing is printed out,just the bracket and nothing 
        //get cleared

        //Test for removeMin() and removeMax() function by using empty tree
        BST2.removeMin();
        BST2.removeMax();
        //For two remove functions, because there nothing in the tree,
        //there is nothing to be removed
        
        //Test for getMin() function by using empty tree
        //BST2.getMin();
        //For getMin(), because there is nothing in the tree, the function
        //will give an abortion. I conmments it prevent it stop the programm

        //Test for getMax() function by using empty tree
        //BST2.getMax();
        //For getMax(), because there is nothing in the tree, the function
        //will give an abortion. I conmments it prevent it stop the programm
        
        //Test for remove(string element) function by using empty tree
        cout << "\nShould returen a false, because there is no \"a\" " ;
        cout << "in the tree ";
        cout << "And the actual output is: " <<  BST2.remove("a") <<endl;
        //Because this is an empty tree, there is nothing in it. The remove()
        //function should return a false that is 0
        
        //Test for contains(string element) function by using empty tree
        cout << "Should return a false, because there is nothing in the tree ";
        cout << "so the contains() function ";
        cout << "should return 0, and the actual output is: " ;
        cout << BST2.contains("E") << endl;
        
        //Test for add(string element) function 
        BST2.add("Ram");
        BST2.add("Horse");
        BST2.add("Swan");
        BST2.add("Deer");
        BST2.add("Kingfisher");
        BST2.add("Llama");
        BST2.add("Bison");
        BST2.add("Horse");
        BST2.add("Swan");
        BST2.add("Swan");
        BST2.add("Deer");
        BST2.add("Deer");
        BST2.add("Deer");
        BST2.add("Llama");
        
        //Test for print() function 
        BST2.print();
        //Add the words given by the sheet randomly, and prints them out
        //There are in the sequence from smallest to the largest
        
        //Test for isEmpty() function
        cout << "\nThere are in total 14 strings in the tree, so the tree is ";
        cout << "not empty, the output is false, should be 0";
        cout << "and the actual output is: ";
        cout << BST2.isEmpty() << endl;
        
        //Test for size() function
        cout << "The size of the tree is: " << BST2.size() << endl;
        //The size here should be 14 because there are in total 14 strings
        //being added into the tree
        
        ///////////////////////////////////////////////////////////////////
        //Test for removeMin(), getMin() and print()  function
        cout << "The smallest string in the tree by calling the function ";
        cout << "getMin() now is: " << BST2.getMin() << endl;
        BST2.removeMin();
        BST2.print();
        //The Bison is the smallest, so it is deleted. 
        
        cout << "\nThe smallest string in the tree by calling the function ";
        cout << "getMin() now is: " << BST2.getMin() << endl;
        BST2.removeMin();
        BST2.print();
        //The Deer is the smallest, but there are 4 "Deer" in the tree now,
        //so just one of them, there are still Deer left
        ///////////////////////////////////////////////////////////////////
        
        ///////////////////////////////////////////////////////////////////
        //Test for removeMax(), getMax() and print()  function
        cout << "\nThe largest string in the tree by calling the function ";
        cout << "getMax() now is: " << BST2.getMax() << endl;
        BST2.removeMax();
        BST2.print();
        //The Swan is the largest, but there are 3 "Deer" in the tree now,
        //so just one of them, there are still 2 Deer left 
        
        cout << "\nThe largest string in the tree by calling the function ";
        cout << "getMax() now is: " << BST2.getMax() << endl;
        BST2.removeMax();
        BST2.print();
        //The Swan is the largest, but there are 2 "Deer" in the tree now,
        //so just one of them, there are still 1 Deer left
        

        cout << "\nThe largest string in the tree by calling the function ";
        cout << "getMax() now is: " << BST2.getMax() << endl;
        BST2.removeMax();
        BST2.print();
        //The Swan is the largest, but there are 1 "Deer" in the tree now,
        //so just one of them, there are still no Deer left
        
        cout << "\nThe largest string in the tree by calling the function ";
        cout << "getMax() now is: " << BST2.getMax() << endl;
        BST2.removeMax();
        BST2.print();
        //The Ram is the largest, so it is deleted and no Ram left
        /////////////////////////////////////////////////////////////////////
        
        
        cout << "\nThe size of the tree now is: " << BST2.size() <<endl;
        //Now the size should be 8, because there are 6 strings are removed
        
        cout << "Because there is no 'Bison' in the tree now, so ";
        cout << "the remove(\"Bison\") function will returen false, ";
        cout << "the output is: " << BST2.remove("Bison") <<endl;
        //We cannot remove Bison now beacause there is no Bison in the tree 
        //now, so the function will return false
        
        cout << "We using the remove(\"Kingfisher\") to remove string";
        cout << "we then print them out: " <<endl;
        BST2.remove("Kingfisher");
        BST2.print();
        //We remove a string in the tree, because there is only one string
        //so it is just deleted
       
        //////////////////////////////////////////////////////////////////////
        cout << "\nWe using the contains(\"Ray\"), because there is no ";
        cout << "\"Ray\" in the";
        cout << "tree, so it will return false, that is: ";
        cout <<BST2.contains("Ray") << endl;
        //Because there is not "Ray" in the tree, so the function will return 
        //false
        
        cout << "We using the contains(\"Horse\"), because there is no ";
        cout << "\"Horse\" in the tree, so it will return false, that is: ";
        cout <<BST2.contains("Horse") << endl;
        //Because there is not "Ray" in the tree, so the function will return 
        //false
        //////////////////////////////////////////////////////////////////////
        
        BST2.clear();
        BST2.isEmpty();
        cout << "We use clear() function to clear the tree and delete the "; 
        cout << "whole strings,";
        cout << "and we use the isEmpty() to decide whether the tree is empty";
        cout << "and the size of the tree now is: " << BST2.size() << endl;
        
        
        
}





