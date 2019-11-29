#pragma once

#include "Point.hpp"

template <typename T>
class Event;

template <typename T>
struct Arc {
  Point <T> p;
  Arc <T>* prev = 0;
  Arc <T>* next = 0;
  Event <T> *event;

  Arc (Point <T> p, Arc *prev = 0, Arc *next = 0):
    p(p), prev(prev), next(next) {}
};
