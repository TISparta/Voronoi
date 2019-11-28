#pragma once

#include "Point.hpp"

class Event {
public:
  enum class Type {
    SITE_EVENT,
    CIRCLE_EVENT
  };

  bool operator < (const Event& other)
  {
    return p < other.p;
  }

private:
  Point p;
  bool valid;
};
