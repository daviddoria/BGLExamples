#include <iostream>
#include <boost/array.hpp>
#include <boost/graph/grid_graph.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>

template <typename TGraph>
struct vertex_id_filter
{
  bool operator()(const typename boost::graph_traits<TGraph>::vertex_descriptor& v) const
  {
    return 3 < v; // keep all vertx_descriptors greater than 3
  }
};

int main(int argc, char* argv[]) 
{
  typedef boost::grid_graph<2> Graph;

  boost::array<std::size_t, 2> lengths = { { 5,5 } };
  Graph graph(lengths);

  {
  // Get the vertex associated with vertex_index
  boost::graph_traits<Graph>::vertices_size_type linearIndex = 0;
  boost::graph_traits<Graph>::vertex_descriptor v = vertex(linearIndex, graph);

  std::cout << v[0] << " " << v[1] << std::endl;
  }

  {
  // Get the index associated with vertex
  boost::graph_traits<Graph>::vertex_descriptor v = { { 0, 1 } };
  boost::graph_traits<Graph>::vertices_size_type ind = get(boost::vertex_index, graph, v);
  std::cout << ind << std::endl;
  }

  vertex_id_filter<Graph> filter;
  boost::filtered_graph<Graph, boost::keep_all, vertex_id_filter<Graph> > filteredGraph(graph, boost::keep_all(), filter); // (graph, EdgePredicate, VertexPredicate)

}
