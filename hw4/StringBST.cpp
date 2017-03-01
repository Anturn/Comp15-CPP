// StringBST.cpp : The .cpp file holds all the funcion declared in StringBST.h
// Rui Qin
// 10/22/2016

#include "StringBST.h"


//StringBST()
//Purpose:constructor without parameters,initialize the 
//initial pointer to NULL and number of string in the 
//tree to 0
//Arguments:none
//Return:none
StringBST::StringBST()
{
        root = NULL;
}



//StringBST(string array[] , int size)
//Purpose: takes an array of strings and an
//integer specifying the size of the array as parameters and
//creates a binary search tree with strings inserted in the
//order in which they appear in the array
//Arguments:an array of strings and the size of the array
//Return:none
StringBST::StringBST(string array[] , int size)
{
        root = NULL;
        for(int i=0;i<size;i++){
                add(array[i]);
        }
}



//~StringBST()
//Purpose: destroys the heap?allocated data associated with 
//the current binary search tree
//Arguments:none
//Return:none
StringBST::~StringBST()
{
        clear();
}


        
//isEmpty()
//Purpose:decide whether the tree is empty
//Arguments:none
//Return:(bool)true if the tree is empty, false if not
bool StringBST::isEmpty()
{
        return (size()==0);
}



//clear()
//Purpose:makes the current binary search tree into
//an empty binary search tree
//Arguments:none
//Return:none
void StringBST::clear()
{
        clear_helper(root);
        root = NULL;
  
}



//clear_healper(treeNode* leaf)
//Purpose:the recursive version to clear the tree used in
//function clear()
//Argument:(treeNode*)the pointer to a tree node
//ReturnLnone
void StringBST::clear_helper(treeNode* leaf)    
{
        if(leaf!=NULL){
                clear_helper(leaf->left);
                clear_helper(leaf->right);
                delete leaf;
        }

}





//size()
//Purpose:how many elements currently in the tree
//Arguments:none
//Return:(int)number of elements in the tree
int StringBST::size()
{
        return size_helper(root);
}



//size_helper(treeNode* leaf)
//Purpose:the recursive version to get how many elements
//currently in the tree for the function size()
//Arguments:(treeNode*)a tree node
//Return:(int)the number of elements in the tree
int StringBST::size_helper(treeNode* leaf)
{
        int num_element = 0;
        if(leaf!=NULL){
                num_element+=leaf->time;
                num_element+=size_helper(leaf->left);
                num_element+=size_helper(leaf->right);
                
        }
        return num_element;


}




//print()
//Purpose:prints the binary search tree in order
//Arguments:none
//Return:none
void StringBST::print()
{
        print_helper(root);
}



//print_helper(treeNode* leaf)
//Purpose:the recursive version to print out the data in 
//the tree for the function print()
//Arguments:(treeNode*)the pointers to a tree node
//Return:none
void StringBST::print_helper(treeNode* leaf)
{
        cout << "[";
        if(leaf==NULL){
                cout <<"]";
                return;
        }else{
                
                
                print_helper(leaf->left);
                cout << " ";
                cout << leaf->word << " " << leaf->time;
                cout << " ";
                print_helper(leaf->right);
                cout <<"]";
                
        }

        

}







//add(string element)
//Purpose:takes an element (string) and adds it 
//to the binary search tree in the correct location 
//based on the behavior of binary search trees
//Arguments:(string)a string be added
//Return:none
void StringBST::add(string element)
{ 

        if(root == NULL){
                treeNode* temp = new treeNode; 
                temp->time = 1;
                temp->word = element;
                root = temp;
        }else{
                add_helper(element,root);
        }
        
    
    
}


//add_helper(string element, treeNode* leaf)
//Purpose:recursive version to add an new element into the
//tree for function add(string element)
//Arguments:(string)a string needed to add,(treeNode*)a tree node
//Returen:none
void StringBST::add_helper(string element, treeNode* leaf)
{
        if(element == leaf->word){
                leaf->time++;
        }else if(element < leaf->word){
                if(leaf->left ==NULL){
                        treeNode* Anode = new treeNode;
                        Anode->time = 1;
                        Anode->word = element;
                        leaf->left = Anode; 
                }else{
                        add_helper(element, leaf->left);
                }
        }else if(element > leaf ->word){
                if(leaf->right ==NULL){
                        treeNode* Anode = new treeNode;
                        Anode->time = 1;
                        Anode->word = element;
                        leaf->right = Anode; 
                }else{
                        add_helper(element, leaf->right);
                }
        }
    
    
    
}







//remove(string element)
//Purpose:takes a target (string) as a parameter
//and returns a boolean. True if there is one and
//is removed successfully, false if not
//Arguments:(string)the target string
//Return:(bool)true if successfully removed, false
//if not
bool StringBST::remove(string element)
{
        if(contains(element)){
        
                root = remove_helper(element, root);
                return true;
        }else{
        
                return false;
        }
}




//remove_helper(string element, treeNode* leaf)
//Purpose:the recursive version to take a target (string) as
//a parameter and returns a boolean. It will find the target 
//and then proceed to remove one instance of it from the tree
//for the function remove(string element)
//Arguments:(string)the target string,(treeNode*)the tree node
//Return:(treeNode*)the pointer to the top root of the tree
treeNode* StringBST::remove_helper(string element, treeNode* leaf)
{
        if(leaf==NULL){
        
                return leaf;
        }else if(element < leaf->word){
        
                leaf->left = remove_helper(element,leaf->left);
        }else if(element > leaf->word){
        
                leaf->right = remove_helper(element,leaf->right);
        }else{
                
                if(leaf->time > 1){
                        
                        leaf->time--;
                        return leaf;
                }else{
                        if(leaf->left == NULL && leaf->right == NULL){
                                
                                treeNode* temp = leaf->left;
                                delete leaf;
                                return temp;
                        }else if(leaf->left == NULL){
                                
                                treeNode* temp = leaf->right;
                                delete leaf;
                                return temp;
                        }else if(leaf->right == NULL){
                
                                treeNode* temp = leaf->left;
                                delete leaf;
                                return temp;
                        }else{
                                treeNode* temp = getMin_helper(leaf->right);
                                int times = temp->time;
                                
                                leaf->word = temp->word;
                                leaf->time = temp->time;
                                
                                for(int i = 0; i < times ;i++ ){
                                        leaf->right = 
                                        remove_helper(temp->word,leaf->right);
                                }
                        
                        }
                }
                
                
        }
        return leaf;
        
        
}




//getMin()
//Purpose:takes no parameters and returns a string. 
//It returns the left most (smallest) string in the
//binary search tree
//Arguments:none
//Return:(string)the smallest string in the tree
string StringBST::getMin()
{    
        if(isEmpty()){
                throw runtime_error ("getMin:empty_tree");
        }
        return getMin_helper(root)->word;
}



//getMin_helper(treeNode* leaf)
//Purpose:the recursive version to find out the smallest
//string in the tree for the function getMin()
//Arguments:(treeNode*)the pointer to the tree node
//Return:(string)the smallest string in the tree
treeNode* StringBST::getMin_helper(treeNode* leaf)
{
        if(leaf->left==NULL){
                return leaf;
        }
        
        return getMin_helper(leaf->left);


}






//getMax()
//Purpose:takes no parameters and returns a string. 
//It returns the right most (largest) string in the
//binary search tree
//Arguments:none
//Return:(string)the largest string in the tree
string StringBST::getMax()
{
        if(isEmpty()){
                throw runtime_error ("getMax:empty_tree");
        }
        return getMax_helper(root)->word;
}




//getMax_helper(treeNode* leaf)
//Purpose:the recursive version to find out the largest
//string in the tree for the function getMax()
//Arguments:(treeNode*)the pointer to the tree node
//Return:(string)the largest string in the tree
treeNode* StringBST::getMax_helper(treeNode* leaf)
{
        if(leaf->right==NULL){
                return leaf;
        }
        
        return getMax_helper(leaf->right);


}





//removeMin()
//Purpose:removes the left most (smallest) string in 
//the binary search tree
//Arguments:none
//Return:none
void StringBST::removeMin()
{
    
        if(isEmpty())
               return;
       
        removeMin_helper();
    
}


//removeMin_helper(treeNode* leaf)
//Purpose:using the function remove() and getMin()
//to help find the smallest string and remove it
//Arguments:none
//Return:none
void StringBST::removeMin_helper()
{
        
        
        string temp_Min = getMin();
        root = remove_helper(temp_Min,root);
        
        
}






//removeMax()
//Purpose:removes the right most (largest) string in
//the binary search tree
//Arguments:none
//Return:none
void StringBST::removeMax()
{
        if(isEmpty())
               return;
        
        removeMax_helper();
}



//removeMax_helper(treeNode* leaf)
//Purpose:using the function remove() and getMax()
//to help find the largest string and remove it
//Arguments:none
//Return:none
void StringBST::removeMax_helper()
{
        
        string temp_Max = getMax();
        root = remove_helper(temp_Max,root);
        
}




//contains(string element)
//Purpose:search the binary search tree, and if it  
//finds the query returns true, otherwise it will  
//return false
//Arguments:(string)the target string be searched
//Return:(bool)true if tree cantains the string, false
//if not 
bool StringBST::contains(string element)
{
    
        return contains_helper(element,root);
    
}


//contains_helper(string element, treeNode* leaf)
//Purpose:the recursive version to finds whether the target
//string is in the tree for the function contains(string element)
//Argument:(element)the target string,(treeNode*)a tree node
//Return:(bool)true if it finds out, false if not
bool StringBST::contains_helper(string element, treeNode* leaf)
{
        if(leaf!=NULL){
                if(element == leaf->word){
                        return true;
                }else if(element<leaf->word){
                        return contains_helper(element,leaf->left);
                }else if(element>leaf->word){
                        return contains_helper(element,leaf->right);
                }
        }
        return false;
}
































