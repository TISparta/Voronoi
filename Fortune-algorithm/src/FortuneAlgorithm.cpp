#include <climits>
#include <cmath>
#include <algorithm>

#include "../header/Voronoi.hpp"
#include "../header/FortuneAlgorithm.hpp"

FortuneAlgorithm::FortuneAlgorithm (const std::vector <Point>& sites)
{
  compute_bounds (sites);
  compute_diagram (sites);
}

void FortuneAlgorithm::compute_bounds (const std::vector <Point>& sites)
{
  diagram.min_x = diagram.min_y = INT_MAX;
  diagram.max_x = diagram.max_y = INT_MIN;
  for (Point p: sites) {
    diagram.min_x = std::min (diagram.min_x, int (std::floor (p.x)));
    diagram.max_x = std::max (diagram.min_x, int (std::ceil (p.x)));
    diagram.min_y = std::min (diagram.min_y, int (std::floor (p.y)));
    diagram.max_y = std::max (diagram.min_y, int (std::ceil (p.y)));
  }
}

void FortuneAlgorithm::compute_diagram (const std::vector <Point>& sites)
{
  init_site_events (sites);
  while (not pq.empty ()) {
  }
}

void FortuneAlgorithm::init_site_events (const std::vector <Point>& sites)
{
  for (Point p: sites) {
    pq.push (p);
  }
}
