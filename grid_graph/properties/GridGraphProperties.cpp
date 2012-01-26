#include <iostream>
#include <boost/array.hpp>
#include <boost/graph/grid_graph.hpp>

int main(int argc, char* argv[]) 
{
  typedef boost::grid_graph<2> GraphType;

  const unsigned int dimension = 5;
  boost::array<std::size_t, 2> lengths = { { dimension, dimension } };
  GraphType graph(lengths);

  boost::graph_traits<GraphType>::vertex_descriptor v = { { 0, 1 } };

  std::vector<float> vertexData(dimension * dimension, 3);

  typedef boost::property_map<GraphType, boost::vertex_index_t>::const_type indexMapType;
  indexMapType indexMap(get(boost::vertex_index, graph));

  // Iterator property
  {
  boost::iterator_property_map<std::vector<float>::iterator, indexMapType> myMap(vertexData.begin(), indexMap);
  float retrieved = get(myMap, v);
  std::cout << "Retrieved: " << retrieved << std::endl;
  }
  
  // Vector property
  {
  boost::vector_property_map<float, indexMapType> myMap(100, indexMap);
  float retrieved = get(myMap, v);
  std::cout << "Retrieved: " << retrieved << std::endl;
  
  put(myMap, v, 2.0f);
  }
  
  
  return 0;
}
