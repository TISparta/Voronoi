#include "../header/util.hpp"
#include "../header/FortuneAlgorithm.hpp"

using T = float;

int main (int argc, char** argv) {
#ifdef FORTUNE
  Arguments <T> arg;
  util::parse_arguments (argc, argv, arg);
  arg.verify ();
  if (arg.sites.empty ()) {
    util::generate_random_sites (arg.n_points, arg.min_val, arg.max_val, arg.sites);
  }
  FortuneAlgorithm <T> fortune (arg.sites);
  VoronoiDiagram <T> diagram = fortune.getDiagram ();

  // Iterating cells
  for (auto cell: diagram.cells) {
    Point <T> site = cell.site;
    HalfEdge <T>* edge = cell.edges;
    do {
      Point <T> from = edge->from;
      Point <T> to = edge->to;
      // do something with (site, from, to)
      edge = edge->next;
    } while (edge != cell.edges);
  }

  // Iterating vertices
  for (auto edge: diagram.edges) {
    edge -> print ();
  }

#else
  // Jhonny's task
#endif
  return (0);
}
