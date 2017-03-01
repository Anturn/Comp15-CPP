// Proj2
// main.cpp : The user interface file for contains all the functions
// run the whole programm 
// Rui Qin
// 11/16/2016

//General Guide:
//This is the main function, which will run the programm
//as a whole, it will collects the imput, the path, from 
//the command line and call an instance of "FsTree" to 
//save all the directories and files into as a tree and
//then call an instance of "hashTable" and then use the
//functions within then to run next. It will also give
//error message and terminate the programm if given 
//wrong number of imputs.

#include "hashTable.h"


void run(DirNode* root,string prefix);
//First find out whether there are directories or files
//in the source directory.Then find the files and print them all
//out, find the directory run the programm again by recursion.

string parent_name(DirNode* leaf);
//Given a node, it will traverse all the path
//and parents directory and return them

void usage_abort();
//While the user gives wrong number of inputs
//or give invalid commands, the programm will give
//messages warning that and terminate the programm


//main(int argc, char *argv[])
//Purpose:This is the main function where runs the 
//whole programm. It count the number of inputs in the
//command line and also specific command such as the
//beginning directory name
//Arguments:(int)number of commands,(char*)the commands
//Return:(int)return 0, representing the end of the programm
//and runs well
int main(int argc, char *argv[])
{
         
        
        if (argc == 2 ){
                
                FSTree A(argv[1]); 
                //intialize an instance of FSTree class
                hashTable B;
                //initialize an instance of hashTable class
                DirNode* root = A.getRoot();
                //then get the pointer to the arranged root
           
                B.run(root,argv[1]);
                B.run1();
                
                
        
        }else{
                usage_abort();
        }


        return 0;

}







//usage_abort()
//Purpose:While the user gives wrong number of inputs
//or give invalid commands, the programm will give
//messages warning that and terminate the programm
//Arguments:none
//Return:none
void usage_abort()
{
        cerr << "Usage:  gerp directory" << endl;
        cerr << "            where:  directory is a valid directory" << endl;
        exit(1); 




}