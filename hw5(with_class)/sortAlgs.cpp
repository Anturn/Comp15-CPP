// Hw5
// sortAlgs.cpp : The file for testing all the functions in sortAlgs.cpp
// Rui Qin
// 10/30/2016

#include "sortAlgs.h"



//constructor
sortAlgs::sortAlgs()
{
}





//destructor
sortAlgs::~sortAlgs()
{
}



//insertionSort()
//Purpose:This is a sorting method called insertion 
//sort in group 1
//Arguments:none
//Return:none
void sortAlgs::insertionSort()
{
        int num_int = vec.size();
        for (int i=1; i < num_int; i++){
                int index = vec[i]; 
                int j = i;
                while (j > 0 && vec[j-1] > index){
                        vec[j] = vec[j-1];
                        j--;
                }
                vec[j] = index;
        }
        

}



//shellSort()
//Purpose:This is a sorting method called insertion
//sort in group 2
//Arguments:none
//Return:none
void sortAlgs::shellSort()
{
	int num_int = vec.size();
	int j;
 
        //Narrow the array by 2 everytime
	for (int gap = num_int / 2; gap > 0; gap /= 2){
		for (int i = gap; i < num_int; ++i){
			int temp = vec[i];
			for (j = i; j >= gap && temp < vec[j - gap]; j -= gap){
				vec[j] = vec[j - gap];
			}
		vec[j] = temp;
		} 
	}


	
	
	
	
}


//
void sortAlgs::quickSort(vector<int>& vec1,int left, int right) {
	
      int i = left, j = right;
      int tmp;
      int pivot = vec1[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (vec1[i] < pivot)
                  i++;
            while (vec1[j] > pivot)
                  j--;
            if (i <= j){ 
                  tmp = vec1[i];
                  vec1[i] = vec1[j];
                  vec1[j] = tmp;
                  i++;
                  j--;
            }
      }
 
      /* recursion */
      if (left < j)
            quickSort(vec1, left, j);
      if (i < right)
            quickSort(vec1, i, right);
		
}








//which_alg(string mode)
//Purpose:Which sorting method will be used
//Arguments:(string)the mode name given
//Return:none
void sortAlgs::which_alg(string mode)
{
        if(mode == "-s1"){
                insertionSort();
	}else if(mode == "-s2"){
		shellSort();
	}else if(mode == "-s3"){
		int num_int = vec.size();
		int left = 0;
		int right = num_int-1;
                quickSort(vec, left, right);
	}



}







//which_output(string output,string origin,string mode)
//Purpose:Which way to present the output
//Arguments:(string)the way the output being presented,(string)the way
//the data being read in,(string)the sorting type
//Return:none
void sortAlgs::which_output(string output,string origin,string mode)
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
string sortAlgs::txtName(string origin,string mode,int number)
{
        string a = to_string(number);
        return(origin + "_" + mode + "_" + a + "_" + "sorted");



}








//run(string mode,string output)
//Purpose:run the programm with two parameters
//Arguments:(string)the sorting tyoe,(string)the output type
//Return:none
void sortAlgs::run(string mode,string output)
{
        int line;
        while(cin >> line){
                vec.push_back(line);
        }
        which_alg(mode);
        which_output(output,"cin",mode);





}



//run(string mode,string output,string filename)
//Purpose:run the programm with three parameters
//Arguments:(string)the sorting tyoe,(string)the output type
//(string)the filename
//Return:none
void sortAlgs::run(string mode,string output,string filename)
{
        ifstream input;
        
        input.open(filename);

        if (not input.is_open()) {
                cerr << "Unable to open " << filename << endl;
                exit(1);
        }
        
        copy_strings_from(input);
        input.close();
        
        which_alg(mode);
        which_output(output,filename,mode);
        






}







//copy_strings_from(istream &infile)
//Purpose://Copy each string of non-whitespace characters 
//from the given input stream onto standard output (cout), 
//one string per line.
//Arguments:the address of the file input 
//Return:none
void sortAlgs::copy_strings_from(istream &infile)
{
        int line;
        
        while(infile >> line) 
                vec.push_back(line);
         
        
}








