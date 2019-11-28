#pragma once

#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

#include "VoronoiDiagram.hpp"
#include "Event.hpp"

template <typename T>
class FortuneAlgorithm {
private:
  VoronoiDiagram <T> diagram;
  std::priority_queue <Event <T>> pq;
  
  void compute_bounds (const std::vector <Point <T>>& sites)
  {
    diagram.min_x = diagram.min_y = INT_MAX;
    diagram.max_x = diagram.max_y = INT_MIN;
    for (auto p: sites) {
      diagram.min_x = std::min (diagram.min_x, int (std::floor (p.x)));
      diagram.max_x = std::max (diagram.min_x, int (std::ceil (p.x)));
      diagram.min_y = std::min (diagram.min_y, int (std::floor (p.y)));
      diagram.max_y = std::max (diagram.min_y, int (std::ceil (p.y)));
    }
  }
  
  void compute_diagram (const std::vector <Point <T>>& sites)
  {
    init_site_events (sites);
    while (not pq.empty ()) {
      
    }
  }
  
  void init_site_events (const std::vector <Point <T>>& sites)
  {
   for (auto p: sites) {
     pq.push (p);
   }

  }

public:
  FortuneAlgorithm (const std::vector <Point <T>>& sites)
  {
    compute_bounds (sites);
    compute_diagram (sites);
  }

  inline VoronoiDiagram <T> getDiagram () const { return diagram; }

};
