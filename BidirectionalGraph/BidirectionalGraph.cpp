#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

int main(int,char*[])
{
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

  // Create a graph object
  Graph g(3);

  add_edge(0,1,g);
  add_edge(1,2,g);

  typedef boost::graph_traits < Graph >::in_edge_iterator in_edge_iterator;

  // Get a list of incoming edges to vertex 1
  std::cout << "In edges: " << std::endl;

  for(std::pair<in_edge_iterator, in_edge_iterator> inEdges = in_edges(1, g);
      inEdges.first != inEdges.second;
      ++inEdges.first)
    {
    //std::cout << index[*inEdges.first] << " ";
    std::cout << *inEdges.first << " ";
    }

  std::cout << std::endl;

  std::cout << std::endl << "Out edges: " << std::endl;

  // Get a list of outgoing edges from vertex 1
  typedef boost::graph_traits < Graph >::out_edge_iterator out_edge_iterator;

  for(std::pair<out_edge_iterator, out_edge_iterator> outEdges = out_edges(1, g);
      outEdges.first != outEdges.second;
      ++outEdges.first)
    {
    std::cout << *outEdges.first << " ";
    }

  std::cout << std::endl;

  return 0;
}
