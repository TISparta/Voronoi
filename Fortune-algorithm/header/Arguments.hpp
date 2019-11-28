#pragma once

#include <string>
#include <vector>

#include "Point.hpp"

const int N_POINTS = 10;
const int WIDTH = 800;
const int HEGIHT = 600;
const int MIN_VAL = -1000;
const int MAX_VAL =  1000;
const std::string OUTPUT_FILE_NAME = "diagram";

struct Arguments {
  int n_points = N_POINTS;
  int width = WIDTH;
  int height = HEGIHT;
  int min_val = MIN_VAL;
  int max_val = MAX_VAL;
  std::string output_file_name = OUTPUT_FILE_NAME;
  std::vector <Point> sites; 

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
