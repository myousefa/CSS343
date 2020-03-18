/**
 * A Graph is made up of Vertex objects that hold data values
 * A vertex is connected to other vertices via Edges
 * A vertex can be visited/unvisited
 * Can connect to another vertex via directed edge with weight
 * The edge can be disconnected
 * A vertex cannot have an edge back to itself
 * getNextNeighbor returns the next neighbor each time it is called
 * when there are no more neighbors, the vertex label is returned
 */

#include "vertex.h"
#include "edge.h"
#include <algorithm>

using namespace std;

/**
 * This is a toString function that displays information
 * from Node in the form of a string
 * @param: ostream Os and const Vertex V
 * @return: Os 
 **/  
ostream &operator<<(ostream &Os, const Vertex &V) {
  Os << V.Label;
  return Os;
}

/**
 * --------------------------------------------------------------?
 * @param: ostream Os and const Vertex V
 * @return: Os 
 **/ 
Vertex::Vertex(const string &Label) {
  this->Label = Label;
  Visited = false; 
}

/**
 * Destructor, deletes Nodes
 * @param: No parameters
 * @return: No return 
 **/ 
Vertex::~Vertex() { Neighbors.clear(); }
