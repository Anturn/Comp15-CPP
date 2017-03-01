// Hw2
// CharLinkedList : The header file declares all the function and 
// variables, no matter public or private, for CharLinkedList.cpp
// Rui Qin
// 9/16/2016

#ifndef CHARLINKEDLIST_H
#define CHARLINKEDLIST_H

//struct node fot CharLinkedList
struct Node
{
        char info; // The char saved 
        Node *next; // The pointer points to the next node
        Node *prev; // The pointer points to the prveious node
};







class CharLinkedList
{
        public:
                CharLinkedList(); // constructor
                CharLinkedList(char Achar); // consturctor with parameter
                ~CharLinkedList(); // destructor 
                bool isEmpty(); // This function decides wether the char sequence is empty
                int size(); // This function return number of characters in the sequence
                void clear(); // This function makes the sequence into an empty sequence
        
                void concatenate(CharLinkedList *anoherClass); // This functions add another sequence to the formal one
        
                char first(); // Return the first char of the sequence
                char last(); // Return the last char of the sequence
                char elementAt(int index); // Return the specific char of the index given by the user
                void print(); // Prints out all the char in the sequence
        

        
                void insertAtBack(char Achar); // Add one more node at the back of the linkedlist
                void insertAtFront(char Achar); // Add one more node at the front of the linkedlist
                void insertAt(char Achar,int index); // Add one more node at specific place
                void insertInOrder(char Achar); // Add an node and inserts it into the list in alphabetical order
                
        
                void removeFromFront(); // Remove the first node
                void removeFromBack(); // Remove the last node
                void removeFrom(int index); // Remove the node in specific position
                void replace(char Achar,int index);// Replace the char in specific position with a new one
        
        
        
        
        
        
        
        private:
                Node* head; // the pointer points to the first node of CharLinkedList
                Node* tail; // the pointer points to the last node of CharLinkedList
                int num_char; // total number of chars in the linked list
        
        
        
        
        
        
        
        
};


#endif