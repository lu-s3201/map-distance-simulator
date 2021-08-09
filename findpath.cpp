/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   main.cpp
 *   By: Luella (lsugim01)
 *   On: 4 Apr 2020
 *
 *   Description: driver file for the Road Trip program - creates a
     RoadTrip object and starts the program
 *
 */

#include "RoadTrip.h"

int main(int argc, char *argv[])        {

     if (argc != 3) {
          cerr << "Usage: findpath vertex_data edge_data";
          exit(1);
     }

     RoadTrip rt(argv[1], argv[2]);
     rt.run(cin);

     return 0;

}




































//
