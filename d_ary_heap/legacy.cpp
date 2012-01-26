#include <iostream>

#include <boost/graph/grid_graph.hpp>
#include <boost/graph/detail/d_ary_heap.hpp>
#include <boost/property_map/property_map.hpp>

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
  boost::array<std::size_t, 2> lengths = { { 5,5 } };
  typedef boost::grid_graph<2> GraphType;
  GraphType graph(lengths);
  typedef boost::graph_traits<GraphType>::vertex_descriptor Vertex;
  typedef boost::property_map<GraphType, boost::vertex_index_t>::const_type GridIndexMapType;
  GridIndexMapType gridIndexMap(get(boost::vertex_index, graph));

  typedef boost::vector_property_map<std::size_t, GridIndexMapType> IndexInHeapMap;
  IndexInHeapMap index_in_heap;

  put(index_in_heap, vertex(0, graph), static_cast<std::size_t>(-1));

  typedef boost::vector_property_map<float, GridIndexMapType> PriorityMapType;
  PriorityMapType priorityMap(gridIndexMap);

  //typedef boost::d_ary_heap_indirect<Vertex, 4, IndexInHeapMap, KeyMap, KeyCompareType> MutableQueue;
  typedef boost::d_ary_heap_indirect<Vertex, 4, IndexInHeapMap, PriorityMapType, LessThanFunctor<float> > MutableQueue;

  LessThanFunctor<float> lessThanFunctor;
  MutableQueue mutableQueue(priorityMap, index_in_heap, lessThanFunctor);
  
  Vertex v = vertex(0, graph);
  mutableQueue.push(v); // Compiler error - no match for operator[]
  return 0;
}
