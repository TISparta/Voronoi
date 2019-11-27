/*
 * file: voro.cpp
 * Implementación fuerza bruta
 * author: Jhony Angulo
 * date: 25-11-2019
 */
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "point.hpp"
#include "voronoi.hpp"

using namespace std;

class Window{
	GLFWwindow *window{nullptr};
	std::string title;
    Voronoi::NaiveSolution naive;
public:
	Window(int width, int height,int n, int p,std::string title);
	void display();
};

int main(){
    int p;
    cin>>p;
    Window m(100,100,100,p,"Fuerza bruta");
    m.display();
}

Window::Window(int width, int height, int n,int p, std::string title)
    : naive(n,p, width, height)
{
	glfwInit();
	glfwWindowHint(GLFW_SAMPLES, 4);// Check this
	window = glfwCreateWindow( width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent( window );
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
    glLineWidth(5);
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void Window::display(){
    GLint width,height,old_width, old_height;
    glfwGetWindowSize(window, &width, &height);
    
    naive.setDimension(width, height);

	while ( !glfwWindowShouldClose(window) ) {
        glfwGetWindowSize(window, &width, &height);
        if( width != old_width || height != old_height) {
            naive.setDimension(width, height);
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
    
        naive.render();
    
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
