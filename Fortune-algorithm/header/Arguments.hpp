#pragma once

#include <string>
#include <vector>

#include "Point.hpp"

const int N_POINTS = 10;
const int WIDTH = 800;
const int HEGIHT = 600;
const int MIN_VAL = -1000;
const int MAX_VAL =  1000;
const int N_THREADS = 2;

template <typename T>
struct Arguments {
  int n_points = N_POINTS;
  int n_threads = N_THREADS;
  int width = WIDTH;
  int height = HEGIHT;
  int min_val = MIN_VAL;
  int max_val = MAX_VAL;
  std::vector <Point <T>> sites; 

  void verify () {
    if (n_points <= 0) {
      puts ("Invalid number of points");
      exit (-1);
    }
    if (width <= 0 or height <= 0) {
      puts ("Invalid dimensions");
      exit (-1);
    }
    if (min_val > max_val) {
      puts ("Invalid points bounds");
      exit (-1);
    }
  }
};
