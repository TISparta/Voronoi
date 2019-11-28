#pragma once

#include "Point.hpp"

template <typename T>
class HalfEdge {
public:


private:
  Point <T>* from = nullptr;
  Point <T>* to = nullptr;
  HalfEdge* prev = nullptr;
  HalfEdge* next = nullptr;
};
