#include <iostream>
#include <boost/array.hpp>
#include <boost/graph/grid_graph.hpp>

int main(int argc, char* argv[]) 
{
  typedef boost::grid_graph<2> Graph;

  boost::array<std::size_t, 2> lengths = { { 5,5 } };
  Graph graph(lengths);

  //boost::graph_traits<Graph>::vertex_iterator iterator = vertices(graph); // This is not the way to get the iterator

  typedef typename boost::graph_traits<Graph>::vertex_iterator VertexIter;
  VertexIter ui,ui_end; tie(ui,ui_end) = vertices(graph);
  
  return 0;
}
