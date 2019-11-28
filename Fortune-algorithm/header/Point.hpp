#pragma once

using T = float;

struct Point {
  T x;
  T y;
  
  Point () {}
  Point (T x, T y): x(x), y(y) {}
  
  bool operator < (const Point& other) const
  {
    if (y != other.y) return y < other.y;
    return x < other.x;
  }

  bool operator == (const Point& other) const
  {
    return x == other.x and y == other.y;
  }
};
