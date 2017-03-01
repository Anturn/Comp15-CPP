// testCharSequence.cpp : The file for testing all the functions in CharSequence.cpp
// Rui Qin
// 9/13/2016

#include <iostream>
#include "CharSequence.h"
using namespace std;




int main()
{        
        
        ///////////////////////////////TESTING//////////////////////////////
        ////////////////Testing case for basic case///////////////////////
        
        
        
        
        CharSequence Sequence1; // Class Sequence1 is initialized witohut parameter
        CharSequence Sequence2('q'); // Class Sequence2 is initialized with a parameter
        
        
        

        //Test 1:isEmpty()
        //Test the function "isEmpty", if the sequence is emmty,they
        //prints out the sequence is empty, if not, then prints out
        //the sequence is nopt empty
        
        if(Sequence1.isEmpty()){
                cout << "The Sequence1 is empty " <<endl;
                
        }else{
        
                cout << "The Sequence1 is not empty " <<endl;
        }
        
        if(Sequence2.isEmpty()){
                cout << "The Sequence2 is empty " <<endl;
                
        }else{
        
                cout << "The Sequence2 is not empty " <<endl;
        }
        
        
        
        
        //Test 2:size()
        //Test how many number of chars in the sequence

        cout << "The size of the Sequence1, that is the number of elements is ";
        cout << Sequence1.size() << endl;
        
        cout << "The size of the Sequence2, that is the number of elements is ";
        cout << Sequence2.size() << endl;


        //Test 3:clear()
        //Test if the sequence gets cleared
        
        Sequence1.clear();
        Sequence2.clear();
        
        if(Sequence1.isEmpty()){        
                cout << "The clear() works well in Sequence1 because the sequence is empty now" <<endl;
        }else{
                cout << "The clear() works not really well in Sequence1, because the sequence is not cleared" <<endl;
        }
        
        if(Sequence2.isEmpty()){        
                cout << "The clear() works well in Sequence2 because the sequence is empty now" <<endl;
        }else{
                cout << "The clear() works not really well in Sequence2, because the sequence is not cleared" <<endl;
        }

        
        
        
        //Test 4:insertAtFront()
        //Test wether the function really insert the specific char into the front of sequence
        
        cout << "\nTest 4 for insertAtFront()" <<endl;
        
        cout << "Insert the char 'b' in the front of the Sequence1:" << endl;
        Sequence1.insertAtFront('b');
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 1 <<b>>]
        cout << endl;
        
        cout << "Insert the char 'c' in the front of the Sequence1:" << endl;
        Sequence1.insertAtFront('c');
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 2 <<cb>>]
        cout << endl;
        
        cout << "Insert the char 'A' in the front of the Sequence2:" << endl;
        Sequence2.insertAtFront('A');
        Sequence2.print(); //Here the outcome should be: [CharSequence of size 1 <<A>>]
        cout << endl;
        
        cout << "Insert the char 'Z' in the front of the Sequence2:" << endl;
        Sequence2.insertAtFront('Z');
        Sequence2.print(); ///Here the outcome should be: [CharSequence of size 1 <<ZA>>]
        cout << endl;
        

        //Test 5:first()
        //Test prints out the first char in the sequence
        
        cout << "\nTest 5 for first()" <<endl;
        
        cout << "The first char in the Sequence1 is:" << endl;
        cout << Sequence1.first() << endl; //Here the outcome should be: c
        
        cout << "The first char in the Sequence2 is:" << endl;
        cout << Sequence2.first() << endl; //Here the outcome should be: Z
        
        
        
        //Test 6:insertAtBack()
        //Test wether the function really insert the specific char into the back of sequence
        
        cout << "\nTest 6 for insertAtBack()" <<endl;
        
        cout << "Insert the char '!' in the back of the Sequence1:" << endl;
        Sequence1.insertAtBack('!');
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 3 <<cb!>>]
        cout << endl;
        
        cout << "Insert the char '?' in the front of the Sequence1:" << endl;
        Sequence1.insertAtBack('?');
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 4 <<cb!?>>]
        cout << endl;
        
        cout << "Insert the char '9' in the front of the Sequence2:" << endl;
        Sequence2.insertAtBack('9');
        Sequence2.print(); ///Here the outcome should be: [CharSequence of size 3 <<ZA9>>]
        cout << endl;
        
        cout << "Insert the char '1' in the front of the Sequence2:" << endl;
        Sequence2.insertAtBack('1');
        Sequence2.print(); ///Here the outcome should be: [CharSequence of size 4 <<ZA91>>]
        cout << endl;
        
        //Test 7:removeFromFront()
        //Test wether the function really remove the first char from sequence
        
        cout << "\nTest 7 for removeFromFront()" <<endl;
        
        cout << "Remove the char from the front of the Sequence1:" << endl;
        Sequence1.removeFromFront();
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 3 <<b!?>>]
        cout << endl;
        
        cout << "Remove the char from the front of the Sequence1:" << endl;
        Sequence1.removeFromFront();
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 2 <<!?>>]
        cout << endl;
        
        cout << "Remove the char from the front of the Sequence2:" << endl;
        Sequence2.removeFromFront();
        Sequence2.print(); //Here the outcome should be: [CharSequence of size 3 <<A91>>]
        cout << endl;
        
        cout << "Remove the char from the front of the Sequence2:" << endl;
        Sequence2.removeFromFront();
        Sequence2.print(); ///Here the outcome should be: [CharSequence of size 2 <<91>>]
        cout << endl;
        
        //Test 8:last()
        //Test prints out the last char in the sequence
        
        cout << "\nTest 8 for last()" <<endl;
        
        cout << "The last char in the Sequence1 is:" << endl;
        cout << Sequence1.last() << endl; //Here the outcome should be: ?
        cout << "The last char in the Sequence2 is:" << endl;
        cout << Sequence2.last() << endl; //Here the outcome should be: 1

        
        //Test 9:elementAt(int index)
        //Test the char in specific position
        cout << "\nTest 9 for elementAt(int index)" << endl;
        
        cout << "The char with index 1 in Sequence1 is" << endl;
        cout << Sequence1.elementAt(1) << endl;
        
        cout << "The char with index 0 in Sequence2 is" << endl;
        cout << Sequence2.elementAt(0) << endl;
        
        
        
        //Test 10:removeFromBack()
        //Test wether the function really remove the last char from sequence
        
        cout << "\nTest 10 for removeFromBack()" <<endl;
        
        cout << "Remove the char from the back of the Sequence1:" << endl;
        Sequence1.removeFromBack();
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 1 <<!>>]
        cout << endl;
        
        cout << "Remove the char from the back of the Sequence1" << endl;
        Sequence1.removeFromBack();
        Sequence1.print(); //Here the outcome should be: [CharSequence of size 0 <<>>]
        cout << endl;
        
        cout << "Remove the char from the back of the Sequence2" << endl;
        Sequence2.removeFromBack();
        Sequence2.print(); //Here the outcome should be: [CharSequence of size 1 <<9>>]
        cout << endl;
        
        cout << "Remove the char from the back of the Sequence2" << endl;
        Sequence2.removeFromBack();
        Sequence2.print(); ///Here the outcome should be: [CharSequence of size 0 <<>>]
        cout << endl;
        


        //Test 11:concatenate(Char *anotherClass)
        //Test the char in specific position
        
        cout << "\nTest 11 for concatenate(Char *anotherClass)" <<endl;

        cout << "We create a new Sequence1 with char 'a' and 'b' with function insertAtBack().";
        cout << "Then we should get: " << endl;
        Sequence1.insertAtBack('a');
        Sequence1.insertAtBack('b');
        Sequence1.print();
        cout << endl;
        
        cout << "We create a new Sequence2 with char 'c' and 'd' with function insertAtBack().";
        cout << "Then we should get: " << endl;
        Sequence2.insertAtBack('c');
        Sequence2.insertAtBack('d');
        Sequence2.print();
        cout << endl;
        
        cout << "By using the function concatenate(Char *anotherClass)"<< endl;
        cout << "we consider Sequence2 as the added one and Sequence1 as the formal one"<< endl;
        cout << "then we combine them togather with Sequence1.concatenate(&Sequence2), we get:" <<endl;

        
        Sequence1.concatenate(&Sequence2);
        Sequence1.print();
        cout << endl;
        
        
        
        
        
        ///////////////////////////////TESTING//////////////////////////////
        ////////////////Testing case for exception and special case///////////////////////
        //WARNING: For all the pragramm below, I comment all of those in order to show my "glorious" 
        // work above. Just uncomment the code below. Thank you! 
        
        CharSequence Sequence3; // The Sequence3 here initialized without parameters
        
        //Sequence3.first(); //Because there is no char in Sequence yet, there is an abortion here
                           //and the programm will terminate here
        
        
        
        //Sequence3.last(); //Because there is no char in Sequence yet, there is an abortion here
                           //and the programm will terminate here
        
        //Sequence3.elementAt(2); //Because there is no char in Sequence yet, there is an abortion here
                                //and the programm will terminate here
        
        
        /*cout << "We add three chars to the Sequence3 with 'a' 'b' and 'c'" <<endl;
        Sequence3.insertAtBack('a');
        Sequence3.insertAtBack('b');
        Sequence3.insertAtBack('c');
        
        Sequence3.elementAt(2); // If the index is in the range, then the programm runs successfully
        Sequence3.elementAt(4); // If the index is out of range, the there is an abortion here and 
                                // the programm will terminate here
        */
        
        
        /*cout << "We add three chars to the Sequence3 with '1' '2' and '3'" <<endl;
        Sequence3.insertAtBack('1');
        Sequence3.insertAtBack('2');
        Sequence3.insertAtBack('3');
        
        Sequence3.insertAt('a',2); // If the index here is in the range and rational, the programm 
        Sequence3.print();            // succeeds to run and prints out
        cout << endl;
        
        Sequence3.insertAt('k',7); // If the index here is out of the range and inrational, the programm 
        Sequence3.print();         // gives abortion and terminates
        cout << endl;
        */
        
        
        
        /*cout << "We add three chars to the Sequence3 with 'A' 'B' and 'C'" <<endl;
        Sequence3.insertAtBack('A');
        Sequence3.insertAtBack('B');
        Sequence3.insertAtBack('C');
        
        
        
        Sequence3.removeFrom(2); // If the index here is in the range and rational, the programm 
        Sequence3.print();            // succeeds to run and prints out
        cout << endl;
        
        Sequence3.removeFrom(7); // If the index here is out of the range and inrational, the programm 
        Sequence3.print();         // gives abortion and terminates
        cout << endl;
        */
        
        
        
        /*cout << "We add three chars to the Sequence3 with 'Q' 'W' and 'E'" <<endl;
        Sequence3.insertAtBack('Q');
        Sequence3.insertAtBack('W');
        Sequence3.insertAtBack('E');
        
        Sequence3.replace('q',0); // If the index here is in the range and rational, the programm 
        Sequence3.print();          // succeeds to run and prints out
        cout << endl;
        
        
        Sequence3.replace('1',4); // If the index here is out of the range and inrational, the programm 
        Sequence3.print();          // gives abortion and terminates
        cout << endl;
        */
        

}










