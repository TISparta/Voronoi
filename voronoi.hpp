#ifndef VORONOI_HPP
#define VORONOI_HPP
#include "point.hpp"
#include <vector>
#include <thread>

namespace Voronoi {
    std::vector<Point<double>> points;
    class NaiveSolution {
        std::vector<std::vector<Point<double>>> pixels;
        int iteration{0};
        int n;
        int p;
        void generateCoordinates(int width, int height) {
            
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
            int width = pixels.size();
            int height = pixels[0].size();
            for(int i=iteration; i<iteration+5 && i<width; i++) {
                for(int c=0; c<height;c++) {
                    double min = 100;
                    for(auto &point: points) {
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
            iteration += 5;
        }
    public:
        NaiveSolution(int n, int p, int width, int height)
            : n(n), p(p)
        {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine generator(seed);
            std::uniform_real_distribution<> dist(-1, 1);
            for(int i = 0; i<n; ++i) {
                double x = dist(generator);
                double y = dist(generator);
                points.emplace_back(x,y,0);
            }
            generateCoordinates(width, height);
        };
        void setDimension(int width, int height) {
            iteration = 0;
            generateCoordinates(width, height);
        }
        void setNorm(int p) { this->p=p;
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
                glVertex3f(p.x, p.y, p.z);
            }
            glEnd();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            update();
        }
    };
}

#endif
