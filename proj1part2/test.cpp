// Proj1
// test.cpp : The .cpp file contains the main() and run the whole programm
// Rui Qin
// 9/30/2016


#include <iostream>
#include "Operation.h"
using namespace std;

void usage_abort(string program_name);
//void copy_strings_from(istream &infile);

int main(int argc, char *argv[])
{
        string filename; //The name of the file
        ifstream input;  
        int size;        //The number of PackStations
        string mode;     //The mode
        
        
        if (argc != 4){
                usage_abort(argv[0]);
        }
        filename = argv[1];  
        size = std::stoi(argv[2]); 
        mode = argv[3];
        
        input.open(filename);
        if (not input.is_open()) {
                cerr << "Unable to open " << argv[0] << endl;
                return 1;
        }
        
        Operation O(filename,size,mode); 
       //Initilize the Operation class
        O.run();  
       //The core, run the whole programm 
       //in the most upper level
        
        return 0;
        
        
        
        
}


/*
 * Copy each string of non-whitespace characters from the given input
 * stream onto standard output (cout), one string per line.
 */
// void copy_strings_from(istream &infile)
// {
//         string s;
//         for (infile >> s; not infile.eof(); infile >> s)
//                 cout << s << endl;
// }


/*
 * Abort the program with an error message describing correct program
 * usage.
 */
void usage_abort(string program_name)
{
        cerr << "Usage:  " << program_name << " filename" << endl;
        exit(1);
}