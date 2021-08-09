/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   RoadTrip.cpp
 *   By: Luella (lsugim01)
 *   On: 4 Apr 2020
 *
 *   Description: implementation of the main simulator class for the Road
     Trip program - runs the reading of files, reception of queries,
     processing of data and printing of results
 *
 */

#include "RoadTrip.h"
#include "Graph.h"


/*
* Arguments: filenames for the vertex and edge data
* Purpose: instantiates a RoadTrip object
*/
RoadTrip::RoadTrip(string vdat, string adat)     {

     //read data and store data into the Graph
     read_file(vdat, adat);

}


/*
* Arguments: filenames for the vertex and edge data
* Purpose: reads files and stores data into the Graph
*/
void RoadTrip::read_file(string vdat, string adat)     {

     read_vdat(vdat);
     read_adat(adat);

}


/*
* Arguments: filename for the vertex data
* Purpose: reads file and store Vertex data into the Graph
*/
void RoadTrip::read_vdat(string vdat)        {

     //open file stream
     ifstream infile(vdat.c_str());
     if (infile.fail())  {
          cerr << "Unable to open " << vdat;
          exit(1);
     }

     string name;
     double lat_deg, lat_min, long_deg, long_min, latitude, longitude;

     //read the whole file
     while (infile >> name)   {
          //store data from the file
          infile >> lat_deg;
          infile >> lat_min;
          infile >> long_deg;
          infile >> long_min;

          //convert coordinates into degrees
          latitude = convert_to_deg(lat_deg, lat_min);
          longitude = convert_to_deg(long_deg, long_min);

          //add Vertex object with the given data into the graph
          g.add_vertex(name, latitude, longitude);
     }

}


/*
* Arguments: filename for the edge data
* Purpose: read files and store edge data into the Graph
*/
void RoadTrip::read_adat(string adat)        {

     //open the filestream
     ifstream infile(adat.c_str());
     if (infile.fail())  {
          cerr << "Unable to open " << adat;
          exit(1);
     }

     string origin, dest;

     //read the whole file
     while (infile >> origin)   {
          //store data from file
          infile >> dest;

          //add edge in the Graph
          g.add_edge(origin, dest);
     }

}


/*
* Argument: input stream to read queries from
* Purpose: runs the Road Trip program
*/
void RoadTrip::run(istream &input)      {

     string line_info;

     //process commands while input is given
     while (getline(input, line_info))   {
          string query, origin, dest;
          istringstream line_stream;
          int max_paths;

          line_stream.str(line_info);
          line_stream >> query;
          if (query == QUIT)  {
               return;
          } else if (query == LIST)     {
               process_list();
          } else if (query == DIST)     {
               line_stream >> origin >> dest;
               process_dist(origin, dest);
          } else if (query == PATH)     {
               line_stream >> origin >> dest >> max_paths;
               process_path(origin, dest, max_paths);
          }

          //clear line stream for the next query
          line_stream.clear();
     }

}


/*
* Purpose: processes the "list" query - lists out all locations (veritces) in
     the Graph
*/
void RoadTrip::process_list()      {

     g.print_vertices();

     cout << "-EOT-" << endl;

}


/*
* Arguments: names of origin and destination locations
* Purpose: processes the "dist" query - finds the distance between the
     2 locations
*/
void RoadTrip::process_dist(string origin, string dest)      {

     //find distance
     double dist = g.find_distance(origin, dest);
     //print distance with 2 decimal places
     cout << fixed << setprecision(2) << dist << endl;

     cout << "-EOT-" << endl;

}


/*
* Arguments: names of origin and destination locations & maximum number of
     paths to print
* Purpose: processes the "path" query - prints path(s) from the origin to the
     destination, printing either the total paths or the given maximum number
     of paths
*/
void RoadTrip::process_path(string origin, string dest, int max_paths)     {

     g.print_paths(origin, dest, max_paths);

}


/*
* Arguments: coordinate's degrees and minutes values
* Purpose: converts degrees and minutes into coordicate degrees
* Returns: calculated degrees value
*/
double RoadTrip::convert_to_deg(double deg, double min)     {

     double degrees;

     //calculate degrees value
     if (deg >= 0)   {
          degrees = deg + min/60;
     } else {
          degrees = deg - min/60;
     }

     return degrees;

}





























//
