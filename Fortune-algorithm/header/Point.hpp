#pragma once

#include <GL/glew.h>
#include <chrono>
#include <cmath>
#include <ostream>
#include <random>

template<typename T>
struct Point{
	T x,y;
  double color[3];
	Point()
  {
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    x=y=0;
  }

  Point (T x, T y)
    : x(x), y(y)
  {
    unsigned seed = std::chrono::system_clock::now()
      .time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<> dist(0, 1);

    color[0] = dist(generator);
    color[1] = dist(generator);
    color[2] = dist(generator);    
  }

	Point<T> operator+(const Point<T>& point)const
  {
    Point<T> r(x+point.x,y+point.y);
    return r;
  }

	Point<T> operator-(const Point<T>& point)const
  {
    Point<T> r(x-point.x,y-point.y);
    return r;
  };

  Point<T> operator/(const double& a)const
  {
    Point<T> r(x/a,y/a);
    return r;
  }

	Point<T> operator*(const double& a)const
  {
    Point<T> r(x*a,y*a);
    return r;
  };

	bool operator!=(const Point<T> &point)const
  {
    return (x!=point.x)&&(y!=point.y);
  };

	Point<T>& operator=(const Point<T>& point)
  {
    x = point.x;
    y = point.y;
    return *this;
  }

  bool operator < (const Point <T>& other) const
  {
    if (y != other.y) return y < other.y;
    return x < other.x;
  }

  bool operator == (const Point <T>& other) const
  {
    return x == other.x and y == other.y;
  }


	void render() {
    glColor3f(color[0], color[1], color[2]);
    glVertex2f(x, y);
  };

  friend double p_norm(const Point<T>&point, int p)
  {
    double x = pow(fabs(point.x),p);
    double y = pow(fabs(point.y),p);
    return pow(x+y,1./p);
  }
    
	friend std::ostream &operator<<(std::ostream& os, const Point<T>&p){
		os<<p.x<<" "<<p.y;
		return os;  
	};
};

template<typename T>
Point<T> operator* (double a, Point<T> p) {
    return p*a;
}
