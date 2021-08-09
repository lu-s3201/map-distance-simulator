/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   RoadTrip.h
 *   By: Luella (lsugim01)
 *   On: 4 Apr 2020
 *
 *   Description: header file for the Road Trip program - provides the
 *   interface of the Road Trip program
 *
 */

#ifndef ROADTRIP_H_
#define ROADTRIP_H_

#include <fstream>
#include <sstream>

#include "Graph.h"

class RoadTrip      {
public:
     RoadTrip(string vdat, string adat);
     void run(istream &input);

private:
     Graph g;

     const string QUIT = "quit";
     const string LIST = "list";
     const string DIST = "dist";
     const string PATH = "path";

     void read_file(string vdat, string adat);
     void read_vdat(string vdat);
     void read_adat(string adat);

     //query functions
     void process_quit();
     void process_list();
     void process_dist(string origin, string dest);
     void process_path(string origin, string dest, int max_path);

     //helper functions
     double convert_to_deg(double deg, double min);
};

#endif





































//
