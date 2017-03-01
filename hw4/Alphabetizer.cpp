// Alphabetizer.cpp : The .cpp file holds all the funcion declared in Alphabetizer.h
// Rui Qin
// 10/22/2016

#include "Alphabetizer.h"




//the constructor
Alphabetizer::Alphabetizer()
{
}

//This is a desctructor destroys/deletes/recycles any
//heap-allocated data you may have used in the Alphabetizer
Alphabetizer::~Alphabetizer()
{
}






//run()
//Purpose:read string from command lines one by one 
//as the user types, first the string for the mode, 
//second then all the strings needed to sort. Then, 
//print out the sorted strings in a format according 
//to the mode the requriments
//Arguments:none
//Return:none
void Alphabetizer::run()
{
        string line;
        cin >> mode;
       
        if((mode != "f")&&(mode != "r")){ 
                
                cerr << "[ cin, " << mode << " : " ;
                cerr << "neither f nor r, not a valid mode name ]" <<endl;
                exit(1);
        }

                while (cin>>line){
                        BST1.add(line);
                        
                }
                cout << "[ cin, " << mode << " : ";
                if(mode=="f")
                        print_inOrder();
                else if(mode=="r")
                        print_reversedOrder();
                
        
        cout << " ]";




}


//run(string filename, string order)
//Purpose:get the file name and using the stream to take them 
//out to save into the binary tree. Then prints them out
//as sorted according to the mode given and the format
//Arguments:(string)the name of the file,(string)the mode
//Return:none
void Alphabetizer::run(string filename, string order)
{
        mode = order;
        ifstream input;
        input.open(filename);

        if (not input.is_open()) {
                cerr << "Unable to open " << filename << endl;
                exit(1);
        }
        
        copy_strings_from(input);
        
        cout << "[ " << filename << ", " << mode << " : ";
        if(order =="f")
                print_inOrder();
        else
                print_reversedOrder();
        cout << " ]" ;
        
        
        input.close();
           
}


//copy_strings_from(istream &infile)
//Purpose://Copy each string of non-whitespace characters 
//from the given input stream onto standard output (cout), 
//one string per line.
//Arguments:the address of the file input 
//Return:none
void Alphabetizer::copy_strings_from(istream &infile)
{
        string s;
        
        while(infile >> s) 
                BST1.add(s);
         
        
}






//print_inOrder()
//Purpose:Print the strings in the tree from the smallest
//to the largest according to their  ASCII character values
//Arguments:none
//Return:none
void Alphabetizer::print_inOrder()
{
        while(!BST1.isEmpty()){
                cout << BST1.getMin();
                if(BST1.size() > 1){
                    cout << ", " ;
                }
                
                BST1.removeMin();
        }

}




//print_reversedOrder()
//Purpose:Print the strings in the tree from the largest
//to the smallest according to their  ASCII character values
//Arguments:none
//Return:none
void Alphabetizer::print_reversedOrder()
{
        while(!BST1.isEmpty()){
                cout << BST1.getMax();
                if(BST1.size() > 1){
                    cout << ", " ;
                }
                
                BST1.removeMax();
        }



}