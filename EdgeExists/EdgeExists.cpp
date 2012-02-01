#include <iostream>
#include <boost/graph/adjacency_list.hpp>

int main(int,char*[])
{
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;

  // Create a graph object
  Graph g;
  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);

  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> retrievedEdge = edge(v0, v1, g);
  std::cout << retrievedEdge.first << " exists? " << retrievedEdge.second << std::endl;

  std::cout << std::endl;

  // Add an edge between v0 and v1.
  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> e0 = add_edge(v0, v1, g);

  // Check again if an edge between v0 and v1 exists. It should now.

  // A demonstration of the full return type of edge().
  retrievedEdge = edge(v0, v1, g);
  std::cout << retrievedEdge.first << " exists? " << retrievedEdge.second << std::endl;

  return EXIT_SUCCESS;
}
