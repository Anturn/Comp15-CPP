// Hw2
// testCharLinkedList.cpp : The file for testing all the functions in CharLinkedlIST.cpp
// Rui Qin
// 9/16/2016

#include <iostream>
#include "CharLinkedList.h"
using namespace std;

int main()
{        
        
        ///////////////////////////////TESTING//////////////////////////////
        ////////////////Testing case for basic case///////////////////////
        
        
        CharLinkedList LinkedList1; // Class LinkedList1 is initialized witohut parameter
        CharLinkedList LinkedList2('q'); // Class LinkedList2 is initialized with a parameter
        
        
        

        //Test 1:isEmpty()
        //Test the function "isEmpty", if the linked list is emmty,they
        //prints out the linked list is empty, if not, then prints out
        //the linked list is not empty
        
        if(LinkedList1.isEmpty()){
                cout << "The LinkedList1 is empty " <<endl;
                
        }else{
        
                cout << "The LinkedList1 is not empty " <<endl;
        }
        
        if(LinkedList2.isEmpty()){
                cout << "The LinkedList2 is empty " <<endl;
                
        }else{
        
                cout << "The LinkedList2 is not empty " <<endl;
        }
        
        
        
        
        //Test 2:size()
        //Test how many number of chars in the linked list

        cout << "The size of the LinkedList1, that is the number of elements is ";
        cout << LinkedList1.size() << endl;
        
        cout << "The size of the LinkedList2, that is the number of elements is ";
        cout << LinkedList2.size() << endl;


        //Test 3:clear()
        //Test if the linked list gets cleared
        
        LinkedList1.clear();
        LinkedList2.clear();
        
        if(LinkedList1.isEmpty()){        
                cout << "The clear() works well in LinkedList1 because the linked list is empty now" <<endl;
        }else{
                cout << "The clear() works not really well in LinkedList1, because the linked list is not cleared" <<endl;
        }
        
        if(LinkedList2.isEmpty()){        
                cout << "The clear() works well in LinkedList2 because the linked list is empty now" <<endl;
        }else{
                cout << "The clear() works not really well in LinkedList2, because the linked list is not cleared" <<endl;
        }

        
        
        
        //Test 4:insertAtFront()
        //Test wether the function really insert the specific char into the front of linked list
        
        cout << "\nTest 4 for insertAtFront()" <<endl;
        
        cout << "Insert the char 'b' in the front of the LinkedList1:" << endl;
        LinkedList1.insertAtFront('b');
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 1 <<b>>]
        cout << endl;
        
        cout << "Insert the char 'c' in the front of the LinkedList1:" << endl;
        LinkedList1.insertAtFront('c');
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 2 <<cb>>]
        cout << endl;
        
        cout << "Insert the char 'A' in the front of the LinkedList2:" << endl;
        LinkedList2.insertAtFront('A');
        LinkedList2.print(); //Here the outcome should be: [CharLinkedList of size 1 <<A>>]
        cout << endl;
        
        cout << "Insert the char 'Z' in the front of the LinkedList2:" << endl;
        LinkedList2.insertAtFront('Z');
        LinkedList2.print(); ///Here the outcome should be: [CharLinkedList of size 1 <<ZA>>]
        cout << endl;
        

        //Test 5:first()
        //Test prints out the first char in the linked list
        
        cout << "\nTest 5 for first()" <<endl;
        
        cout << "The first char in the LinkedList1 is:" << endl;
        cout << LinkedList1.first() << endl; //Here the outcome should be: c
        
        cout << "The first char in the LinkedList2 is:" << endl;
        cout << LinkedList2.first() << endl; //Here the outcome should be: Z
        
        
        
        //Test 6:insertAtBack()
        //Test wether the function really insert the specific char into the back of linked list
        
        cout << "\nTest 6 for insertAtBack()" <<endl;
        
        cout << "Insert the char '!' in the back of the LinkedList1:" << endl;
        LinkedList1.insertAtBack('!');
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 3 <<cb!>>]
        cout << endl;
        
        cout << "Insert the char '?' in the front of the LinkedList1:" << endl;
        LinkedList1.insertAtBack('?');
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 4 <<cb!?>>]
        cout << endl;
        
        cout << "Insert the char '9' in the front of the LinkedList2:" << endl;
        LinkedList2.insertAtBack('9');
        LinkedList2.print(); ///Here the outcome should be: [CharLinkedList of size 3 <<ZA9>>]
        cout << endl;
        
        cout << "Insert the char '1' in the front of the LinkedList2:" << endl;
        LinkedList2.insertAtBack('1');
        LinkedList2.print(); ///Here the outcome should be: [CharLinkedList of size 4 <<ZA91>>]
        cout << endl;
        
        //Test 7:removeFromFront()
        //Test wether the function really remove the first char from linked list
        
        cout << "\nTest 7 for removeFromFront()" <<endl;
        
        cout << "Remove the char from the front of the LinkedList1:" << endl;
        LinkedList1.removeFromFront();
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 3 <<b!?>>]
        cout << endl;
        
        cout << "Remove the char from the front of the LinkedList1:" << endl;
        LinkedList1.removeFromFront();
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 2 <<!?>>]
        cout << endl;
        
        cout << "Remove the char from the front of the LinkedList2:" << endl;
        LinkedList2.removeFromFront();
        LinkedList2.print(); //Here the outcome should be: [CharLinkedList of size 3 <<A91>>]
        cout << endl;
        
        cout << "Remove the char from the front of the LinkedList2:" << endl;
        LinkedList2.removeFromFront();
        LinkedList2.print(); ///Here the outcome should be: [CharLinkedList of size 2 <<91>>]
        cout << endl;
        
        //Test 8:last()
        //Test prints out the last char in the linked list
        
        cout << "\nTest 8 for last()" <<endl;
        
        cout << "The last char in the LinkedList1 is:" << endl;
        cout << LinkedList1.last() << endl; //Here the outcome should be: ?
        cout << "The last char in the LinkedList2 is:" << endl;
        cout << LinkedList2.last() << endl; //Here the outcome should be: 1

        
        //Test 9:elementAt(int index)
        //Test the char in specific position
        cout << "\nTest 9 for elementAt(int index)" << endl;
        
        cout << "The char with index 1 in LinkedList1 is" << endl;
        cout << LinkedList1.elementAt(1) << endl;
        
        cout << "The char with index 0 in LinkedList2 is" << endl;
        cout << LinkedList2.elementAt(0) << endl;
        
       
        
        //Test 10:removeFromBack()
        //Test wether the function really remove the last char from linked list
        
        cout << "\nTest 10 for removeFromBack()" <<endl;
        
        cout << "Remove the char from the back of the LinkedList1:" << endl;
        LinkedList1.removeFromBack();
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 1 <<!>>]
        cout << endl;
        
        cout << "Remove the char from the back of the LinkedList1" << endl;
        LinkedList1.removeFromBack();
        LinkedList1.print(); //Here the outcome should be: [CharLinkedList of size 0 <<>>]
        cout << endl;
        
        cout << "Remove the char from the back of the LinkedList2" << endl;
        LinkedList2.removeFromBack();
        LinkedList2.print(); //Here the outcome should be: [CharLinkedList of size 1 <<9>>]
        cout << endl;
        
        cout << "Remove the char from the back of the LinkedList2" << endl;
        LinkedList2.removeFromBack();
        LinkedList2.print(); ///Here the outcome should be: [CharLinkedList of size 0 <<>>]
        cout << endl;
        
        
        /*cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
        LinkedList2.insertAtBack('k');
        LinkedList2.print();
        */
        
        
        
        


        //Test 11:concatenate(Char *anotherClass)
        //Test the char in specific position
        
        cout << "\nTest 11 for concatenate(Char *anotherClass)" <<endl;

        cout << "We create a new LinkedList1 with char 'a' and 'b' with function insertAtBack().";
        cout << "Then we should get: " << endl;
        LinkedList1.insertAtBack('a');
        LinkedList1.insertAtBack('b');
        LinkedList1.print();
        cout << endl;
        
        cout << "We create a new LinkedList2 with char 'c' and 'd' with function insertAtBack().";
        cout << "Then we should get: " << endl;
        LinkedList2.insertAtBack('c');
        LinkedList2.insertAtBack('d');
        LinkedList2.print();
        cout << endl;
        
        cout << "By using the function concatenate(Char *anotherClass)"<< endl;
        cout << "we consider LinkedList2 as the added one and LinkedList1 as the formal one"<< endl;
        cout << "then we combine them togather with LinkedList1.concatenate(&LinkedList2), we get:" <<endl;

        
        LinkedList1.concatenate(&LinkedList2);
        LinkedList1.print();
        cout << endl;
        
        
        
        
        
        ///////////////////////////////TESTING//////////////////////////////
        ////////////////Testing case for exception and special case///////////////////////
        //WARNING: For all the pragramm below, I comment all of those in order to show my "glorious" 
        // work above. Just uncomment the code below. Thank you! 
        
        //CharLinkedList LinkedList3; // The LinkedList3 here initialized without parameters
        
        //LinkedList3.first(); //Because there is no char in linked list yet, there is an abortion here
                           //and the programm will terminate here
        
        
        
        //LinkedList3.last(); //Because there is no char in linked list yet, there is an abortion here
                           //and the programm will terminate here
        
        //LinkedList3.elementAt(2); //Because there is no char in linked list yet, there is an abortion here
                                //and the programm will terminate here
        
        
        /*cout << "We add three chars to the LinkedList3 with 'a' 'b' and 'c'" <<endl;
        LinkedList3.insertAtBack('a');
        LinkedList3.insertAtBack('b');
        LinkedList3.insertAtBack('c');
   
        LinkedList3.elementAt(2); // If the index is in the range, then the programm runs successfull
        
        cout <<  LinkedList3.elementAt(2) << endl;
        LinkedList3.elementAt(4); // If the index is out of range, the there is an abortion here and 
                                // the programm will terminate here
        cout <<  LinkedList3.elementAt(4) << endl;
        */
        
        /*cout << "We add three chars to the LinkedList3 with '1' '2' and '3'" <<endl;
        LinkedList3.insertAtBack('1');
        LinkedList3.insertAtBack('2');
        LinkedList3.insertAtBack('3');
        
        LinkedList3.insertAt('a',2); // If the index here is in the range and rational, the programm 
        LinkedList3.print();            // succeeds to run and prints out
        cout << endl;
        
        LinkedList3.insertAt('k',7); // If the index here is out of the range and inrational, the programm 
        LinkedList3.print();         // gives abortion and terminates
        cout << endl;
        */
        
        
        
        /*cout << "We add three chars to the LinkedList3 with 'A' 'B' and 'C'" <<endl;
        LinkedList3.insertAtBack('A');
        LinkedList3.insertAtBack('B');
        LinkedList3.insertAtBack('C');
        
        
        
        LinkedList3.removeFrom(2); // If the index here is in the range and rational, the programm 
        LinkedList3.print();            // succeeds to run and prints out
        cout << endl;
        
        LinkedList3.removeFrom(7); // If the index here is out of the range and inrational, the programm 
        LinkedList3.print();         // gives abortion and terminates
        cout << endl;
        */
        
        
        
        /*cout << "We add three chars to the LinkedList3 with 'Q' 'W' and 'E'" <<endl;
        LinkedList3.insertAtBack('Q');
        LinkedList3.insertAtBack('W');
        LinkedList3.insertAtBack('E');
        
        LinkedList3.replace('q',2); // If the index here is in the range and rational, the programm 
        LinkedList3.print();          // succeeds to run and prints out
        cout << endl;
        
        
        LinkedList3.replace('1',4); // If the index here is out of the range and inrational, the programm 
        LinkedList3.print();          // gives abortion and terminates
        cout << endl;
        */
        
        
        /*cout << "We add three chars to the LinkedList3 with 'a' 'k' 'z' 'a' 'x'and 's'" <<endl;
        LinkedList3.insertInOrder('a');
        LinkedList3.insertInOrder('k');
        LinkedList3.insertInOrder('z');
        LinkedList3.insertInOrder('a');
        LinkedList3.insertInOrder('x');
        LinkedList3.insertInOrder('s');
        LinkedList3.print();
        */
        
        

}










