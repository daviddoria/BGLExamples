#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>

struct FeatureVectorPixelDescriptor
{
  //std::vector<float> FeatureVector;
  int A;
};

struct ImagePatchPixelDescriptor
{
  int B;
  //class Image {} image;
  //class Index {} index;
};

typedef boost::adjacency_list<boost::vecS, //OutEdgeList
                              boost::vecS,// VertexList
                              boost::undirectedS, //Directed,
                              FeatureVectorPixelDescriptor //VertexProperties
                              > Graph;

int main(int,char*[])
{
  // Declare a graph object
  Graph g;

  boost::graph_traits<Graph>::vertex_descriptor v0 = boost::add_vertex(g);
  g[v0].A = 4;

  boost::graph_traits<Graph>::vertex_descriptor v1 = boost::add_vertex(g);
  g[v1].A = 5;

  // Add edges.
  add_edge(v0, v1, g);

  // Get the vertices
  typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
  IndexMap index = get(boost::vertex_index, g);

  typedef boost::graph_traits<Graph>::vertex_iterator vertex_iter;
  std::pair<vertex_iter, vertex_iter> firstLastPair;
  for (firstLastPair = vertices(g); firstLastPair.first != firstLastPair.second; ++firstLastPair.first)
  {
    boost::graph_traits<Graph>::vertex_descriptor currentVertex = *firstLastPair.first;
    std::cout << "Vertex A value: " << g[currentVertex].A << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
