#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include <boost/array.hpp>
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

int main()
{

  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
    boost::no_property, boost::property<boost::edge_weight_t, int> > Graph;
  typedef boost::property_map<Graph, boost::edge_weight_t>::type EdgeWeightMap;

  unsigned int numberOfVertices = 10;
  Graph g(numberOfVertices);
  for(unsigned int i = 0; i < numberOfVertices - 1; ++i)
    {
    add_edge(i, i+1, g);
    }

  std::cout << "Original graph:" << std::endl;
  boost::print_graph(g);

  vertex_id_filter<Graph> filter;
  typedef boost::filtered_graph<Graph, boost::keep_all, vertex_id_filter<Graph> > FilteredGraphType;
  FilteredGraphType filteredGraph(g, boost::keep_all(), filter); // (graph, EdgePredicate, VertexPredicate)

  std::cout << "Filtered graph:" << std::endl;
  boost::print_graph(filteredGraph);
  
  FilteredGraphType::vertex_iterator ui,ui_end; tie(ui,ui_end) = vertices(filteredGraph);

  return 0;
}
