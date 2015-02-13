//
//  priorityQueue.h
//  Dijkstra
//
//  Created by Shiv chandra Kumar on 12/8/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#ifndef __Dijkstra__priorityQueue__
#define __Dijkstra__priorityQueue__

#include <stdio.h>
#include <iostream>

//structure defining the node of a priority queue
struct PriorityQueueNode{
    float key;  //Sorting will be done on the basis of key only
    int data;
};

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();
    int DeleteMin(); //Retreive the smallest element from the queue
    void AddToQueue(int data, float key); //Add data to the queue (only prepares data to be added)
    bool isEmpty();
    void ClearPriorityQueue(); //Clear the queue
    void Debug(); //Method to debug the queue
private:
    void AddToQueue(PriorityQueueNode data); //Method that actually does the addition of data to the queue
    PriorityQueueNode priorityQueue[100]; //priority queue of size 100
    int priorityQueueIndex; //index to track the queues length
};

#endif /* defined(__Dijkstra__priorityQueue__) */
