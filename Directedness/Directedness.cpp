#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

/* In this example, we demonstrate the differences between the three types of directedness available in an adjacency_list.
 * Each of the three functions is centered around a 3 vertex graph (vertices 0, 1, and 2), and particularly focused on vertex 1.
 * We attempt to do the same thing on all three graph types (except when something is not possible on a partuclar graph type, the code is
 * commented out).
 */

// Only out edges are stored at each vertex.
static void Directed();

// Every edge is added to every vertex. That is, an edge (A,B) is available as an out edge from A and an in edge from B.
// Adding (A, B) and (B, A) creates two separate edges.
static void Undirected();

// Adding (A, B) and (B, A) only creates one edge.
static void Bidirectional();

int main(int,char*[])
{
  Directed();
  Undirected();
  Bidirectional();

  return 0;
}

void Directed()
{
  std::cout << std::endl << "Directed()" << std::endl;
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;

  // Create a graph object.
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v2 = add_vertex(g);

  // Directed graphs can only store out_edges. That is, a call to add_edge(A, B) will only produce an edge that is accessible from A, not from B.
  // In edges
  add_edge(v0,v1,g);
  add_edge(v2,v1,g);
  
  // Out edges
  add_edge(v1,v2,g);
  add_edge(v1,v0,g);

  // Get a list of incoming edges to vertex 1 - Can't do this with a directed graph! Only out_edges are stored on the vertices.
//  typedef boost::graph_traits < Graph >::in_edge_iterator in_edge_iterator;

//   std::pair<in_edge_iterator, in_edge_iterator> inEdges = in_edges(1, g); // Can't do this, no access to in_edges in a directed graph
// 
//   std::cout << "In edges: " << std::endl;
//   for(in_edge_iterator iter = inEdges.first; iter != inEdges.second; ++iter)
//     {
//     std::cout << *iter << " ";
//     }
// 

  // Get a list of outgoing edges from vertex 1. Here we will only see two edges, (1,0) and (1,2).
  typedef boost::graph_traits < Graph >::out_edge_iterator out_edge_iterator;
  std::pair<out_edge_iterator, out_edge_iterator> outEdges = out_edges(1, g);

  std::cout << std::endl << "Out edges: " << std::endl;
  for(out_edge_iterator iter = outEdges.first; iter != outEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  std::cout << std::endl;

}

void Undirected()
{
  std::cout << std::endl << "Undirected()" << std::endl;
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;

  // Create a graph object
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v2 = add_vertex(g);

  // Add in edges
  add_edge(v0,v1,g);
  add_edge(v2,v1,g);

  // Add out edges
  add_edge(v1,v2,g);
  add_edge(v1,v0,g);

  // Get a list of incoming edges to vertex 1. Since all edges are stored at each vertex in an undirected graph,
  // we can see 4 edges here.
  typedef boost::graph_traits < Graph >::in_edge_iterator in_edge_iterator;

  std::pair<in_edge_iterator, in_edge_iterator> inEdges = in_edges(1, g);

  std::cout << "In edges: " << std::endl;
  for(in_edge_iterator iter = inEdges.first; iter != inEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  // Get a list of outgoing edges from vertex 1.  Since all edges are stored at each vertex in an undirected graph,
  // we can see 4 edges here as well.
  typedef boost::graph_traits < Graph >::out_edge_iterator out_edge_iterator;
  std::pair<out_edge_iterator, out_edge_iterator> outEdges = out_edges(1, g);

  std::cout << std::endl << "Out edges: " << std::endl;
  for(out_edge_iterator iter = outEdges.first; iter != outEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  std::cout << std::endl;

}

void Bidirectional()
{
  std::cout << std::endl << "Bidirectional()" << std::endl;
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

  // Create a graph object
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v1 = add_vertex(g);
  boost::graph_traits<Graph>::vertex_descriptor v2 = add_vertex(g);

  // Add in edges
  add_edge(v0,v1,g);
  add_edge(v2,v1,g);
  
  // Add out edges
  add_edge(v1,v2,g);
  add_edge(v1,v0,g);

  // Get a list of incoming edges to vertex 1. We can see the in edges we'd expect ( (0,1) and (2,1) ).
  typedef boost::graph_traits < Graph >::in_edge_iterator in_edge_iterator;

  std::pair<in_edge_iterator, in_edge_iterator> inEdges = in_edges(1, g);

  std::cout << "In edges: " << std::endl;
  for(in_edge_iterator iter = inEdges.first; iter != inEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  // Get a list of outgoing edges from vertex 1. We can see the out edges we'd expect ( (1, 2) and (1, 0) ).
  typedef boost::graph_traits < Graph >::out_edge_iterator out_edge_iterator;
  std::pair<out_edge_iterator, out_edge_iterator> outEdges = out_edges(1, g);

  std::cout << std::endl << "Out edges: " << std::endl;
  for(out_edge_iterator iter = outEdges.first; iter != outEdges.second; ++iter)
    {
    std::cout << *iter << " ";
    }

  std::cout << std::endl;

}
