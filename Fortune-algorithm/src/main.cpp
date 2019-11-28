#include "../header/util.hpp"
#include "../header/Voronoi.hpp"

using T = float;

int main (int argc, char** argv) {
#ifdef FORTUNE
  Arguments <T> arg;
  util::parse_arguments (argc, argv, arg);
  arg.verify ();
  if (arg.sites.empty ()) {
    util::generate_random_sites (arg.n_points, arg.min_val, arg.max_val, arg.sites);
  }
  Voronoi <T> diagram;
  // diagram.generate_diagram (arg);
#else
  // Jhonny's task
#endif
  return (0);
}
