#include "StringBST.h"




int main()
{


        //string A[12] ;
        //A = ["daad]
        StringBST K;
        K.add("Ram");
        K.add("Horse");
        K.add("Swan");
        K.add("Horse");
        K.add("Swan");
        K.add("Kingfisher");
        K.add("Swan");
        K.add("Bison");
        K.add("Llama");
        K.add("Deer");
        K.add("Deer");
        K.add("Deer");
        K.add("Deer");
        K.add("Llama");
        K.print();
        cout << endl;
        cout << "The size of the tree " << K.size() << endl;
        
        /*
        string max = K.getMax();
        cout <<"This is the max string in the tree " << max <<endl;
        string min = K.getMin();
        cout <<"This is the min string in the tree " << min <<endl;
        */
        
        
//         K.remove("Ram");
//         K.remove("Horse");
//         K.remove("Swan");
//         K.remove("Llama");
//         K.remove("Deer");
//         K.remove("Deer");
//         K.remove("Horse");
//         K.remove("Swan");
//         K.remove("Kingfisher");
//         K.remove("Swan");
//         K.remove("Bison");
        
        
        
        
        
        //K.remove("Bison");
        //K.print();
        
        
        //K.clear();
         K.removeMin();
        K.removeMin();
         K.removeMin();
         K.removeMin();
         K.removeMin();
         K.removeMin();
         K.removeMin();
         K.removeMin();
         K.removeMin();
         K.removeMin();
        
         //K.print();
//          //cout << endl;
        K.removeMin();
        K.removeMin();
//         //K.removeMin();
//         //K.removeMin();
//         
         K.print();
//         cout << endl;
//         
//          K.removeMax();
//          K.removeMax();
//          K.removeMax();
//          K.print();
        
        /*if(K.contains("Swann")){
                cout << "contains is true" << endl;
        }else{
                cout << "contains is false" << endl;
        }
        */
        cout << "The size of the tree " << K.size() << endl;
        
        return 0;
        



}