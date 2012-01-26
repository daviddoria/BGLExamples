#include <iostream>

#include <boost/graph/grid_graph.hpp>
#include <boost/graph/detail/d_ary_heap.hpp>
#include <boost/property_map/property_map.hpp>

// See also: http://www.boost.org/doc/libs/1_44_0/boost/graph/detail/d_ary_heap.hpp and
// https://github.com/mikael-s-persson/ReaK/blob/master/src/ReaK/ctrl/graph_alg/adstar_search.hpp

template <typename T>
struct LessThanFunctor
{
  bool operator()(const T& a, const T& b)
  {
    return a < b;
  }
};

// Better than std::priority_queue because you can modifiy the priority of elements already in the queue.
int main(int argc, char*argv[])
{
  boost::grid_graph<2> graph;
  typedef boost::graph_traits<VertexListGraph>::vertex_descriptor Vertex;

  typedef boost::vector_property_map<std::size_t> IndexInHeapMap;
  IndexInHeapMap index_in_heap;
  
  typedef boost::vector_property_map<float, GridIndexMapType> PriorityMapType;
  PriorityMapType priorityMap(gridIndexMap);

  //typedef boost::d_ary_heap_indirect<Vertex, 4, IndexInHeapMap, KeyMap, KeyCompareType> MutableQueue;
  typedef boost::d_ary_heap_indirect<Vertex, 4, IndexInHeapMap, PriorityMapType, LessThanFunctor> MutableQueue;

  LessThanFunctor<float> lessThanFunctor;
  MutableQueue mutableQueue(priorityMap, index_in_heap, lessThanFunctor);

  return 0;
}