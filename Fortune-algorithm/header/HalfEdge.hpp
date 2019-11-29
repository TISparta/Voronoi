#pragma once

#include "Point.hpp"

template <typename T>
struct HalfEdge {
  HalfEdge (Point <T> from): from(from) {}

  Point <T> from;
  Point <T> to;
  HalfEdge* prev = nullptr;
  HalfEdge* next = nullptr;

  void print () {
    printf ("(%f,%f) -> (%f,%f)\n", from.x, from.y, to.x, to.y);
  }

};
