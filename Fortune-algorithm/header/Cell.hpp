#pragma once

#include "Point.hpp"
#include "HalfEdge.hpp"

template <typename T>
struct Cell {

  Point <T> site;
  HalfEdge <T>* edges;

};
