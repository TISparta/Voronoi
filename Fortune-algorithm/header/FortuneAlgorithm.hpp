#pragma once

#include <queue>

#include "Voronoi.hpp"
#include "Event.hpp"

template <typename T>
class FortuneAlgorithm {
private:
  Voronoi <T> diagram;
  std::priority_queue <Event <T>> pq;
  void compute_bounds (const std::vector <Point <T>>& sites);
  void compute_diagram (const std::vector <Point <T>>& sites);
  void init_site_events (const std::vector <Point <T>>& sites);

public:
  FortuneAlgorithm (const std::vector <Point <T>>& sites);
  inline Voronoi <T> getDiagram () const { return diagram; }

};
