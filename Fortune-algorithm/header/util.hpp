#pragma once

#include <iostream>
#include <random>
#include <unistd.h>

#include "Arguments.hpp"

namespace util {

/**
 * Returns a random number in [l, r)
 */
static T random_real (int l, int r)
{
  std::mt19937 rng;
  rng.seed (std::random_device ()());
  std::uniform_real_distribution <> distribution(l, r);
  return distribution (rng);
}

/**
 * Returns a random point whose coordinates are in [l, r)
 */
static Point random_point (int l, int r) {
  return Point (random_real (l, r), random_real (l, r));
}

/**
 * Show help for using command line options
 */
void show_help ()
{
  puts ("./voronoi [options]");
  puts ("Options");
  puts ("\t -n <number_points>");
  puts ("\t -w <width>");
  puts ("\t -h <height>");
  puts ("\t -f <output file name>");
  exit (-1);
}

/**
 * Parses the arguments and saves them
 */
static void parse_arguments (int argc, char** argv, Arguments& arg)
{ 
  int option;
  while (true) {
    option = getopt (argc, argv, "n:w:h:f:-");
    if (option == -1) break;
    switch (option) {
      case 'n':
        arg.n_points = atoi(optarg);
        break;
      case 'w':
        arg.width = atoi(optarg);
        break;
      case 'h':
        arg.height = atoi(optarg);
        break;
      case 'f':
        arg.output_file_name = std::string(optarg);
        break;
      case '-':
        show_help ();
      case '?':
        std::cout << "Unknow option\n";
        show_help ();
    }
  }
}

/**
 * Generates 'n_sites' points in 'sites'
 */
void generate_random_sites (int n_sites, int min_val, int max_val,
                            std::vector <Point>& sites)
{
  sites.clear ();
  for (int i = 0; i < n_sites; i++) {
    sites.push_back (random_point(min_val, max_val));
  }
}

}
