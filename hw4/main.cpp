#include "Alphabetizer.h"

void usage_abort(string program_name,string mode, string filename);


//main(int argc, char *argv[])
//Purpose:This is the main function where runs the 
//whole programm. It count the number of inputs in the
//command line and also some specific commands.
//Arguments:(int)number of commands,(char*)the commands
//Return:(int)return 0, representing the end of the programm
//and runs well
int main(int argc, char *argv[])
{

        Alphabetizer A;
        int    number = argc;   //Number of conmmands in the command line
        
        if(number == 1){
                A.run();
                return 0;
        }
        
        if(number == 3){
                string programm_name = argv[0]; //Programm name
                string mode = argv[1];     //The mode
                string filename = argv[2];; //The name of the file
                if(mode == "f" || mode == "r"){
                        A.run(filename,mode);
                }else{
                        usage_abort(programm_name,mode,filename);
                }
        }
        
        
}





//usage_abort(string program_name,string mode, string filename)
//Purpose:prints out the error messages using the imformation given
//Arguments:(string)the name of the programm,(string)the mode
//the programm will implement,(string)the name of the input
//Return:none
void usage_abort(string program_name,string mode, string filename)
{
        cerr << "Usage:  " << program_name << " [" << mode;
        cerr << " " << filename << "]";
        exit(1);
}







