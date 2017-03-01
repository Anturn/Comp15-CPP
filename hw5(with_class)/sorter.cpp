// Hw5
// sorter.cpp : The .cpp file holds holds the main function runs
// the whole programm
// Rui Qin
// 10/30/2016


#include "sortAlgs.h"

bool rule(string mode,string output);
//Deciding whether the user gives the wrong inputs for
//the run function. Also conducting the abort function without 
//the file name

void usage_abort();
//prints out the error messages using the imformation given




//main(int argc, char *argv[])
//Purpose:This is the main function where runs the 
//whole programm. It count the number of inputs in the
//command line and also some specific commands including
//the prgram name,soring method,output saved method,sometimes
//the filename
//Arguments:(int)number of commands,(char*)the commands
//Return:(int)return 0, representing the end of the programm
//and runs well
int main(int argc, char *argv[])
{
        sortAlgs A;
        
        if (argc == 3 ){
                if(rule(argv[1],argv[2]))
                        A.run(argv[1],argv[2]);
                
        }else if (argc == 4){
                if(rule(argv[1],argv[2]))
                        A.run(argv[1],argv[2],argv[3]);
                        
        }else{
		usage_abort();
        }




}



//rule(string mode,string output)
//Purpose:Deciding whether the user gives the wrong inputs for
//the run function. Also conducting the abort function without 
//the file name
//Arguments: (string)the sorting mode,(string)the way the output 
//being presented
//Return:(bool)the inputs are right or wrong
bool rule(string mode,string output)
{
        if(mode=="-s1"||mode=="-s2"||mode=="-s3"){
                if(output == "--save"|| output == "--print"){
                        return true;
                }
        }
        usage_abort();

}






//usage_abort1()
//Purpose:prints out the error messages using the imformation given
//Arguments:none
//Return:none
void usage_abort()
{
        cerr << "Usage:  sorter sortAlg outputMode [fileName]" << endl;
        cerr << "            where:  sortAlg is -s1, -s2, or -s3" << endl;
        cerr << "            and     outputMode is --print or --save" << endl;
	exit(1);
}























