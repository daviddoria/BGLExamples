#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

//typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph; //can't use this, in_edges are not defined in this concept - it only stores out_edges for space efficiency
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

int main(int,char*[])
{
  // Create a graph object
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v2 = add_vertex(g);

  add_edge(v0,v1,g);
  add_edge(v1,v2,g);

  // Get a list of incoming edges to vertex 1
  typedef boost::graph_traits < Graph >::in_edge_iterator in_edge_iterator;

  std::pair<in_edge_iterator, in_edge_iterator> inEdges = in_edges(1, g);

  std::cout << "In edges: " << std::endl;
  for(in_edge_iterator iter = inEdges.first; iter != inEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  
  // Get a list of outgoing edges from vertex 1
  typedef boost::graph_traits < Graph >::out_edge_iterator out_edge_iterator;
  std::pair<out_edge_iterator, out_edge_iterator> outEdges = out_edges(1, g);

  std::cout << std::endl << "Out edges: " << std::endl;
  for(out_edge_iterator iter = outEdges.first; iter != outEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  std::cout << std::endl;

  return 0;
}
