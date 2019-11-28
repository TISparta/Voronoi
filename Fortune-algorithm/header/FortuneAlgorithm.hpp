#pragma once

#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

#include "VoronoiDiagram.hpp"
#include "Event.hpp"
#include "Arc.hpp"

template <typename T>
class FortuneAlgorithm {
private:
  VoronoiDiagram <T> diagram;
  std::priority_queue <Event <T>> pq;
  Arc <T> *beachline = 0;

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
    for (auto p: sites) pq.push (Event <T> (p));
    while (not pq.empty ()) {
      auto event = pq.top ();
      pq.pop ();
      if (not event.valid) continue;
      if (event.type == Event <T>::Type::SITE_EVENT) {
        process_site_event (event);
      }
      if (event.type == Event <T>::Type::CIRCLE_EVENT) {
        process_circle_event (event);
      }
    }
  }

  void process_site_event (Event <T> event)
  {
    Point <T> p = event.p;
    // insert p to the brachline
  }

  void process_circle_event (Event <T> event)
  {
    Point <T> p = event.p;
    if (!beachline) {
      beachline = new Arc <T> (p);
      return;
    }
    HalfEdge <T>* cur_edge = new HalfEdge <T> (p);
    Arc <T>* cur_arc = event->arc;
    if (cur_arc->prev)
    {
      cur_arc->prev->next = cur_arc->next;
      // TODO
    }
    if (cur_arc->next)
    {
      cur_arc->next = cur_arc->prev;
      // TODO
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
