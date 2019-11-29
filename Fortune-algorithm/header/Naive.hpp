#pragma once
#include <limits>
#include <omp.h>
#include "Point.hpp"
#include "util.hpp"
#include <vector>
#include <thread>

namespace Voronoi {

std::vector<Point<double>> points;
class NaiveSolution {
  std::vector<std::vector<Point<double>>> pixels;
  int iteration{0};
  int width;
  int height;
  int n;
  int p;
  void updateCoordinates() {
    pixels.resize(0, std::vector<Point<double>>(0));
    pixels.resize(width, std::vector<Point<double>>(height));
    for(int i=0;i<width;i++) {
      for(int j = 0; j<height; ++j) {
        pixels[i][j].x = -1+2*(double)i/width;
        pixels[i][j].y = -1+2*(double)j/height;
      }
    }
  }
  void update(){
    int delta = 100;
#pragma omp parallel for
    for(int c=0; c<height;c++) {
      for(int i=iteration; i<iteration+delta && i<width; i++)
        {
          double min = std::numeric_limits<double>::max();
          for(auto &point: points)
            {
              double m = p_norm(point-pixels[i][c], p);
              if(m<min) {
                min=m;
                pixels[i][c].color[0] = point.color[0];
                pixels[i][c].color[1] = point.color[1];
                pixels[i][c].color[2] = point.color[2];
              }
          }
        }
    }            
    iteration += delta;
  }
public:
  NaiveSolution(int n, int p, int width, int height)
    : n(n), p(p), width(width), height(height)
  {
    for(int i = 0; i<n; ++i) {
      double x = util::random_real<double>(-1,1);
      double y = util::random_real<double>(-1,1);
      points.emplace_back(x,y);
    }
    updateCoordinates();
  };
  void setDimension(int width, int height) {
    this->width = width;
    this->height = height;
    iteration = 0;
    updateCoordinates();
  }

  void setNorm(int p)
  {
    this->p=p;
  }

  void render() {
    glBegin(GL_POINTS);
    for(auto rpixel:pixels) {
      for(auto pixel:rpixel) {
        pixel.render();
      }
    }
    for(auto &p:points) {
      glColor3f(1, 1, 1);
      glVertex2f(p.x, p.y);
    }
    glEnd();

    if(iteration < width)
      update();
  }
};

}
