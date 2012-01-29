#include <iostream>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;

int main(int,char*[])
{
  // Create a graph object
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);

  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> e0 = add_edge(v0, v1, g);
    
  std::pair<boost::graph_traits<Graph>::edge_iterator, boost::graph_traits<Graph>::edge_iterator> edgeIteratorRange = edges(g);
  for(boost::graph_traits<Graph>::edge_iterator edgeIterator = edgeIteratorRange.first; edgeIterator != edgeIteratorRange.second; ++edgeIterator)
   {
     std::cout << *edgeIterator << std::endl;
   }
  return 0;
}
