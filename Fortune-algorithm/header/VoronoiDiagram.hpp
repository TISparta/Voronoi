#pragma once

#include <queue>

#include "Site.hpp"


template <typename T>
struct VoronoiDiagram {
  std::vector <Site <T>> sites;

  int min_x;
  int max_x;
  int min_y;
  int max_y;

};
