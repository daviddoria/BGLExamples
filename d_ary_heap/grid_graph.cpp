#include <iostream>
#include <iomanip>
 
#include <boost/graph/grid_graph.hpp>
#include <boost/graph/detail/d_ary_heap.hpp>
#include <boost/property_map/property_map.hpp>
 
#include <cstdlib>
 
template <typename T>
struct LessThanFunctor
{
  bool operator()(const T& a, const T& b)
  {
    return a < b;
  }
};
 
int main(int argc, char*argv[])
{
  srand((unsigned int)time(NULL));
 
  boost::array<std::size_t, 2> lengths = { { 5,5 } };
  typedef boost::grid_graph<2> GraphType;
  GraphType graph(lengths);
  typedef boost::graph_traits<GraphType>::vertex_descriptor Vertex;
  typedef boost::property_map<GraphType, boost::vertex_index_t>::const_type GridIndexMapType;
  GridIndexMapType gridIndexMap(get(boost::vertex_index, graph));
 
  typedef boost::vector_property_map<std::size_t, GridIndexMapType> IndexInHeapMap;
  IndexInHeapMap index_in_heap(gridIndexMap);
 
  typedef boost::graph_traits<GraphType>::vertex_iterator VertexIteratorType;
//   VertexIteratorType ui, ui_end;
//   for( tie(ui,ui_end) = vertices(graph); ui != ui_end; ++ui)
//     put(index_in_heap, *ui, static_cast<std::size_t>(-1));
 
  typedef boost::vector_property_map<float, GridIndexMapType> PriorityMapType;
  PriorityMapType priorityMap(gridIndexMap);
  VertexIteratorType vertexIterator, vertexIteratorEnd;
  for( tie(vertexIterator, vertexIteratorEnd) = vertices(graph); vertexIterator != vertexIteratorEnd; ++vertexIterator)
    put(priorityMap, *vertexIterator, rand() % 1000);
 
  std::cout << "Given the following random grid-graph: " << std::endl;
  Vertex v = vertex(0,graph);
  for(std::size_t i = 0; i < lengths[0]; ++i) {
    Vertex u = v;
    for(std::size_t j = 0; j < lengths[1]; ++j) {
      std::cout << std::setw(5) << get(priorityMap, u);
      u = graph.next(u,1);
    };
    v = graph.next(v,0);
    std::cout << std::endl;
  };
 
  typedef boost::d_ary_heap_indirect<Vertex, 4, IndexInHeapMap, PriorityMapType, LessThanFunctor<float> > MutableQueue;
 
  LessThanFunctor<float> lessThanFunctor;
  MutableQueue mutableQueue(priorityMap, index_in_heap, lessThanFunctor);
 
  for( tie(vertexIterator, vertexIteratorEnd) = vertices(graph); vertexIterator != vertexIteratorEnd; ++vertexIterator)
    mutableQueue.push(*vertexIterator); 
 
  std::cout << "We get the following priority queue: " << std::endl;
  while( ! mutableQueue.empty() ) {
    Vertex u = mutableQueue.top(); mutableQueue.pop();
    std::cout << std::setw(5) << get(priorityMap, u);
  };
  std::cout << std::endl;
  return 0;
}
