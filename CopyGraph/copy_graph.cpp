#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/copy.hpp>

typedef boost::adjacency_list <
  boost::vecS,
  boost::vecS,
  boost::undirectedS> Graph;


int main(int, char*[])
{
  Graph g(19);

  add_edge(0,1,g);
  add_edge(1,2,g);

  Graph g_copy;
  
  copy_graph(g, g_copy);
  return EXIT_SUCCESS;
}
