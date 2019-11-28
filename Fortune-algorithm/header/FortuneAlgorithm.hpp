#pragma once

#include <queue>

#include "Voronoi.hpp"
#include "Event.hpp"

class FortuneAlgorithm {
private:
  Voronoi diagram;
  std::priority_queue <Event> pq;
  void compute_bounds (const std::vector <Point>& sites);
  void compute_diagram (const std::vector <Point>& sites);
  void init_site_events (const std::vector <Point>& sites);

public:
  FortuneAlgorithm (const std::vector <Point>& sites);
  inline Voronoi getDiagram () const { return diagram; }

};
