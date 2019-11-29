#pragma once

#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

#include "VoronoiDiagram.hpp"
#include "Event.hpp"
#include "util.hpp"

template <typename T>
class FortuneAlgorithm {
private:
  VoronoiDiagram <T> diagram;
  std::priority_queue <Event <T>> pq;
  Arc <T> *beachline = 0;

  /**
   * Get the left-right most x-coordinate and upper-loweer y-coordinate
   */
  void compute_bounds (const std::vector <Point <T>>& sites)
  {
    diagram.min_x = diagram.min_y =  util::INF;
    diagram.max_x = diagram.max_y = -util::INF;
    for (auto p: sites) {
      diagram.min_x = std::min (diagram.min_x, int (std::floor (p.x)));
      diagram.max_x = std::max (diagram.min_x, int (std::ceil (p.x)));
      diagram.min_y = std::min (diagram.min_y, int (std::floor (p.y)));
      diagram.max_y = std::max (diagram.min_y, int (std::ceil (p.y)));
    }
  }
  
  /**
   * Computes the Voronoi diagram
   */
  void compute_diagram (const std::vector <Point <T>>& sites)
  {
    // Init site events
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

  /**
   * Process the site event
   */
  void process_site_event (Event <T>& event)
  {
    Point <T> p = event.p;
    insert_to_beachline (p);
  }

  /**
   * Insert the arc generated by p to the beach line
   */
  void insert_to_beachline (Point <T>& p)
  {
    if (!beachline) {
      beachline = new Arc <T> (p);
      return;
    }
    Arc <T>* last = 0;
    Point <T> z1, z2;
    for (Arc <T>* cur = beachline; cur != NULL; cur = cur->next) {
      last = cur;
      if (util::intersect (p, cur, z1)) {
        // Insert and arc between 'cur' and 'cur->next'
        if (cur->next and not util::intersect (p, cur->next, z2)) {
          cur->next->prev = new Arc <T> (cur->p, cur, cur->next);
          cur->next = cur->next->prev;
        } else {
          cur->next = new Arc <T> (cur->p, cur);
        }
        
        cur->next->edge_left = cur->edge_left;

        // Insert parabola generate by p between 'cur' and 'cur->next'
        cur->next->prev = new Arc <T> (p, cur, cur->next);
        cur->next = cur->next->prev;
        cur = cur->next;
        
        // Add edges to the diagram
        cur->prev->edge_right = cur->edge_left  = new HalfEdge <T> (z1);
        cur->next->edge_left  = cur->edge_right = new HalfEdge <T> (z1);
        diagram.edges.push_back (cur->edge_left);
        diagram.edges.push_back (cur->edge_right);
        
        // check if new circle events were produced
        check_circle_event (cur, p.x);
        check_circle_event (cur->prev, p.x);
        check_circle_event (cur->next, p.x);
        return;
      }
    }
    // If p never intersect the beachline, just append it
    last->next = new Arc <T> (p, last);
    Point <T> q (diagram.min_x, (last->p.y + last->next->p.y) / 2);
    last->edge_right = last->next->edge_left = new HalfEdge <T> (q);
    diagram.edges.push_back (last->edge_right);
  }

  /**
   * Adds a new circle event if necessary
   */
  void check_circle_event (Arc <T> *arc, T x)
  {
    if (arc->event and !util::IS_EQ <T> (arc->event->x, x)) {
      arc->event->valid = false;
    }
    arc->event = 0;
    if (not arc->prev or not arc->next) return;
    T x1;
    Point <T> o;
    if (util::generate_circle_event (arc->prev->p, arc->p, arc->next->p, x1, o) and
        x < x1) {
      arc->event = new Event <T> (x1, o, arc);
      pq.push (*arc->event);
    }
  }

  /**
   * Process a circle event
   */
  void process_circle_event (Event <T> event)
  {
    T x = event.x;
    Point <T> p = event.p;
    Arc <T>* arc = event.arc;
    HalfEdge <T>* q = new HalfEdge <T> (p);
    diagram.edges.push_back (q);
    if (arc->prev) { // delete it
      arc->prev->next = arc->next;
      arc->prev->edge_right = q;
    }
    if (arc->next) { // delete it
      arc->next->prev = arc->prev;
      arc->next->edge_left = q;
    }

    if (arc->edge_left) arc->edge_left->to = p;
    if (arc->edge_right) arc->edge_right->to = p;

    if (arc->prev) check_circle_event (arc->prev, x);
    if (arc->next) check_circle_event (arc->next, x);
  }

  /**
   * Close edges that did not finish in the sweep line process
   */
  void close_edges ()
  {
    T x = diagram.max_x * 5;
    for (Arc <T>* cur = beachline; cur->next != NULL; cur = cur->next) {
      if (cur->edge_left) {
        cur->edge_left->to = util::compute_parabolas_intersection <T>
                             (cur->p, cur->next->p, x); 
      }
    }
  }

  /**
   * Filter invalid edges
   */
  void filter_edges ()
  {
    std::vector <HalfEdge <T>*> edges;
    for (auto edge: diagram.edges) {
      Point <T> p = edge->to;
      if (util::IS_EQ <T> (p.x, 0) and util::IS_EQ <T> (p.y, 0)) continue;
      edges.push_back(edge);
    }
    diagram.edges = edges;
  }

public:
  FortuneAlgorithm (const std::vector <Point <T>>& sites)
  {
    compute_bounds (sites);
    compute_diagram (sites);
    close_edges ();
    filter_edges ();
    diagram.sites = sites;
  }

  inline VoronoiDiagram <T> getDiagram () const { return diagram; }

};
