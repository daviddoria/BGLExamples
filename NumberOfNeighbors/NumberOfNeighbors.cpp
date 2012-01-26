#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

int main(int,char*[])
{
  // Create a graph object
  Graph g(3);

  add_edge(0,1,g);
  add_edge(1,2,g);

  int numberOfInEdges = in_degree(1,g);
  std::cout << "numberOfInEdges: " << numberOfInEdges << std::endl;

  int numberOfOutEdges = out_degree(1,g);
  std::cout << "numberOfOutEdges: " << numberOfOutEdges << std::endl;

  int numberOfEdges = degree(1,g);
  std::cout << "numberOfEdges: " << numberOfEdges << std::endl;

  return 0;
}
