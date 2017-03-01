// RPNCalc.cpp : The .cpp file holds all the funcion declared in RPNCalc.h
// Rui Qin
// 9/13/2016



#include "RPNCalc.h"




//This is the default constructor takes no parameters
//and initializes a stack and set the loop
//condition to true.It does not return anything
//anything.
RPNCalc::RPNCalc()
{        
        commands1 ="";
        fir = 0;
        sec = 0;
        isContinue = true;
}

//This is a desctructor destroys/deletes/recycles any
//heap-allocated data you may have used in the RPNCalc
RPNCalc::~RPNCalc()
{

}


//run()
//Purpose:run the whole programm and main function is to 
//receive the input command and execute correspoonding 
//operation depending on the command given
//Arguments:none
//Return:none
void RPNCalc::run()
{
        while (isContinue){
                cin >> commands1;
                run1();
        }
        
        
}

//run1()
//Purpose:run the whole programm and main function is to 
//receive the input command and execute correspoonding 
//operation depending on the command given,this is the
//truncated part from run() function, which contains all 
//corresponding execution depends on the commands given
//Arguments:none
//Return:none
void RPNCalc::run1()
{

        double resultp;
        
        string localString = commands1;
        toLowerCase(localString);
        if(localString == "q"){
                isContinue = false;
        }else if(localString == "p"){
                cout << Stack1.top() << endl;
        }else if(localString == "c"){
                Stack1.clear();
        }else if (localString == "f"){
                read_file();
        }else if (operatorCommand(commands1) ){
                
        }else if(got_double(localString, &resultp)){
                Stack1.push(resultp);
        }else{
                
                cerr << commands1 << ": unimplemented\n";
                        
        }
                
         

}


//operatorCommand(string command)
//Purpose:If the command is one of the operations, it will run 
//and operate and return true, otherwise, it means the command 
//is not one of the operations
//Arguments:The command given by the user
//Return:(bool)ture if the command is one of the operations
//false if it is not
bool RPNCalc::operatorCommand(string command)
{
        if(command == "+"){
                swap();
                Stack1.push(fir+sec);
                return true;
        }else if(command == "-"){
                swap();
                Stack1.push(fir-sec);
                return true;
        }else if(command == "*"){
                swap();
                Stack1.push(fir*sec);
                return true;
        }else if (command == "/"){
                swap();
                Stack1.push(fir/sec);
                return true;
        }else{
        
                return false;
        }
        
}
        
//swap()
//Purpose:Make the sequence of the two doubles poped out swap the 
//order in order to operate properly
//Arguments:none
//Return:none
void RPNCalc::swap()
{
        sec = Stack1.pop();
        fir = Stack1.pop();
        
}

//toLowerCase(string& Astring)
//Purpose:To transfer the string to lower case
//Arguments:Passing a string by reference
//Return:none
void RPNCalc::toLowerCase(string& Astring)
{
        for(unsigned i = 0 ; i < Astring.length();i++)
        {
                Astring[i] = tolower(Astring[i]);
        }
}


//got_double(string s, double *resultp)
//Decide whether the string is a double number
//and transfers the string to double and assign 
//it to another variable
//Arguments:(string,double)A string that will be telled whether is a 
//double number and a double resultp which will be assigned to the 
//transfered double
//Return(bool)Ture id the string is a double number, false if not
bool RPNCalc::got_double(string s, double *resultp)
{
        return sscanf(s.c_str(), "%lf", resultp) == 1;
}



//read_file()
//Purpose:Read the file user give, including the double and operations 
//normally
//Arguments:(none)
//Return:(none)
void RPNCalc::read_file()
{
        string filename;
        cin >> filename;
        ifstream input;
        input.open(filename);

        if (not input.is_open()) {
                cerr << "Unable to read " << filename << "\n";
        
        }
        copy_strings_from(input);
        input.close();
        

}



//read_file(string Astring)
//Purpose:The read file with parameters.Not read input from user
//anymore,but take the existed string in the txt file as input
//Arguments:(string)the string command,
//Return:(none)
void RPNCalc::read_file(string Astring)
{
        string filename;
        filename = Astring;
        ifstream input;
        input.open(filename);
        if (not input.is_open()) {
                cerr << "Unable to read " << filename << "\n";
        }
        copy_strings_from(input);
        input.close();
        
}


//copy_strings_from(istream &infile)
//Purpose:Copy each string of non-whitespace characters from the given input
//stream onto standard output (cout), one string per line.
//Arguments:the address of the file input
//Return:(none)
void RPNCalc::copy_strings_from(istream &infile)
{
        string s;
        //for (infile >> s; not infile.eof(); infile >> s){
        
        while(infile >> s){
                commands1 = s;
                if(commands1 == "f" || commands1 == "F"){
                         infile>>s;
                         commands1 = s;
                         read_file(commands1);
                         
                }else{
                        run1();
                }
                if(!isContinue){
                        return;
                }
        }
        
        
}







