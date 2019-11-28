#pragma once

#include <queue>

#include "Site.hpp"

struct Voronoi {
  std::vector <Site> sites;

  int min_x;
  int max_x;
  int min_y;
  int max_y;

};
