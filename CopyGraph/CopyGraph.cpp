// http://www.boost.org/doc/libs/1_37_0/libs/graph/doc/read_graphviz.html
#include <iostream>
#include <string>
#include <fstream>
 
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
 
// We need a bool to store visibility of each edge
struct EdgeVisibility
{
  bool visible;
};
 
typedef boost::adjacency_list < boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, EdgeVisibility> Graph;
 
Graph CreateGraph();
void Test(const Graph& g);
 
int main(int argc, char*argv[])
{
  Graph g = CreateGraph();
  Test(g);
  return 0;
}
 
void Test(const Graph& g)
{
  // Copy the graph
  Graph copiedGraph = g;
 
  // Set the 10th edge of the copied graph to invisible
  unsigned int counter = 0;
  std::pair<Graph::edge_iterator, Graph::edge_iterator> copiedGraphOriginalIteratorRange = edges(copiedGraph);
  for(Graph::edge_iterator copiedGraphOriginalEdgeIterator = copiedGraphOriginalIteratorRange.first; copiedGraphOriginalEdgeIterator != copiedGraphOriginalIteratorRange.second; ++copiedGraphOriginalEdgeIterator)
    {
    if(counter == 10)
      {
      copiedGraph[*copiedGraphOriginalEdgeIterator].visible = false;
      }
    counter++;
    }
    
  // Display both graphs edge visibilities so that we are convinced the two graphs are actually separate objects.

  // Display the input graph's edge visibility
  std::cout << "Input graph edge visiblity: " << std::endl;
  std::pair<Graph::edge_iterator, Graph::edge_iterator> gEdgeIteratorRange = edges(g); // Note this is the new graph
  for(Graph::edge_iterator gEdgeIterator = gEdgeIteratorRange.first; gEdgeIterator != gEdgeIteratorRange.second; ++gEdgeIterator)
    {
    std::cout << g[*gEdgeIterator].visible << " ";
    }
  std::cout << std::endl;
 
  
  // Display the copied graph's edge visibility
  std::cout << "Copied graph edge visiblity: " << std::endl;
  std::pair<Graph::edge_iterator, Graph::edge_iterator> copiedGraphEdgeIteratorRange = edges(copiedGraph); // Note this is the original graph
  for(Graph::edge_iterator copiedGraphEdgeIterator = copiedGraphEdgeIteratorRange.first; copiedGraphEdgeIterator != copiedGraphEdgeIteratorRange.second; ++copiedGraphEdgeIterator)
    {
    std::cout << copiedGraph[*copiedGraphEdgeIterator].visible << " ";
    }
    std::cout << std::endl;
}
 
Graph CreateGraph()
{
  Graph g(19);
 
  add_edge(0,1,g);
  add_edge(1,2,g);
  add_edge(2,3,g);
  add_edge(3,4,g);
  add_edge(4,5,g);
  add_edge(5,6,g);
  add_edge(6,7,g);
  add_edge(7,8,g);
  add_edge(7,9,g);
  add_edge(9,10,g);
  add_edge(7,11,g);
  add_edge(11,12,g);
  add_edge(12,13,g);
  add_edge(13,14,g);
  add_edge(13,15,g);
  add_edge(15,16,g);
  add_edge(16,17,g);
  add_edge(17,18,g);
 
  // Set all edges to visible
  std::pair<Graph::edge_iterator, Graph::edge_iterator> edgeIteratorRange = edges(g);
  for(Graph::edge_iterator edgeIterator = edgeIteratorRange.first; edgeIterator != edgeIteratorRange.second; ++edgeIterator)
    {
    g[*edgeIterator].visible = true;
    }
    
  return g;
}
