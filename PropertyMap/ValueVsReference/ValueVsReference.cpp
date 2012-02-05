#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>

namespace boost {
  enum vertex_data_t { vertex_data };

  BOOST_INSTALL_PROPERTY(vertex, data);
};

typedef boost::adjacency_list<boost::vecS, //OutEdgeList
                              boost::vecS,// VertexList
                              boost::undirectedS, //Directed,
                              boost::property< boost::vertex_data_t, float > // VertexProperties
                              > Graph;

int main(int,char*[])
{
  Graph g;

  typedef boost::property_map<Graph, boost::vertex_data_t>::type PropertyMapType;
  PropertyMapType propertyMap = get(boost::vertex_data, g);

  typedef boost::graph_traits<Graph>::vertex_descriptor VertexType;
  VertexType v = boost::add_vertex(g);
  float p = 0.0f;

  put(propertyMap, v, p);

  {
  // Value
  std::cout << "Value: " << std::endl;
  float retrieved = get(propertyMap, v);
  std::cout << retrieved << std::endl;
  retrieved = 4;
  std::cout << retrieved << std::endl;
  float retrieved2 = get(propertyMap, v);
  std::cout << retrieved2 << std::endl;
  }

  {
  // Reference
  std::cout << "Reference: " << std::endl;
  float& retrieved = get(propertyMap, v);
  std::cout << retrieved << std::endl;
  retrieved = 4;
  std::cout << retrieved << std::endl;
  float retrieved2 = get(propertyMap, v);
  std::cout << retrieved2 << std::endl;
  }

  return 0;
}