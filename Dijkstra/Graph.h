//
//  Graph.h
//  Dijkstra
//
//  Created by Shiv chandra Kumar on 12/4/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#ifndef __Dijkstra__Graph__
#define __Dijkstra__Graph__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
# include "priorityQueue.h"
#define infinity 20000.0; 

using namespace std;

struct edges{
    int id1;
    int id2;
    float distance;
    float speed;
};

struct vertices{
    int id;
    string name;
    float weight;
    bool known;
    vector<edges> head;
    vertices* pred;
};

class Graph{
public:
    vector<vertices> graph;
    void form_graph(vector<string> , vector<edges> , int ,int);
    int count_vertex ;
    int count_edges ;
    void dijkstra(int , string);
    void print_graph(int);
    void find_distance( int , int ,string);
    void print_graph_time(int);
};


#endif /* defined(__Dijkstra__Graph__) */
