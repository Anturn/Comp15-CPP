#include "Orderqueue.h"
#include "Order.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{

//struct Order {
  //      int id;
    //    int arrival_timestamp;  /* aka "arrival time" */
      //  int fetch_duration;     /* aka "fetch time"   */
        //int pack_duration;      /* aka "pack time"    */
       // int fetch_time_left;
        //int pack_time_left;
//};




         /*Order order1;
         order1.id = 2222;
         Orderqueue QR;
        
         QR.Enqueue(order1);
         cout << QR.isEmpty()<< endl;
         
         Order order = QR.Dequeue();
         cout <<"The id for the new order is" << order.id << endl;
         cout << QR.isEmpty()<< endl;
         */
          Orderqueue QR;
         Order order1,order2,order3,order4,order5,order6,order7;
         QR.Enqueue(order1);
          QR.Enqueue(order2);
           QR.Enqueue(order3);
            QR.Enqueue(order4);
             QR.Enqueue(order5);
              QR.Enqueue(order6);
               QR.Enqueue(order7);
               cout << QR.size() << endl;
         
         return 0;
}