#pragma once
#include "HalfEdge.hpp"
#include "Arguments.hpp"
#include "FortuneAlgorithm.hpp"
#include "HalfEdge.hpp"
#include <vector>
namespace Voronoi {
template<typename T>
class FortuneVisualization {
  FortuneAlgorithm <T> fortune;
public:
  FortuneVisualization(Arguments <T> arg)
  {
    fortune.getDiagram();
  }
  void render() {
    for (auto cell: fortune.cells) {
      Point <T> site = cell.site;
      HalfEdge* edge = cell.edges;
      do {
        Point <T> from = edge->from;
        Point <T> to = edge->to;
        // do something with (site, from, to)
        edge = edge->next;
      } while (edge != cell.edges);
    }
  }
    
};
  
}


