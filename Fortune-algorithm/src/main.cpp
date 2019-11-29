#include "../header/util.hpp"
#include "../header/VoronoiDiagram.hpp"
#include "../header/Visualization.hpp"
#include "../header/FortuneAlgorithm.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using T = float;

class Window {
	GLFWwindow *window{nullptr};
	std::string title;  
  Arguments <T> arg;

  FortuneAlgorithm <T> *fortune; 
  VoronoiDiagram <T> diagram;

public:
	Window(int width, int height,int n, int p,std::string title,
          Arguments <T> arg): arg(arg)
  {

    fortune = new  FortuneAlgorithm <T> (arg.sites);
    diagram = fortune->getDiagram ();

    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4);
    window = glfwCreateWindow( width, height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent( window );
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glLineWidth(5);
  }

	void display()
  {
    GLint width,height,old_width, old_height;
    glfwGetWindowSize(window, &width, &height);

    while ( !glfwWindowShouldClose(window) ) {
      glfwGetWindowSize(window, &width, &height);

      glLoadIdentity();
      glViewport(0, 0, width, height);

      glPointSize(3);
      glClearColor(0, 0, 0, 1);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glMatrixMode(GL_PROJECTION_MATRIX);
      glLoadIdentity();
    
      //Renderizar
      for (auto edge: diagram.edges) {
        edge -> render();
      }      
    
      glfwSwapBuffers(window);
      glfwPollEvents();
    }
  }
};

int main (int argc, char** argv) {
  Arguments <T> arg;
  util::parse_arguments (argc, argv, arg);
  arg.verify ();
  if (arg.sites.empty ()) {
    util::generate_random_sites (arg.n_points, arg.min_val, arg.max_val, arg.sites);
  }

#ifdef FORTUNE
	Window w(1000,1000, 10, 2,"Fortune", arg);
  w.display();
#else
  omp_set_num_threads(arg.n_threads);
  Visualization<Voronoi::NaiveSolution>
    window(arg.width, arg.height, arg.n_points, arg.n_threads, "Naive Solution");
  window.display();
#endif
  return (0);
}
