#include "../header/util.hpp"
#include "../header/Voronoi.hpp"

int main (int argc, char** argv) {
  Arguments arg;
  util::parse_arguments (argc, argv, arg);
  arg.verify ();
  if (arg.sites.empty ()) {
    util::generate_random_sites (arg.n_points, arg.min_val, arg.max_val, arg.sites);
  }
  Voronoi diagram;
  diagram.generate_diagram (arg);
  return (0);
}
