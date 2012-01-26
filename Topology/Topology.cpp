#include <iostream>

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/topology.hpp"

int main(int argc, char *argv[])
{

  typedef boost::adjacency_list<boost::vecS,
                                boost::vecS,
                                boost::undirectedS
                                > Graph;

  Graph g;

  boost::square_topology<boost::minstd_rand> squareTopology;

  // no default constructor - rectangle_topology(double left, double top, double right, double bottom)
  boost::rectangle_topology<boost::minstd_rand> rectangleTopology(0,0,100,100);

  return 0;
}
