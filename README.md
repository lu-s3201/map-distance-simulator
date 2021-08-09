# map-distance-simulator

PURPOSE

This assignment includes a Road Trip program. The program is able to
read into a .vdat (vertex data) & .adat (adjacency data) file, store given
information in a directed graph, and run the following queries: "list", "dist",
"quit" and "path".

ACKNOWLEDGEMENTS

In this assignment, I referred to cplusplus.com's documentation of the vector
library.

FILES

Graph.h:
     Interface of the Graph class. Defines the class's members and functions.

Graph.cpp:
     Implementation of the Graph class. Allows for the creation and
     manipulation of 'locations' (vertices) and 'connections' (edges).

RoadTrip.h:
     Interface of the RoadTrip class. Defines the class's members and
     functions.

RoadTrip.cpp:
     Implementation of the RoadTrip class. Allows for the processing of
     queries inputted into the program.

findpath.cpp:
     Driver file for the Road Trip program. Creates a RoadTrip object
     to start off the program.

testGraph.cpp:
     Test class for the Graph class. Creates and initializes a Graph
     object and tests its functions.

testRoadTrip.cpp:
     Test class for the Road Trip class. Runs the program using an input file
     specified in the command line.

test0.txt, test1.txt, test2.txt:
     Test file for the Road Trip class. Tests all completed queries of the
     program.

README:
     Reference documentation for the Road Trip program.

Makefile:
     Defines Terminal shortcuts for compiling the program.

COMPILE & RUN

To compile the Graph: "make testGraph.o"
To run: "./testGraph.o"

To compile the Road Trip test: "make testRoadTrip.o"
To run: "./testRoadTrip.o vertex_data edge_data input_data"

To compile the Road Trip program: "make findpath"
To run: "./findpath vertex_data edge_data"

DATA STRUCTURES & ALGORITHMS

To implement the directed graph structure, I used a struct as vertices and a
\linked-list-like implementation of edges. The Vertex struct contains the
name of the location, a Location object to store its coordinates and
calculate distances, and a vector of pointers to other Vertex structs. The
vector of pointers is how I implemented the directed edges of the graph - it
represents a path between one location to another. (The execution of this
aspect of the graph is yet to be completed in phase 1.)

To store the vertices, I also used a vector (through the C++ vector STL).
I decided to implement these aspects of the graph using vectors because it's
the most memory-efficient data structure I'm familiar with. Due to its
dynamic structure, it's able to expand in space only when necessary, meaning
it won't take up any more space in memory than needed. To insert a new
Vertex or a new neighbor pointer would be extremely efficient, being of
O(1) complexity. Accessing vertices or neighbors would be O(n) complexity
since I would have to search for matching names, which wouldn't be different
to any other data structure (linked list, array, etc.). In addition, there's
no query to delete anything in the graph so the complexity of remove is
unimportant.

To find paths, I used a recursive depth-first search (DFS) algorithm. It will
explore a path from the origin to the deepest node (dead-end) before
backtracking and exploring an alternate path. This allowed me to find multiple
paths from one location to another. The path is stored in a vector of Vertex
pointers, which is printed once a complete path is found, then cleared to store
the next path. Since the objective is to find many paths and not specifically
the shortest path, a BFS isn't the necessary algorithm to use.

TESTING

I conducted unit testing on the Graph class, in a class named testGraph.cpp.
This class tests all the functions implemented in Graph.cpp. I applied
the functions with a small data set (data0), a larger data set (ta) and an
even larger data set (cs15). With the help of a print function, each output is
compared before and after the function was called, to manually ensure the
functions worked correctly. The print_graph() function is now made private.

To test the CalcYouLater program as a whole, I created a test file named
test0.txt, test1.txt and test2.txt. The functions of each query was given as
input in this test file to cover all bases. To take input from a file, I
created another driver class called testRoadTrip.cpp to facilitate the
different input source. I applied the functions with a small data set (data0),
a larger data set (ta) and an even larger data set (c15). The testing files
included commands that had unknown city names (in the path query) and path
queries that had no possible paths to test how the program would inform the
user. Then, I 'diff'ed the outputs of my program and the reference
implementation in order to ensure each output was correct and that my program
was working as expected.
