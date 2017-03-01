// CharSequence.h : The header file declares all the function and 
// variables, no matter public or private, for CharSequence.cpp
// Rui Qin
// 9/13/2016





#ifndef CHARSEQUENCE_H
#define CHARSEQUENCE_H
const int CAPACITY = 5; //The intial capacity of the sequence
const int ADDNUMBER = 1; //The increase value each time



class CharSequence
{
public:
        CharSequence(); // constructor
        CharSequence(char Achar); // consturctor with parameter
        ~CharSequence(); // destructor 
        bool isEmpty(); // This function decides wether the char sequence is empty
        int size(); // This function return number of characters in the sequence
        void clear(); // This function makes the sequence into an empty sequence
        
        void concatenate(CharSequence *anoherClass); // This functions add another sequence to the formal one
        
        char first(); // Return the first char of the sequence
        char last(); // Return the last char of the sequence
        char elementAt(int index); // Return the specific char of the index given by the user
        void print(); // Prints out all the char in the sequence
        

        
        void insertAtBack(char Achar); // Add one more char at the back of the sequence
        void insertAtFront(char Achar); // Add one more char at the front of the sequence 
        void insertAt(char Achar,int index); // Add one more char at specific place
        
        void removeFromFront(); // Remove the first char
        void removeFromBack(); // Remove the last char
        void removeFrom(int index); // Remove the char in specific position
        void replace(char Achar,int index);// Replace the char in specific position with a new one

        
        
private:
        char *charSequence; // the pointer points to the CharSequence
        int num_elements; // the exact number of elements in the sequence
        int capacity; // the size of the current CharSequence
        
        //The functions below are created by me
        void expand(int charadded); // Expand the sequence with more space and upgrade the capacity
        void expand1(int charadded); // Expand the sequence with more space and upgrade the capacity
        
        
        
};




#endif