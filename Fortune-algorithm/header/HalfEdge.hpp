#pragma once

#include "Point.hpp"

class HalfEdge {
public:

private:
  Point* from = nullptr;
  Point* to = nullptr;
  HalfEdge* prev = nullptr;
  HalfEdge* next = nullptr;
};
