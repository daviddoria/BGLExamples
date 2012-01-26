#include <iostream>

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/simple_point.hpp"

namespace boost {
  enum vertex_coordinate_t { vertex_coordinate };

  BOOST_INSTALL_PROPERTY(vertex, coordinate);
};

int main(int argc, char *argv[])
{

  typedef boost::simple_point<float> PointType;

  typedef boost::adjacency_list<boost::vecS,
                                boost::vecS,
                                boost::undirectedS,
                                boost::property< boost::vertex_coordinate_t, PointType >
                                > Graph;

  Graph g;

  typedef typename boost::property_map<Graph, boost::vertex_coordinate_t>::type CoordinatePropertyMap;
  CoordinatePropertyMap coordinatePropertyMap = get(boost::vertex_coordinate, g);

  return 0;
}
