// Proj2
// Node.cpp : The implementation file contains all the functions in Node.h
// Rui Qin
// 11/16/2016

#include "Node.h"

//Constructor:initialize the head pointer, let it
//points to NULL
Node::Node()
{
        head = NULL;
}

//Destructor:deletes and free all the memory allocated
Node::~Node()
{
        data* temp = head;
        while(temp != NULL){
                temp = temp->next;
                delete head;
                head = temp;
        }


}




//insertNode(string word,string newword,int index,int line
//,string path,string wholeline)
//Purpose:Insert the imformation into the vector of the class
//Arguments:(string)the word needed to sort,(string)the lower 
//case of the word,(int)the index of the word by hash function,
//(int)the line the word in (string)the save address of the word,
//(string)the content in the whole line
//Return:none
void Node::insertNode(string word,string newword,int index,int line,string path,string wholeline)
{
        data* newNode = new data;
        newNode->word = word;
        newNode->low_word = newword;
        newNode->key = index;
        newNode->line = line;
        newNode->wholeline = wholeline;
        newNode->path = path;                                                                                                                       
        newNode->next = NULL;

        
        if(head == NULL){
                head = newNode; 
                return;
        }
        data* temp = head;
        data* previous = head;
        
        while(temp != NULL){
                if(temp->word == word ){
                        if(temp->line == line && temp->path == path){
                                return;
                        }else{
                                size_t length = temp->A.size();
                                bool Isame = (length==0 || temp->A[length-1]->path != path || temp->A[length-1]->line != line );
                                if(Isame){
                                        temp->A.push_back(newNode);
                                        return;
                                }else{
                                        return;
                                }
                                
                        }
                }
                
                previous = temp;
                temp = temp->next;
                
        }
        previous->next = newNode;
        
        

}




//search_show(string target_word)
//Purpose:Seearching the target word in the original case
//and then print them out with all the imformation
//used in the mode searching the original word
//Arguments:(string)the target word needed to search and print
//Return:none
void Node::search_show(string target_word)
{
        int position =0;
        data* temp = head;
        while(temp != NULL){
                if(target_word == temp->word){
                        print(temp);
                        if(!temp->A.empty()){
                                for(size_t i = 0; i < temp->A.size();i++){
                                        print(temp->A[i]);
                                }
                        }
                }
                temp =temp->next;
                position++;
        
        }




}


//search_show_i(string newTarget)
//Purpose:Searching the target word in the lower case
//and print them out with all the imformation
//used in the mode searching the word in lower case
//Arguments:(string)the lower case of the target word needed
//to search and print
//Return:none
void Node::search_show_i(string newTarget)
{
	
        data* temp = head;
        while(temp != NULL){
                if(newTarget == temp->low_word){
                        print(temp);
                        if(!temp->A.empty()){
                                for(size_t i = 0; i < temp->A.size();i++){
                                        print(temp->A[i]);
                                }
                        }
                }
                temp =temp->next;
        
        }
	

	
}






//print(data* node)
//Purpose:print the imformation in the iright format
//Arguments:(data*)the pointer points tp a node
//Return:none
void Node::print(data* node)
{
        cout << node->path << ":" << node->line;
        cout << ": " << node->wholeline << endl;




}
















   