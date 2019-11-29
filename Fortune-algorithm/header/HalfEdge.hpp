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
  void render () {
    glColor3f(0.0,1.0,.0);

    glBegin(GL_LINE_LOOP);
		glVertex2f(from.x/10000, from.y/10000);
		glVertex2f(to.x/10000, to.y/10000);
    glEnd();
    glBegin(GL_LINE_LOOP);
  }
};
