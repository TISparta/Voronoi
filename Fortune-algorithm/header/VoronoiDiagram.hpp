#pragma once

#include <queue>

#include "Cell.hpp"


template <typename T>
struct VoronoiDiagram {
  std::vector <Cell <T>> cells;

  int min_x;
  int max_x;
  int min_y;
  int max_y;

};
