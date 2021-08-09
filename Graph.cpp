/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   Graph.cpp
 *   By: Luella (lsugim01)
 *   On: 4 Apr 2020
 *
 *   Description: header file for the Graph data structure - provides the
 *   implementation of the Graph structure
 *
 */

#include "Graph.h"


/*
* Purpose: instantiates a Graph object
*/
Graph::Graph()      {

     //done in header

}


/*
* Arguments: place name, latitude coordinates, longitude coordinates
     (in minutes)
* Purpose: adds a Vertex object containing the given information into the Graph
*/
void Graph::add_vertex(string name, double latitude, double longitude)     {

     //make Vertex with the given values
     Vertex v;
     v.name = name;
     v.location.set_location(latitude, longitude);

     //add to the vector representing the graph
     map.push_back(v);

}


/*
* Arguments: names of origin and destination locations
* Purpose: adds an edge in the graph, from the origin Vertex to the
     destination Vertex
*/
void Graph::add_edge(string origin, string dest)       {

     //find Vertex objects corresponding to the given location names
     Vertex *from = find_vertex(origin);
     Vertex *to = find_vertex(dest);

     //add as neighbor
     from->neighbors.push_back(to);

}


/*
* Purpose: prints the names of all vertices
*/
void Graph::print_vertices()    {

     for (size_t i = 0; i < map.size(); i++)    {
          cout << map[i].name << endl;
     }

}


/*
* Arguments: names of origin and destination locations and the maximum number
     of paths to print
* Function: finds paths from the origin location to the destination location,
     and prints out as many as requested (if available)
*/
void Graph::print_paths(string origin, string dest, int max_paths)         {

     initialize_path();

     //find Vertex objects corresponding to the given location names
     Vertex *from = find_vertex(origin);
     Vertex *to = find_vertex(dest);

     //if any city isn't in the database, alert the user and exit the query
     if (!from or !to)   {
          cout << "ERROR: unknown city" << endl;
          return;
     }

     find_paths(from, to, max_paths);

     //if there is not path, alert the user
     if (num_paths == 0)      {
          cout << "ERROR: no-path-possible" << endl;
     } else {
          cout << "-EOT-" << endl;
     }

}


/*
* Purpose: initializes the path vector to accomodate fo a new set of paths
*/
void Graph::initialize_path()        {

     //mark all nodes as not visited
     for (size_t i = 0; i < map.size(); i++)      {
          map[i].visited = false;
     }

     //clear the path vector for a new set of paths
     path.clear();
     path.insert(path.begin(), nullptr);

     num_paths = 0;

}


/*
* Arguments: pointer to origin and destination Vertex objects & maximum number
     of paths to print
* Purpose: finds and prints paths form the origin to destination, printing
     either the total paths or the given maximum number of paths
*/
void Graph::find_paths(Vertex *from, Vertex *to, int max_paths)       {

     if (num_paths == max_paths)   {
          //if the maximum number of paths is reached, stop exploring
          return;
     } else {
          from->visited = true;
          path.push_back(from);
          if (from->name == to->name)      {
               //if the destination location is met, print the path
               num_paths += 1;
               report_path();
          } else {
               //if not, explore the current Vertex's neighbors
               for (size_t i = 0; i < from->neighbors.size(); i++)       {
                    Vertex *next = from->neighbors[i];
                    if (!next->visited)   {
                         //call the function on each neighbor
                         find_paths(next, to, max_paths);
                    }
               }
          }
          //remove the last Vertex in the path to explore alternate options
          path.pop_back();
          from->visited = false;
     }

}


/*
* Purpose: prints a path from the path vector in the required format
*/
void Graph::report_path()       {

     cout << "PATH " << num_paths << " ::";
     //print all the required information for every city stop
     for (size_t i = 1; i < path.size(); i++)     {
          cout << " ";
          cout << find_distance(path[i-1], path[i]);
          cout << " " << path[i]->name << " ";
          path[i]->location.print();
     }
     cout << endl;

}


/*
* Arguments: pointers to the origin and destination Vertex objects
* Purpose: finds the distance between the origin and destination locations.
* Returns: the distance between the 2 locations, but if either location isn't
     if either location isn't on the map, it returns -1.00
*/
int Graph::find_distance(Vertex *from, Vertex *to)         {

     //if either location isn't found, return -1.00
     if (!from or !to)     {
          return 0;
     } else {
          //return distance between the locations
          return from->location.distance_to(to->location);
     }

}


/*
* Arguments: pointers to the origin and destination Vertex objects
* Purpose: finds the distance between the origin and destination locations.
* Returns: the distance between the 2 locations, but if either location isn't
     if either location isn't on the map, it returns -1.00
*/
double Graph::find_distance(string origin, string dest)         {

     //find Vertex objects of the origin and destination
     Vertex *v1 = find_vertex(origin);
     Vertex *v2 = find_vertex(dest);

     //if either location isn't found, return -1.00
     if (!v1 or !v2)     {
          return -1.00;
     } else {
          //return distance between the locations
          return v1->location.distance_to(v2->location);
     }

}


/*
* Argument: name of the Vertex object to find
* Purpose: finds and returns the Vertex object with the given name
* Returns: a pointer to the Vertex object, but returns nullptr if it's
     not found
*/
Vertex *Graph::find_vertex(string name)       {

     //loop through all vertices
     for (size_t i = 0; i < map.size(); i++)    {
          if (map[i].name == name)      {
               //if the vertex matches the given name, return a pointer to it
               return &map[i];
          }
     }

     //if it's not found, return a nullptr
     return nullptr;

}


/*
* Purpose: prints the graph's vertices and edges
*/
void Graph::print_graph()          {

     //print vertices
     cout << "Vertices:" << endl;
     print_vertices();

     //print edges
     for (size_t i = 0; i < map.size(); i++)      {
          cout << "Vertex: " << map[i].name << endl;
          cout << "Neighbors: " << endl;
          for (size_t j = 0; j < map[i].neighbors.size(); j++)   {
               cout << map[i].neighbors[j]->name << endl;
          }
     }

}


























//
