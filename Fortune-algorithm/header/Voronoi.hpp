#pragma once

#include <queue>

#include "Site.hpp"


template <typename T>
struct Voronoi {
  std::vector <Site <T>> sites;

  int min_x;
  int max_x;
  int min_y;
  int max_y;

};
