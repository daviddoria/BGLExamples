#include <iostream>
#include <boost/array.hpp>
#include <boost/graph/grid_graph.hpp>

// More examples: http://www.boost.org/doc/libs/1_41_0/libs/graph/example/grid_graph_example.cpp
// See also: http://www.ais.uni-bonn.de/~schulz/2011/01/27/dijkstra-on-boost-grid-graph.html

int main(int argc, char* argv[]) 
{
  typedef boost::grid_graph<2> Graph;

  boost::array<std::size_t, 2> lengths = { { 5,5 } };
  Graph graph(lengths);

  {
  // Get the grid index (vertex_descriptor) associated with linear index
  boost::graph_traits<Graph>::vertices_size_type linearIndex = 0;
  boost::graph_traits<Graph>::vertex_descriptor v = vertex(linearIndex, graph);

  std::cout << v[0] << " " << v[1] << std::endl;
  }
  
  {
  // Get the linear index associated with vertex descriptor (grid index)
  boost::graph_traits<Graph>::vertex_descriptor v = { { 0, 1 } };
  
  int a, b;
  boost::graph_traits<Graph>::vertex_descriptor testv = { { a, b } };
  
  boost::graph_traits<Graph>::vertices_size_type ind = get(boost::vertex_index, graph, v);
  std::cout << ind << std::endl;
  
  // Equivalently, first get the property map, then get the linear index
  typedef boost::property_map<Graph, boost::vertex_index_t>::type PropertyMapType;
  PropertyMapType propertyMap = get(boost::vertex_index, graph);
  
  boost::graph_traits<Graph>::vertices_size_type ind2 = get(propertyMap, v);
  std::cout << ind2 << std::endl;
  }

}
