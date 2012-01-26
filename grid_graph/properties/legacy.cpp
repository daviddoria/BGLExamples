#include <iostream>
#include <boost/array.hpp>
#include <boost/graph/grid_graph.hpp>

namespace boost {
  enum vertex_data_t { vertex_data };

  BOOST_INSTALL_PROPERTY(vertex, data);
};

int main(int argc, char* argv[]) 
{
  typedef boost::grid_graph<2> GraphType;

  const unsigned int dimension = 5;
  boost::array<std::size_t, 2> lengths = { { dimension, dimension } };
  GraphType graph(lengths);

  boost::graph_traits<GraphType>::vertex_descriptor v = { { 0, 1 } };

  std::vector<float> vertexData(dimension * dimension, 0);
  
  //typedef boost::property_map<GraphType, boost::vertex_data_t>::type PropertyMapType;
  //PropertyMapType propertyMap = get(boost::vertex_data, graph);

  boost::grid_graph_index_map<GraphType, boost::graph_traits<GraphType>::vertex_descriptor, float> myMap(graph);
  
  float retrieved = get(myMap, v);
}
