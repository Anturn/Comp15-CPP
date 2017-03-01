// Proj2
// hashTable.cpp : The implementation file for contains all the 
// functions in hashTable.cpp
// Rui Qin
// 11/16/2016


#include "hashTable.h"





//Constructor:initialize two different vectors of hash table
//with specific size 
hashTable::hashTable()
{
      vec = new Node [VECTORSIZE];
      vec1 = new Node [VECTORSIZE];
}




hashTable::~hashTable()
{
}





//run(DirNode* root)
//Purpose:First find out whether there are directories or files
//in the source directory.Then find the files and print them all
//out, find the directory run the programm again by recursion.
//Arguments:(DirNode*)the node
//Return:none
void hashTable::run(DirNode* leaf,string prefix)
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
                                read(name,path);

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


//run1()
//Purpose:Collect the imformation from the command line
//and ask the user the specific command to run next
//Arguments:none
//Return:none
void hashTable::run1()
{
        string command;
        cout << "Query? ";
        
        while(cin >> command){
                if (command == "@q" || command == "@quit"){
                        break;
                }else if (command == "@i" || command == "@insensitive"){
                        string word;
			                  cin >> word;
			                  word = toLC(word);
			                  mode_i(word);
			
                }else{          
			                  mode(command);
			
		
                }
                cout << "Query? ";
        }

        cout << "\nGoodbye! Thank you and have a nice day." << endl;
        return;



}





//parent_name(DirNode* leaf)
//Purpose:Given a node, it will traverse all the path
//and parents directory and return them
//Arguments:(DirNode* leaf)the node needed to be traversed
//Return:(string)all the path of the parent directories of 
//the given node
string hashTable::parent_name(DirNode* leaf)
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




//read(string filename, string path)
//Purpose:Open the specific file and prepare to take
//out all the words from it
//Arguments:(string)the name of the file£¬(path)the path
//of the file
//Return:none
void hashTable::read(string filename, string path)
{

        ifstream input;
        input.open(path);
	
        if (not input.is_open()) {
                cerr << "Unable to open " << filename << endl;
                return;
        }
        
        copy_strings_from(input,path);
        input.close();
        
        

}



//copy_strings_from(istream &infile,string path)
//Purpose:Copy each string of non-whitespace characters from the 
//given input stream onto standard output (cout), one int 
//per line.
//Arguments:(string)the path of the file,(istream&)the reference of 
//the input
//Return:none
void hashTable::copy_strings_from(istream &infile,string path)
{
  
        string word,wholeline,line;
        int number_of_lines = 0;
  
	
     
	      while (getline(infile, line)){
		            ++number_of_lines;
		            istringstream iss(line);
			          while(iss >> word){
				                insert(word,number_of_lines,path,line);
			          }
	      }
		
    
}





//insert(string word,int line,string path,string wholeline)
//Purpose://Insert a new word into a hash table with all the imformation required 
//Arguments:(string)the word needed to insert,(int)the line the word is in
//(string)the path(the address)of the word in file,(string)all content in the line
//Return:none 
void hashTable::insert(string word,int line,string path,string wholeline)
{
       
	
        string newword = toLC(word);
        int index = hash(word);
        int index1 = hash(newword);
        vec[index].insertNode(word,newword,index,line,path,wholeline);
        vec1[index1].insertNode(word,newword,index1,line,path,wholeline);
    
    
       
}



//hash(string word)
//Purpose:Transform a strong into a number as an index
//Arguments:(string)the word given to hash(transform into index)
//Return:(int)the index of the word 
int hashTable::hash(string word)
{
        int sum = 0;
        for(size_t i = 0; i < word.length(); i++){
        
                sum = sum + int(word[i]);
        }

        return sum % VECTORSIZE;


}





//string toLC(string word)
//Purpose:to transform all the charactors in the string 
//into lower case
//Arguments:(string)the word being transformed
//Return:(string)the word with lower case
string hashTable::toLC(string word)
{
        for (size_t i=0;i<word.length();i++){  
                
                word[i] = tolower(word[i]);
        }
        return word;




}



//mode(string target)
//Purpose:This is the mode that looks for the original word 
//Arguments:(string)the original word
//Return:nonw
void hashTable::mode(string target)
{
	
        int target_index = hash(target);
        vec[target_index].search_show(target);



}
        
        
        
        

//mode_i(string target)
//Purpose:This is the mode that looks for insensitive word also
//Arguments:(string)the target string in lower case
//Return:none
void hashTable::mode_i(string target)
{
        string newTarget = toLC(target);
        int target_index = hash(newTarget);
        vec1[target_index].search_show_i(newTarget);
        
}















