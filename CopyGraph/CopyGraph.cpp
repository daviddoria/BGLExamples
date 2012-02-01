#include <iostream>
#include <boost/graph/adjacency_list.hpp>

// We need a bool to store visibility of each edge
struct EdgeVisibility
{
  bool visible;
};

typedef boost::adjacency_list <
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::no_property,
  EdgeVisibility > Graph;

typedef boost::graph_traits<Graph>::edge_iterator EdgeIterator;

// -----------------------------------------------------------------------------
Graph CreateGraph()
{
  Graph g(19);

 // 0 - 1 - 2 - 3 - 4 - 5 - .... - 18

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

  std::pair< EdgeIterator, EdgeIterator > edgeIteratorRange = edges(g);

  // Set all edges to visible
  for( EdgeIterator edgeIterator = edgeIteratorRange.first;
       edgeIterator != edgeIteratorRange.second;
       ++edgeIterator )
    {
    g[*edgeIterator].visible = true;
    }

  return g;
}

// -----------------------------------------------------------------------------
void Test(const Graph& g)
{
  // Copy the graph by the means of the operator '='
  Graph copiedGraph = g;

  // Another way to copy a graph is to use the constructor by copy, i.e.
  // Graph copiedGraph( g )

  // Set the 10th edge of the copied graph to invisible
  unsigned int counter = 0;
  std::pair< EdgeIterator, EdgeIterator > copiedGraphOriginalIteratorRange = edges(copiedGraph);

  for(EdgeIterator copiedGraphOriginalEdgeIterator = copiedGraphOriginalIteratorRange.first;
      copiedGraphOriginalEdgeIterator != copiedGraphOriginalIteratorRange.second;
      ++copiedGraphOriginalEdgeIterator, ++counter )
    {
    if(counter == 10)
      {
      copiedGraph[ *copiedGraphOriginalEdgeIterator ].visible = false;
      }
    }

  // ---------------------------------------------------------------------------
  // Display both graphs edge visibilities so that we are convinced the
  // two graphs are actually separate objects.

  // Display the input graph's edge visibility
  std::cout << "Input graph edge visiblity: " << std::endl;
  std::pair< EdgeIterator, EdgeIterator > gEdgeIteratorRange = edges(g); // Note this is original graph

  for(EdgeIterator gEdgeIterator = gEdgeIteratorRange.first;
      gEdgeIterator != gEdgeIteratorRange.second;
      ++gEdgeIterator)
    {
    std::cout << g[*gEdgeIterator].visible << " ";
    }
  std::cout << std::endl;

  std::cout << std::endl;

  // Display the copied graph's edge visibility
  std::cout << "Copied and modified graph edge visiblity: " << std::endl;
  std::pair< EdgeIterator, EdgeIterator > copiedGraphEdgeIteratorRange = edges(copiedGraph); // Note this is the copied and modified graph

  for(EdgeIterator copiedGraphEdgeIterator = copiedGraphEdgeIteratorRange.first;
      copiedGraphEdgeIterator != copiedGraphEdgeIteratorRange.second;
      ++copiedGraphEdgeIterator)
    {
    std::cout << copiedGraph[*copiedGraphEdgeIterator].visible << " ";
    }
  std::cout << std::endl;
}

int main(int, char*[])
{
  Graph g = CreateGraph();
  Test(g);
  return EXIT_SUCCESS;
}
