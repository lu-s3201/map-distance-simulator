/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   testRoadTrip.cpp
 *   By: Luella Sugiman (lsugim01)
 *   On: 8 Apr 2020
 *
 *   Description: test file for the Road Trip program
 *
 */

 #include "RoadTrip.h"

 int main(int argc, char *argv[])        {

      RoadTrip rt(argv[1], argv[2]);

      ifstream infile(argv[3]);

      rt.run(infile);

      return 0;

 }
