//
//  priorityQueue.cpp
//  Dijkstra
//
//  Created by Shiv chandra Kumar on 12/8/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#include "priorityQueue.h"

PriorityQueue::PriorityQueue()
{
    //head node (or index 0) will be kept out of bounds always.
    priorityQueueIndex = 1;
    PriorityQueueNode headNode;
    headNode.data = 0;
    headNode.key = 0;
    priorityQueue[0] = headNode;
}

PriorityQueue::~PriorityQueue()
{
    
}

void PriorityQueue::AddToQueue(int data, float key)
{
    PriorityQueueNode newEntry;
    newEntry.data = data;
    newEntry.key = key;
    AddToQueue(newEntry);
}

//Add key-value pair to the priority queue based on the key
void PriorityQueue::AddToQueue(PriorityQueueNode newData)
{
    priorityQueue[priorityQueueIndex] = newData;
    int parentIndex = priorityQueueIndex/2;
    PriorityQueueNode temp;
    int newDataIndex = priorityQueueIndex;
    while (parentIndex > 0) {
        //If key@parent is less than the key@new node, swap the two nodes
        if (priorityQueue[newDataIndex].key < priorityQueue[parentIndex].key) {
            temp = priorityQueue[parentIndex];
            priorityQueue[parentIndex] = priorityQueue[newDataIndex];
            priorityQueue[newDataIndex] = temp;
            newDataIndex = parentIndex;
        }
        //keep precolating up towards the root
        parentIndex = parentIndex/2;
    }
    priorityQueueIndex++;
}

//Method to delete the smallest element(by key) in the queue
int PriorityQueue::DeleteMin()
{
    int deletedData = -1;
    if (priorityQueueIndex == 1) {
        return deletedData; //in case this method is called on an empty queue
    }
    deletedData = priorityQueue[1].data;
    int currentIndex = 1;
    int child;
    PriorityQueueNode temp;
    priorityQueue[1] = priorityQueue[priorityQueueIndex-1];
    priorityQueueIndex--;
    while ((currentIndex * 2) < priorityQueueIndex) {
        child = currentIndex * 2;
        //Each parent has two child (not always), check which child represents a smaller key value
        if ((child != (priorityQueueIndex-1)) && (priorityQueue[child].key > priorityQueue[child+1].key))
        {
            child++;
        }
        if (priorityQueue[child].key < priorityQueue[currentIndex].key) {
            temp = priorityQueue[currentIndex];
            priorityQueue[currentIndex] = priorityQueue[child];
            priorityQueue[child] = temp;
        }else{
            break;
        }
        currentIndex = child;
    }
    return deletedData;
}

bool PriorityQueue::isEmpty()
{
    if (priorityQueueIndex == 1) {
        return true;
    }
    return false;
}

//Make the queue index 1. It will override the old data when a new data is added.
void PriorityQueue::ClearPriorityQueue()
{
    priorityQueueIndex = 1;
}

//Method to be used only for testing purposes
void PriorityQueue::Debug()
{
    std::cout<<"Debug:"<<std::endl;
    for (int index = 1; index < priorityQueueIndex; index++) {
        std::cout<<priorityQueue[index].data<<std::endl;
    }
}
