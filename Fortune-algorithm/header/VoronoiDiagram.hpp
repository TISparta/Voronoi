#pragma once

#include <queue>

#include "Cell.hpp"
#include "HalfEdge.hpp"

template <typename T>
struct VoronoiDiagram {
  std::vector <Cell <T>> cells;

  int min_x;
  int max_x;
  int min_y;
  int max_y;
  std::vector <HalfEdge <T>*> edges;

};
