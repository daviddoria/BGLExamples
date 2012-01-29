#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>

int main(int,char*[])
{
  // If the graph has a vecS vertex container selector, the vertex_descriptor is equal to the vertexId (an int)
  {
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = boost::add_vertex(g);
  std::cout << v0 << std::endl;

  boost::graph_traits<Graph>::vertex_descriptor v1 = boost::add_vertex(g);
  std::cout << v1 << std::endl;
  }

  // If the graph has a setS or listS vertex container selector, the vertex_descriptor is a void*.
  // It does not make sense to convert this pointer to an id, just as it does not make sense to convert
  // an iterator of std::set or std::list to an id.
  {
  typedef boost::adjacency_list<boost::vecS, boost::setS, boost::undirectedS> Graph;
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = boost::add_vertex(g);
  std::cout << v0 << std::endl; // This is the void* pointer which is the vertex_descriptor

  boost::graph_traits<Graph>::vertex_descriptor v1 = boost::add_vertex(g);
  std::cout << v1 << std::endl; // This is the void* pointer which is the vertex_descriptor

  boost::graph_traits<Graph>::vertex_descriptor test = boost::add_vertex(g);
  }
  
  return 0;
}
