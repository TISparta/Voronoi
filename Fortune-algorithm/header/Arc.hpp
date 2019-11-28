#pragma once

#include "Point.hpp"

template <typename T>
struct event;

template <typename T>
struct Arc {
  Point <T> p;
  Arc *prev = 0;
  Arc *next = 0;
  
  Arc (Point <T> p, Arc *prev = 0, Arc *next = 0):
    p(p), prev(prev), next(next) {}
};
