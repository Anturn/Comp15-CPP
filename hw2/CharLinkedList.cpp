// HW2
// CharLinkedLit.cpp : The .cpp file holds all the funcion declared in CharLinkedList.h
// Rui Qin
// 9/16/2016

#include <iostream>
#include <stdexcept>
#include "CharLinkedList.h"
using namespace std;

//This is the default constructor takes no parameters
//and initializes an empty linked list. It does not return
//anything.
CharLinkedList::CharLinkedList()
{
        head = NULL;
        tail = NULL;
        num_char = 0;
}


//This constructor takes in a single character as a
//paramter and creates a one element linked list consisting of
//that character.It does not return anything.
CharLinkedList::CharLinkedList(char Achar)
{
        num_char = 1;
        Node *new_node = new Node;
        new_node->info = Achar;
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
        tail = new_node;
}


//This is a destructor that deletes the linked list.
CharLinkedList::~CharLinkedList()
{
        Node* temp = head;
        while(temp != NULL){
                temp = temp->next;
                delete head;
                head = temp;
        }
        
}

//isEmpty()
//Purpose: Decides wether the linked list is empty: true if it is, false if it is not
//Arguments: none
//Return: (boolean) If linked list is empty, return true, otherwise, false
bool CharLinkedList::isEmpty()
{
        if (num_char==0)
                return true;
        else
                return false;
}

//size()
//Purpose: Decides how many char in the linked list
//Arguments:none
//Return:number of char in the linked list
int CharLinkedList::size()
{
        return num_char;
}



//clear()
//Purpose: It makes the linked into an empty linked list
//Arguments:none
//Return:none
void CharLinkedList::clear()
{
        num_char = 0;
        Node* temp = head;
        while(temp != NULL){
                temp->info = '\0'; 
                temp = temp->next;
        }
        
        
}



//concatenate(CharLinkedList *anotherClass) 
//Purpose: It combines two linked list togather
//Arguments:a pointer to a new linked list
//Return:none
void CharLinkedList::concatenate(CharLinkedList *anotherClass) 
{
        int loop_time = anotherClass->size();
        for(int i=0;i<loop_time;i++){
                insertAtBack(anotherClass->elementAt(i));
                
        }
        
        
        
}





//first()
//Purpose: Return the first char of the linked list
//Arguments:none
//Return:(char) the first char of the linked list
char CharLinkedList::first()
{        
        if (num_char==0){ //////////////////////////////
                throw invalid_argument("the linkedlist is empty");
        }
        return head->info;
       
}



//last()
//Purpose: Return the last char of the linked list
//Arguments:none
//Return:(char) the last char of the linked list
char CharLinkedList::last()
{
        if (num_char==0){ ////////////////////////////
                throw invalid_argument ("the linkedlist is empty");
        }
        return tail->info;
}


//elementAt(int index)
//Purpose: Return the specific char of the index
//Arguments:(int) index from user
//Return:(char) the char of the linked list in specific pisition
char CharLinkedList::elementAt(int index) //////////////using capacity or number of elements as range//////////////////////////////
{
        Node* temp = head;
        if (num_char==0){
                throw invalid_argument("the linkedlist is empty");
        }else if (index>=num_char){
                throw invalid_argument ("index is out of range");
        }else{
                for(int i=0;i<index;i++)
                        temp = temp->next;
                return temp->info;
        }
        
}



//print()
//Purpose: Print out all the char in the linked list
//Arguments:none
//Return:none
void CharLinkedList::print()
{
        Node* temp = head;
        cout << "[CharLinkedList of size " << num_char;
        cout << " <<" ;
        for (int i = 0; i < num_char; i++){
                cout << temp->info;
                temp = temp->next;
        }
        cout << ">>]";
                
}



//insertAtBack(char Achar)()
//Purpose: Add one more char at the back of the linked list
//Arguments:(char)the char that will be added
//Return:none
void CharLinkedList::insertAtBack(char Achar)
{
        Node* temp = new Node; // create a new node
        temp->info = Achar; // save the data into the new node
        temp->next = NULL; // because the new node will become the tail, the next it points to is NULL
        temp->prev = tail; // the formal tail becomes the previous node 
        if(num_char==0){
                
                head = temp;
                tail = temp;
                
        }else{
        tail->next = temp; // make the new node linked to the existed one
        tail = temp; // then update the tail, let it points to the last node of the linked list
        }
        
        num_char ++; // update the number of char in the linked list
        
}

//insertAtFront(char Achar)
//Purpose: Add one more char at the front of the linked list
//Arguments:(char)the char that will be added
//Return:none
void CharLinkedList::insertAtFront(char Achar)
{
        Node* temp = new Node; // create a new node
        temp->info = Achar; // save the data into the new node
        temp->next = head; // because the new node will become the head, the next it points to is head
        temp->prev = NULL; // the formal head  becomes the previous node 
        if(num_char==0){
        
                head = temp;
                tail = temp;
                
        }else{
        head->prev = temp; // make the new node linked to the existed one
        head = temp; // then update the head, let it points to the first node of the linked list
        }
        
        num_char++; // update the number of char in the linked list
        
        

}


//insertAt(int index, char Achar)
//Purpose: Add one more char at specific place
//Arguments:(char)the new added char,(int)the place put the char
//Return:none
void CharLinkedList::insertAt(char Achar,int index)
{        
        Node *newNode = new Node;
        Node *temp = head;
        newNode->info = Achar;
        
       
        if(index>num_char){
                throw invalid_argument("index is out of range");
        }else if (index == 0 ){
                insertAtFront(Achar);

        }else if (index == num_char ){          //////////////////////////////////////////////
                insertAtBack(Achar);

        }else{
                for(int i=0; i <index;i++){  /////////////////Question!/////////////////////////
                       temp = temp->next;
                }
                newNode->next = temp;
                temp->prev->next = newNode;
                
                newNode->prev = temp->prev ;
                temp->prev = newNode;
                
                
                num_char++;

        }


}


//insertInOrder(char Achar)
//Purpose:Takes an element (char) and inserts it into the list in alphabetical order
//Arguments:(char)the char that will be added
//Return:none

void CharLinkedList::insertInOrder(char Achar)
{
        if(num_char==0){
                insertAtFront(Achar);
        }else{
                Node* temp = head;
                for(int i=0;i<num_char;i++){
                        if( Achar < temp->info ){
                                insertAt(Achar,i);
                                return;
                        }
                temp = temp->next;
                }
                insertAtBack(Achar);
                
        }
}






//removeFromFront()
//Purpose: Remove the first node
//Arguments:none
//Return:none
void CharLinkedList::removeFromFront()
{
        if (num_char==0){
                throw invalid_argument("the linked list is empty");
        }else if(num_char==1){
                delete head;
                head = NULL;
                tail = NULL;
        }else{
                Node* temp = head;
                delete head;
                temp->next->prev = NULL;
                temp = temp->next;
                head = temp;
                
        }
        
        num_char--;
        
        
        
}



//removeFromBack()
//Purpose: Remove the first node
//Arguments:none
//Return:none
void CharLinkedList::removeFromBack()
{
        if (num_char==0){
                throw invalid_argument("the linked list is empty");
        }else if(num_char==1){
                delete head;
                head = NULL;
                tail = NULL;
        }else{
                Node* temp = tail;
                delete tail;
                temp->prev->next =NULL;
                temp = temp->prev;
                tail = temp;
        }
        
        num_char--;
        
        
}


//removeFrom()
//Purpose: Remove the char in specific position
//Arguments:none
//Return:none
void CharLinkedList::removeFrom(int index)
{
        

        if(index>=num_char){
                throw invalid_argument("index is out of range");
        }else if(index==0){
        
                removeFromFront();
        }else if(index==num_char-1){
        
                removeFromBack();
        }else{
                Node* temp = head;
                for(int i=0;i<index;i++)
                        temp = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                num_char--;
        }
       
        
        
        
}











//replace(char Achar,int index)
//Purpose: Replace the char in specific position with a new one
//Arguments:(char)the new added char,(int)the place put the char
//Return:none
void CharLinkedList::replace(char Achar,int index)
{
        if (index>num_char){
                throw invalid_argument ("index is out of range");
        }
        
        Node* temp = head;
        for(int i=0; i < index ; i++)
                temp = temp->next;
        temp->info = Achar;
}


