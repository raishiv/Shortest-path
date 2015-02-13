//
//  Graph.cpp
//  Dijkstra
//
//  Created by Shiv chandra Kumar on 12/4/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

PriorityQueue pqueue;
int source_vertex;
float diff;


//Build the graph with taking locations as vertices and segements as vertices.
//Build and adjacency list type of graph structure.
void Graph::form_graph(vector<string> vertex, vector<edges> edge, int no_of_vertex, int no_of_edges){
    count_edges = no_of_edges;
    count_vertex = no_of_vertex;
    for(int i = 0 ; i < no_of_vertex; i++){
        vertices graph_vertex ;
        graph_vertex.id = i;
        graph_vertex.name = vertex[i];
        for(int j= 0 ; j< no_of_edges ; j++){
            if(edge[j].id1 == i){
                graph_vertex.head.push_back(edge[j]);
            }
        }
        graph.push_back(graph_vertex);
    }
    
    
}



//Dijkstra's algorithm implementation to find the shortest distance between any two nodes in a graph
void Graph::dijkstra(int source , string type){
    source_vertex = source ;
    pqueue.ClearPriorityQueue();
    int data = 0;
    float key = 0.0;
    for(int i = 0 ; i < count_vertex ; i++){
            graph[i].known = false;
            graph[i].weight = infinity;
            graph[i].pred = NULL;
        }
    data = source;
    graph[source].weight = 0;
    key = graph[source].weight;
    pqueue.AddToQueue(data, key);
    
    while (!pqueue.isEmpty()) {
        float d = 0;
        int index =  pqueue.DeleteMin();
        graph[index].known = true;
        int adj_id ;
        for(int j = 0 ; j< graph[index].head.size() ; j++){
            adj_id = graph[index].head[j].id2;
            
            if(type == "D"){
                d = graph[index].weight + graph[index].head[j].distance ;
            }
            else{
                d = graph[index].weight + float((graph[index].head[j].distance) /(graph[index].head[j].speed));
            }
            if(graph[adj_id].known == false && d < graph[adj_id].weight){
                graph[adj_id].weight = d ;
                pqueue.AddToQueue(graph[adj_id].id, graph[adj_id].weight);
                graph[adj_id].pred = &graph[index];
            }
        }
            
    }
    return;
    
}



//Find the distance between the source and destination node provided from the input file

void Graph::find_distance(int source , int dest , string type){
    dijkstra(source, type);
    cout<<"Shortest distance from "<<graph[source].name<<" to "<<graph[dest].name<<":"<<endl;
    cout<<endl;
    cout<<"Start at "<<graph[source_vertex].name<<endl;
    if(type == "D"){
        print_graph(dest);
        cout<<endl;
        cout<<"Total Distance: "<<graph[dest].weight<<" miles"<<endl;
    }
    else{
       print_graph_time(dest);
        cout<<endl;
        int min = (graph[dest].weight * 3600)/60;
        int sec = (int(graph[dest].weight * 3600))%60;
        cout<<"Total time: "<<min<<" minutes"<<" & "<<sec<<" seconds"<<endl;
    }
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    return;
}



//Print the information which asks for distance(in mile)
void Graph::print_graph(int dest){
    
    if(graph[dest].pred->id != source_vertex){
        print_graph(graph[dest].pred->id);
    }
    diff = graph[dest].weight - graph[dest].pred->weight;
    
    cout<<"Continue to "<<graph[dest].name;
    cout<<"("<<diff<<" miles"<<")"<<endl;
    return;
}



//Print the information as output in form of time.
void Graph::print_graph_time(int dest){
    if(graph[dest].pred->id != source_vertex){
        print_graph_time(graph[dest].pred->id);
    }
    diff = graph[dest].weight - graph[dest].pred->weight;
    diff = diff * 3600;
    int min = int(diff/60);
    int sec = (int(diff) % 60);
    cout<<"("<<min<<" minutes"<<" & "<<sec<<" seconds"<<")"<<endl;
    cout<<"Continue to "<<graph[dest].name;
    
    return;
}



