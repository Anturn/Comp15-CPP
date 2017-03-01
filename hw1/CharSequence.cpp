// CharSequence.cpp : The .cpp file holds all the funcion declared in CharSequence.h
// Rui Qin
// 9/13/2016

#include <iostream>
#include <stdexcept>
#include "CharSequence.h"
using namespace std;


//This is the default constructor takes no parameters
//and initializes an empty sequence. It does not return
//anything.
CharSequence::CharSequence()
{
        capacity = CAPACITY; //capacity initialized as constant CAPACITY
        num_elements = 0;    // num_elements initialized as 0 since there is no char in the sequence
        charSequence = new char[CAPACITY]; // create a sequence with specific size
        
        
        
}

//This constructor takes in a single character as a
//paramter and creates a one element sequence consisting of
//that character.It does not return anything.

CharSequence::CharSequence(char Achar)   
{
        num_elements = 1;      // One char in the sequence
        capacity = CAPACITY;  
        charSequence = new char[capacity];  // create a sequence with specific size
        charSequence[0] = Achar;  // First char generated
        
        
}

//This is a destructor that destroys/deletes/recycles the
//heap-allocated data in the current sequence.
CharSequence::~CharSequence()
{
        delete[] charSequence;
        
}



//isEmpty()
//Purpose: Decides wether the sequence is empty: true if it is, false if it is not
//Arguments: none
//Return: (boolean) If sequence is empty, return true, otherwise, false
bool CharSequence::isEmpty()
{
        if (num_elements==0)
                return true;
        else
                return false;
}

//size()
//Purpose: Decides how many char in the sequence
//Arguments:none
//Return:number of char in the sequence
int CharSequence::size()
{
        return num_elements;
}

//clear()
//Purpose: It makes the sequence into an empty sequence
//Arguments:none
//Return:none
void CharSequence::clear()
{
        for (int i =0;i<num_elements;i++)
                charSequence[i] = '\0'; 
                num_elements = 0;
}



//concatenate(CharSequence *anotherClass) 
//Purpose: It combines two sequence togather
//Arguments:a pointer to a new Char sequence
//Return:none
void CharSequence::concatenate(CharSequence *anotherClass) 
{
        int otherSize = anotherClass->size();
        
        for (int i = 0 ; i < otherSize; i++){
                insertAtBack(anotherClass->elementAt(i));
        }
        
        
}  



//first()
//Purpose: Return the first char of the sequence
//Arguments:none
//Return:(char) the first char of the sequence
char CharSequence::first()
{        
        
        if (num_elements==0){
                throw invalid_argument("the sequence is empty");
        }
        return charSequence[0];
}



//last()
//Purpose: Return the last char of the sequence
//Arguments:none
//Return:(char) the last char of the sequence
char CharSequence::last()
{
        if (num_elements==0){
                throw invalid_argument ("the sequence is empty");
        }
        return charSequence[num_elements-1];
}



//elementAt(int index)
//Purpose: Return the specific char of the index
//Arguments:(int) index from user
//Return:(char) the char of the sequence in specific pisition
char CharSequence::elementAt(int index) //////////////using capacity or number of elements as range//////////////////////////////
{
        if (num_elements==0){
                throw invalid_argument("the sequence is empty");
        }else if (index>num_elements){
                throw invalid_argument ("index is out of range");
        }
        
        return charSequence[index];
}





//print()
//Purpose: Print out all the char in the sequence
//Arguments:none
//Return:none
void CharSequence::print()
{
        cout << "[CharSequence of size " << num_elements;
        cout << " <<" ;
        for (int i = 0; i < num_elements; i++)
                cout << charSequence[i];
        cout << ">>]";
                
}

//expand(int charadded)
//Purpose: Expand the sequence with more space and upgrade the capacity
//Arguments:(int)number of new rooms added
//Return:none
void CharSequence::expand(int charadded)
{
        char *temp;
        temp = new char[capacity+charadded];
        for (int i = 0; i < capacity; i++) {
                temp[i] = charSequence[i];
        }
        delete[] charSequence;
        charSequence = temp;
        capacity += charadded; 
}

//expand(int charadded)
//Purpose: Expand the sequence with more space and upgrade the capacity
//Arguments:(int)number of new rooms added
//Return:none
void CharSequence::expand1(int charadded)
{
        char *temp;
        temp = new char[capacity+charadded];
        for (int i = 1; i < capacity+1; i++) {
                temp[i] = charSequence[i-1];
        
        }
        delete[] charSequence;
        charSequence = temp;
        capacity += charadded;

}








//insertAtBack(char Achar)()
//Purpose: Add one more char at the back of the sequence
//Arguments:(char)the char that will be added
//Return:none
void CharSequence::insertAtBack(char Achar)
{
        if(num_elements == capacity){
                expand(ADDNUMBER);
        }

        charSequence[num_elements] = Achar;
        num_elements ++;

}


//insertAtFront(char Achar)
//Purpose: Add one more char at the front of the sequence
//Arguments:(char)the char that will be added
//Return:none
void CharSequence::insertAtFront(char Achar)
{
        expand1(ADDNUMBER);
        charSequence[0] = Achar;
        num_elements ++;

}


//insertAt(int index, char Achar)
//Purpose: Add one more char at specific place
//Arguments:(char)the new added char,(int)the place put the char
//Return:none
void CharSequence::insertAt(char Achar,int index)
{        
        char *temp;
        temp = new char[capacity+1];
        if(index>num_elements){
                throw invalid_argument("index is out of range");
        }else if (index == 0 ){
                insertAtFront(Achar);

        }else if (index == num_elements+1 ){
                insertAtBack(Achar);

        }else{
                for(int i=0; i <index;i++)
                        temp[i] = charSequence[i];
                temp[index] = Achar;
                for(int j = index+1; j <capacity+1;j++)
                        temp[j] = charSequence[j-1];        

                delete[] charSequence;
                charSequence = temp;
                capacity ++;
                num_elements ++;

        }


}


//removeFromFront()
//Purpose: Remove the first char
//Arguments:none
//Return:none
void CharSequence::removeFromFront()
{
        if (num_elements==0){
                throw invalid_argument("the sequence is empty");
        }
        char *temp;
        temp = new char[capacity-1];
        for(int i = 1;i<num_elements;i++){

                temp[i-1] = charSequence[i];
        }
        delete[] charSequence;
        charSequence = temp;
        capacity --; 
        num_elements--;
        
}


//removeFromBack()
//Purpose: Remove the last char
//Arguments:none
//Return:none
void CharSequence::removeFromBack()
{
        if (num_elements==0){
                throw invalid_argument("the sequence is empty");
        }
        char *temp;
        temp = new char[capacity-1];
        for(int i = 0;i<num_elements-1;i++){

                temp[i] = charSequence[i];
        }
        delete[] charSequence;
        charSequence = temp;
        capacity --; 
        num_elements--;
        

}

//removeFrom()
//Purpose: Remove the char in specific position
//Arguments:none
//Return:none
void CharSequence::removeFrom(int index)
{
        char *temp;
        temp = new char[capacity-1];

        if(index>=num_elements){
                throw invalid_argument("index is out of range");
        }else if(index==0){
        
                removeFromFront();
        }else if(index==num_elements){
        
                removeFromBack();
        }else{
                for(int i = 0;i < index;i++)
                        temp[i] = charSequence[i];
                for(int j = index+1;j<num_elements;j++)
                        temp[j-1] = charSequence[j];
        }
        delete[] charSequence;
        charSequence = temp;
        capacity --; 
        num_elements--;
        
        
        
}





//replace(char Achar,int index)
//Purpose: Replace the char in specific position with a new one
//Arguments:(char)the new added char,(int)the place put the char
//Return:none
void CharSequence::replace(char Achar,int index)
{
        if (index>num_elements){
                throw invalid_argument ("index is out of range");
        }
        charSequence[index] = Achar;
}









































