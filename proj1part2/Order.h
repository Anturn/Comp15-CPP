/*
 * Order.h
 * Written by: Max Bernstein and Erica Schwartz
 * Fall 2016
 *
 * Defines an Order struct that holds the data for a Nozama order
 */

#ifndef ORDER_H
#define ORDER_H

struct Order {
        int id;
        int arrival_timestamp;  /* aka "arrival time" */
        int fetch_duration;     /* aka "fetch time"   */
        int pack_duration;      /* aka "pack time"    */
        int fetch_time_left;
        int pack_time_left;
        
        int FS_waitingTime; //The time the order waits in the FetchStation
        int PS_waitingTime; //The time the order waits in the PackingStation
        int total_time;     //The total time the order finish processing
        
        
        
};

#endif
