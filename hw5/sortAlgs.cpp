// Hw5
// sortAlgs.cpp : The file for testing all the functions in sortAlgs.cpp
// Rui Qin
// 10/30/2016

#include "sortAlgs.h"




//insertionSort(vector<int> &vec)
//Purpose:This is a sorting method called insertion 
//sort in group 1
//Arguments:(vector<int>)pass the vec by reference
//Return:none
void insertionSort(vector<int> &vec)
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



//shellSort(vector<int> &vec)
//Purpose:This is a sorting method called insertion
//sort in group 2
//Arguments:(vector<int>)pass the vec by reference
//Return:none
void shellSort(vector<int> &vec)
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


//quickSort(vector<int>& vec1,int left, int right)
//Purpose:This is a soting method called quicksort
//in group 2
//(vector<int>)pass the vec by reference,(int)the 
//index of the left int,(int)the index of the right
//int
//Return:none

void quickSort(vector<int>& vec,int left, int right) {
        
        quickSort_helper(vec,left,right);
                
}



//quickSort_helper(vector<int>& vec,int left, int right)
//Purpose:Recursive version for quick sort, the helper function
//for the quickSort function
//(vector<int>)pass the vec by reference,(int)the 
//index of the left int,(int)the index of the right
//int
//Return:none
void quickSort_helper(vector<int>& vec,int left, int right){

        
      int i = left, j = right;
      int tmp;
      int pivot = vec[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (vec[i] < pivot)
                  i++;
            while (vec[j] > pivot)
                  j--;
            if (i <= j){ 
                  tmp = vec[i];
                  vec[i] = vec[j];
                  vec[j] = tmp;
                  i++;
                  j--;
            }
      }
 
      /* recursion */
      if (left < j)
            quickSort_helper(vec, left, j);
      if (i < right)
            quickSort_helper(vec, i, right);

        
      
      
}







