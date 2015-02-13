//
//  main.cpp
//  Dijkstra
//
//  Created by Shiv chandra Kumar on 12/4/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Graph.h"

using namespace std;

int loc_size =0;
string line = "";
string str = "";
vector<edges> edges_of_graph;
int edges_size = 0;
int input_size = 0;

struct input_data{
    int source;
    int destination;
    string type;
};

vector <input_data> input ;


Graph graph;

//get the location names from location files.
string get_loc_name(vector<string> location)
{
    string name;
    for (int i = 0; i < location.size() - 1; i++)
    {
        name = name + location[i] + " ";
    }
    name = name + location[location.size() - 1];
    return name;
}


//build the location names from the location files
int get_loc_size(const char* filepath)
{
    ifstream loc_file;
    loc_file.open(filepath);
    vector<string> locations;
    if(loc_file.is_open()){
        while (getline(loc_file, line))
        {
            vector <string> loc;
            istringstream stream(line);
            while(stream>>str)
            {
                loc.push_back(str);
            }
            if (loc.size() == 1)
            {
                loc_size = atoi(loc[0].c_str());
            }
            if (loc.size() == 0 || loc[0] == "#" || loc.size() == 1)
            {
                continue;
            }
        }
    }
    else{
            cout<<"could not open the file"<<endl;
        }
        
    loc_file.close();
    return loc_size;
}



//get the location and store it into a Vector
vector<string> locations(const char* filepath)
{
    ifstream loc_file;
    loc_file.open(filepath);
    vector<string> locations_vector;
    while (getline(loc_file, line))
    {
        vector <string> loc;
        //split the line by space
        istringstream stream(line);
        while(stream>>str)
        {
            loc.push_back(str);
        }
        //get the loc_size from the input file
        if (loc.size() == 1)
        {
            //change string into int
            loc_size = atoi(loc[0].c_str());
        }
        if (loc.size() == 0 || loc[0] == "#" || loc.size() == 1)
        {
            continue;
        }
        else
        {
            //store locations_vector' name into vector locations_vector
            locations_vector.push_back(get_loc_name(loc));
        }
    }
    loc_file.close();
    return locations_vector; 
}



//get all the edges from the segment file
void get_edges(const char* filepath){
        ifstream loc_file;
        loc_file.open(filepath);
        edges segments;
        if(loc_file.is_open()){
            while (getline(loc_file, line))
            {
                vector <string> loc;
                istringstream stream(line);
                while(stream>>str)
                {
                    loc.push_back(str);
                }
                if (loc.size() == 4)
                {
                    segments.id1      = atoi(loc[0].c_str());
                    segments.id2      = atoi(loc[1].c_str());
                    segments.distance = atof(loc[2].c_str());
                    segments.speed    = atof(loc[3].c_str());
                    edges_of_graph.push_back(segments);
                }
                if (loc.size() == 1){
                    edges_size = atoi(loc[0].c_str());
                }
                if (loc.size() == 0 || loc[0] == "#" || loc.size() == 1)
                {
                    continue;
                }
            }
        }
        else{
            cout<<"could not open the file"<<endl;
        }
        
        loc_file.close();
    
}


//take out the input from the input file. read number of inputs and all the inputs.store it into a vector
void get_input(const char* filepath){
    ifstream loc_file;
    input_data input1;
    loc_file.open(filepath);
    if(loc_file.is_open()){
        while (getline(loc_file, line))
        {
            vector <string> loc;
            istringstream stream(line);
            while(stream>>str)
            {
                loc.push_back(str);
            }
            if (loc.size() == 3 && loc[0] != "#")
            {
                input1.source = atoi(loc[0].c_str());;
                input1.destination = atoi(loc[1].c_str());;
                input1.type = loc[2].c_str() ;
                input.push_back(input1);
            }
            if (loc.size() == 1){
                input_size = atoi(loc[0].c_str());
            }
            if (loc.size() == 0 || loc[0] == "#" || loc.size() == 1)
            {
                continue;
            }
        }
    }
    else{
        cout<<"could not open the file"<<endl;
    }
    
    loc_file.close();
    
}


//main operation is done here where graph is being asked to build and then calling the find distance
// method to get the shortest path between two locations
int main(int argc, const char * argv[]) {
    get_loc_size(argv[1]);
    vector<string> location = locations(argv[1]);

    get_edges(argv[2]);
    graph.form_graph(location, edges_of_graph, loc_size, edges_size);
    get_input(argv[3]);
    int y = 0;
    while(y < input_size){
        graph.find_distance(input[y].source , input[y].destination , input[y].type);
        y++;
    }
    
    return 0;
}


//"/Users/Shiv/Desktop/Program4Fall2014trips.txt"
