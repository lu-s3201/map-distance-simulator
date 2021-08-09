/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   Graph.h
 *   By: Luella (lsugim01)
 *   On: 4 Apr 2020
 *
 *   Description: header file for the Graph data structure - provides the
 *   interface of the Graph structure
 *
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <iostream>
#include <iomanip>

#include "Location.h"

using namespace std;

struct Vertex;

struct Vertex       {
     string name;
     Location location;
     vector<Vertex*> neighbors;
     bool visited;
};


class Graph         {
public:
     Graph();

     //structure functions
     void add_vertex(string name, double latitude, double longitude);
     void add_edge(string origin, string dest);

     //query functions
     void print_vertices();
     double find_distance(string origin, string dest);
     void print_paths(string origin, string dest, int max_paths);

private:
     vector<Vertex> map;
     vector<Vertex*> path;
     int num_paths;

     //helper functions
     Vertex *find_vertex(string name);
     void initialize_path();
     void find_paths(Vertex *from, Vertex *to, int max_paths);
     void report_path();
     int find_distance(Vertex *from, Vertex *to);

     //test functions
     void print_graph();

};

#endif















 //
