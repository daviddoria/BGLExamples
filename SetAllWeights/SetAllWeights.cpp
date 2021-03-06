#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/directed_graph.hpp>

typedef boost::property<boost::edge_weight_t, float> EdgeWeightProperty;

typedef boost::directed_graph<boost::no_property, EdgeWeightProperty> Graph;

int main(int,char*[])
{
  // Create a graph object
  Graph g;
  
  // Add vertices to the graph
  boost::graph_traits<Graph>::vertex_descriptor v0 = g.add_vertex();
  boost::graph_traits<Graph>::vertex_descriptor v1 = g.add_vertex();
  boost::graph_traits<Graph>::vertex_descriptor v2 = g.add_vertex();

  // Create weighted edges
  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> e01 = add_edge(v0,v1,g);
  add_edge(v1,v2,g);
  
  put( boost::edge_weight, g, e01.first, 3.1 );
  

  //"Ask a question" of a graph. The IndexMap is the solution set.
  typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
  IndexMap index = get(boost::vertex_index, g);
  std::cout << "Edges from index map:";
  typedef boost::graph_traits<Graph>::edge_iterator edge_iter;
  std::pair<edge_iter, edge_iter> edgePair;
  for(edgePair = edges(g); edgePair.first != edgePair.second; ++edgePair.first)
  {
    put( boost::edge_weight, g, *edgePair.first, 3.1 );
  }
  
  

  // Retrieve the weight of an edge (method 1, works)
  {
  typedef boost::property_map<Graph, boost::edge_weight_t>::type EdgeWeightMap;
  EdgeWeightMap edgeWeightMap = get(boost::edge_weight, g);

  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> edgePair = edge(v0, v1, g);
  boost::graph_traits<Graph>::edge_descriptor edge = edgePair.first;

  std::cout << "Edge (" << v0 << ", " << v1 << ") has weight " << edgeWeightMap[edge] << std::endl;
  }

  // method 2
  {
  std::pair<boost::graph_traits<Graph>::edge_descriptor, bool> edgePair = edge(v0, v1, g);
  boost::graph_traits<Graph>::edge_descriptor edge = edgePair.first;
  std::cout << std::cout << "Edge (" << v0 << ", " << v1 << ") has weight " << get( boost::edge_weight, g, edge ) << std::endl;
  }

  return 0;
}
