#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Naive.hpp"

template<typename V>
class Visualization {
	GLFWwindow *window{nullptr};
	std::string title;  
  V voronoi;
public:
	Visualization(int width, int height,int n, int p,std::string title)
    : voronoi(n,p, width, height)
  {
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
    voronoi.setDimension(width, height);

    while ( !glfwWindowShouldClose(window) ) {
      glfwGetWindowSize(window, &width, &height);
      if( width != old_width || height != old_height) {
        voronoi.setDimension(width, height);
        old_width = width;
        old_height = height;
      }
      glLoadIdentity();
      glViewport(0, 0, width, height);

      glPointSize(3);
      glClearColor(0, 0, 0, 1);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glMatrixMode(GL_PROJECTION_MATRIX);
      glLoadIdentity();
    
      voronoi.render();
    
      glfwSwapBuffers(window);
      glfwPollEvents();
    }
  }
};
