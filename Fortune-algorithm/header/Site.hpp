#pragma once

#include "Point.hpp"
#include "HalfEdge.hpp"

template <typename T>
struct Site {


  Point <T> site;
  HalfEdge <T> edges;

};
