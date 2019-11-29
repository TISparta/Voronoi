#pragma once

#include <GL/glew.h>
#include <chrono>
#include <cmath>
#include <ostream>
#include <random>

template<typename T>
struct Point{
  const T EPS = 1e-6;
	T x,y,z;
  double color[3];
	Point() {
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        x=y=z=0;
    }

  Point (T x, T y): x(x), y(y) {}

	Point(T x,T y,T z)
        : x(x), y(y), z(z)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_real_distribution<> dist(0, 1);

        color[0] = dist(generator);
        color[1] = dist(generator);
        color[2] = dist(generator);
    };

	Point<T> operator+(const Point<T>& point)const {
        Point<T> r(x+point.x,y+point.y,z+point.z);
        return r;
    }

	Point<T> operator-(const Point<T>& point)const {
        Point<T> r(x-point.x,y-point.y,z-point.z);
        return r;
    };

    Point<T> operator/(const double& a)const{
        Point<T> r(x/a,y/a,z/a);
        return r;
    }

	Point<T> operator*(const double& a)const {
        Point<T> r(x*a,y*a,z*a);
        return r;
    };

	bool operator!=(const Point<T> &point)const {
        return (x!=point.x)&&(y!=point.y)&&(z!=point.z);        
    };

	Point<T>& operator=(const Point<T>& point) {
        x = point.x;
        y = point.y;
        z = point.z;
        return *this;
    }

  bool operator < (const Point <T>& other) const
  {
    if (not (std::fabs (x - other.x) < EPS)) return x < other.x;
    return y < other.y;
  }

  bool operator == (const Point <T>& other) const
  {
    return std::fabs (x - other.x) < EPS and std::fabs (y == other.y) < EPS;
  }


	void render() {
        glColor3f(color[0], color[1], color[2]);
        glVertex3f(x, y, z);
    };

    friend double p_norm(const Point<T>&point, int p) {
        double x = pow(fabs(point.x),p);
        double y = pow(fabs(point.y),p);
        double z = pow(fabs(point.z),p);
        return pow(x+y+z,1./p);
    }
    
	friend std::ostream &operator<<(std::ostream& os, const Point<T>&p){
		os<<p.x<<" "<<p.y<<" "<<p.z;
		return os;  
	};
};

template<typename T>
Point<T> operator* (double a, Point<T> p) {
    return p*a;
}
