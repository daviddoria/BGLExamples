#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_iterator.hpp>


/*
adjacency_list<OutEdgeList, VertexList, Directed,
               VertexProperties, EdgeProperties,
               GraphProperties, EdgeList>
*/

int main(int,char*[])
{
  typedef boost::property<boost::vertex_property_tag, double> VertexProperty;

  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, VertexProperty> Graph;

  // Create a graph object
  Graph g(3);

  // Create two edges
  add_edge(0,1,g);
  add_edge(1,2,g);

  typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
  IndexMap index = get(boost::vertex_index, g);

  typedef boost::graph_traits< Graph >::adjacency_iterator adjacency_iterator;

  std::cout << "Adjacent neighbors of vertex 1 are:" << std::endl;

  std::pair<adjacency_iterator, adjacency_iterator> neighbors =
    boost::adjacent_vertices(vertex(1,g), g);

  for(; neighbors.first != neighbors.second; ++neighbors.first)
    {
    std::cout << index[*neighbors.first] << " ";
    }

  std::cout << std::endl;

  return EXIT_SUCCESS;
}
