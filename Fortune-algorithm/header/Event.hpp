#pragma once

#include "Point.hpp"
#include "Site.hpp"

template <typename T>
class Event {
public:
  enum class Type {
    SITE_EVENT,
    CIRCLE_EVENT
  };

  Event (Site <T> s):
    type (Type::SITE_EVENT),
    p (s.site) {}

  bool operator < (const Event& other)
  {
    return p < other.p;
  }

private:
  Type type;
  Point <T> p;
  bool valid;
};
