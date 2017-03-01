// Hw5
// sorter.cpp : The .cpp file holds holds the main function runs
// the whole programm
// Rui Qin
// 10/30/2016


#include "sortAlgs.h"

void rule(string mode,string output);
//Deciding whether the user gives the wrong inputs for
//the run function. Also conducting the abort function without 
//the file name

void usage_abort();
//prints out the error messages using the imformation given

void run(string mode,string output);
//run the programm with parameters
        
void run(string mode,string output,string filename);
//run the programm with three parameters

vector<int> which_alg(vector<int> vec,string mode);
//Determing which mode is used among "s1","s2" and "s3"
        
void which_output(vector<int> vec,string output,string origin,string mode);
//Determing what kind of output
        
string txtName(string origin,string mode,int number);
//combining all the required elements to format the
//txt name

vector<int> copy_strings_from(istream &infile);
//Copy each string of non-whitespace characters from the 
//given input stream onto standard output (cout), one int 
//per line.




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
        
        if (argc == 3 ){
                rule(argv[1],argv[2]);
                run(argv[1],argv[2]);
                
        }else if (argc == 4){
                rule(argv[1],argv[2]);
                run(argv[1],argv[2],argv[3]);
                        
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
//Return:none
void rule(string mode,string output)
{
        if(mode != "-s1" && mode != "-s2" && mode != "-s3"){
                
                usage_abort();
        }
        
        if(output != "--save" && output != "--print"){
                        
                usage_abort();
        }
        

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


//which_alg(vector<int> vec,string mode)
//Purpose:Which sorting method will be used
//Arguments:(vector<int>)the vec we need to sort
//(string)the mode name given
//Return:(vector<int>)the sorted vec
vector<int> which_alg(vector<int> vec,string mode)
{
        if(mode == "-s1"){
                insertionSort(vec);
        }else if(mode == "-s2"){
                shellSort(vec);
        }else if(mode == "-s3"){
                int left = 0;
                int right = vec.size()-1;
                quickSort(vec, left, right);
        }
        return vec;



}







//which_output(vector<int> vec,string output,string origin,string mode)
//Purpose:Which way to present the output
//Arguments:vector<int>the vec we need to use,(string)the way the output 
//being presented,(string)the way the data being read in,(string)the 
//sorting type
//Return:none
void which_output(vector<int> vec,string output,string origin,string mode)
{
        int num_int = vec.size();
        
        if(output == "--print"){
                for(int i = 0; i < num_int; i++){
                        cout << vec[i] << endl;        
                }
                
        }else if(output == "--save"){
                ofstream input;
                string name = txtName(origin,mode,num_int);
                input.open(name);
                for(int i = 0; i < num_int; i++){
                        input << vec[i];
                        input << endl;
                }
        
        }

}





//txtName(string origin,string mode,int number)
//Purpose:combining all the required elements to format the
//txt name
//Arguments:(string)the way the data being reading in,
//(string)the sorting method,(int)number of int in the vec
//Return:(string)the txt name
string txtName(string origin,string mode,int number)
{
        string a = to_string(number);
        return(origin + "_" + mode[2] + "_" + a + "_" + "sorted");



}








//run(string mode,string output)
//Purpose:run the programm with two parameters
//Arguments:(string)the sorting tyoe,(string)the output type
//Return:none
void run(string mode,string output)
{
        vector<int> vec;
        int line;
        while(cin >> line){
                vec.push_back(line);
        }
        vec = which_alg(vec,mode);
        which_output(vec,output,"cin",mode);





}



//run(string mode,string output,string filename)
//Purpose:run the programm with three parameters
//Arguments:(string)the sorting tyoe,(string)the output type
//(string)the filename
//Return:none
void run(string mode,string output,string filename)
{
        vector<int> vec;
        ifstream input;
        
        input.open(filename);

        if (not input.is_open()) {
                cerr << "Unable to open " << filename << endl;
                exit(1);
        }
        
        vec = copy_strings_from(input);
        input.close();
        
        vec = which_alg(vec,mode);
        which_output(vec,output,filename,mode);
        


}







//copy_strings_from(istream &infile)
//Purpose://Copy each string of non-whitespace characters 
//from the given input stream onto standard output (cout), 
//one string per line.
//Arguments:the address of the file input 
//Return:the vec which gets the input from file
vector<int>  copy_strings_from(istream &infile)
{
        int line;
        vector<int> vec;
        
        while(infile >> line) 
                vec.push_back(line);
        
        return vec;
         
        
}





























