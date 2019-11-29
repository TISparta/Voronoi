#pragma once

#include "Point.hpp"
#include "Cell.hpp"

template <typename T>
struct Arc;

template <typename T>
struct Event {
  enum class Type {
    SITE_EVENT,
    CIRCLE_EVENT
  };

  Event (Point <T> p):
    type (Type::SITE_EVENT),
    p (p) {}

  Event (T x, Point <T> p, Arc <T>* arc):
    type (Type::CIRCLE_EVENT),
    x (x),
    p (p),
    arc (arc) {}

  bool operator < (const Event <T>& other) const
  {
    return p < other.p;
  }

  T x;
  Type type;
  Point <T> p;
  Arc <T> *arc;
  bool valid;
};

template <typename T>
struct Arc {
  Point <T> p;
  Arc <T>* prev = 0;
  Arc <T>* next = 0;
  Event <T> *event = 0;
  HalfEdge <T>* edge_left = 0;
  HalfEdge <T>* edge_right = 0;

  Arc (Point <T> p, Arc *prev = 0, Arc *next = 0):
    p(p), prev(prev), next(next) {}
};
