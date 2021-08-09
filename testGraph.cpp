/*
 *
 *   COMP 15 PROJ 2 ROAD TRIP
 *
 *   testGraph.cpp
 *   By: Luella Sugiman (lsugim01)
 *   On: 4 Apr 2020
 *
 *   Description: test file for the Graph data structure
 *
 */

#include "Graph.h"

using namespace std;

void test_phase1(Graph *g);
void test_phase2(Graph *g);

int main()     {

     Graph g;

     g.add_vertex("Boston", 2168, 4922);
     g.add_vertex("Singapore", -190, 932);
     g.add_vertex("Beijing", -2090, -450);
     g.add_edge("Boston", "Singapore");
     g.add_edge("Singapore", "Boston");
     g.add_edge("Singapore", "Beijing");

     test_phase1(&g);
     test_phase2(&g);

     return 0;

}

void test_phase1(Graph *g)  {

     //test reading into vdat, storing vertices & list query
     g->print_vertices();
     cout << endl;

     //test dist query
     cout << g->find_distance("Boston", "Singapore") << endl;
     cout << endl;

}

void test_phase2(Graph *g)    {

     //test reading into adat & storing edges
     g->print_graph();
     cout << endl;

     //test path query
     g->print_paths("Boston", "Beijing", 2);

}
