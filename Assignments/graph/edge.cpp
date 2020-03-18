/**
 * Edge is the simplest structure of the graph
 * All edges are directed
 * Each edge belongs to a vertex
 */

#include "edge.h"

/**
 * Edge constructor
 * @param: Vertex From, Vertex to, and Weight of Vertex
 * @return: No return
 **/ 
Edge::Edge(Vertex *From, Vertex *To, int Weight) {
  this->From = From;
  this->To = To;
  this->Weight = Weight;
}
