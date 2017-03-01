// Proj2Part2
// FSTreeTraversal.cpp : The .cpp file holds holds the main function runs
// the whole programm
// Rui Qin
// 11/14/2016

//General Guide: This is the file includes the "FSTree.h" header
//file and main() function which start and run thw whole programm.
//First of all, it will get the commands from terminal, which is
//the starting directory
//Second, it will initilize a class of "FSTree" with the parameter,
//which is the name of the source directory, then the "FSTree.o" 
//given by professor will put all the sub-files and sub-directories
//into the tree.
//Third,call the run(DirNode* root), which will take a node as input '
//and try to find all the sub-files and print them out. Also, if it
//finds out a new directory, it will continue traverse until get to 
//files.

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

#include "FSTree.h"


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
                DirNode* root = A.getRoot();
                //then get the pointer to the arranged root
                run(root,argv[1]);
                
        
        }else{
                usage_abort();
        }




}





//run(DirNode* root)
//Purpose:First find out whether there are directories or files
//in the source directory.Then find the files and print them all
//out, find the directory run the programm again by recursion.
//Arguments:(DirNode*)the node
//Return:none
void run(DirNode* leaf,string prefix)
{
        string path;
        if(!leaf->isEmpty()){
                if(leaf->hasFiles()){ 
                        //Take all files out and prints all the path
                        //(parent directories)it has and the name of 
                        //itself        
                        int num_files = leaf->numFiles();
                        for(int i = 0; i < num_files; i++){
                                string name = leaf->getFile(i);
                                path = prefix + parent_name(leaf)+ "/" + name;
                                cout << path << endl;
                        }
                        
                }
                if(leaf->hasSubDir()){
                        //Take all the directories out and run the function 
                        //again(recursion)to find the files in them
                        int num_dirs = leaf->numSubDirs();
                        for(int i = 0; i < num_dirs; i++){
                                DirNode* dir = leaf->getSubDir(i);
                                run(dir,prefix);
                                
                        
                        }
                
                }
                
        }








}



//parent_name(DirNode* leaf)
//Purpose:Given a node, it will traverse all the path
//and parents directory and return them
//Arguments:(DirNode* leaf)the node needed to be traversed
//Return:(string)all the path of the parent directories of 
//the given node
string parent_name(DirNode* leaf)
{
        string path;
        if(leaf->getParent()==NULL){
                return path;
        
        }else{
                DirNode* parent = leaf->getParent();
                path = parent_name(parent);
                path = path + "/" + leaf->getName();
                return path;
        }



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
        cerr << "            where:  directory is a valid directory";
        exit(1); 




}
























