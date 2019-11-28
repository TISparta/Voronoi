LIBS = -lGL -lglfw

voronoi: FORCE
	g++ src/main.cpp -o fortune -DFORTUNE
	g++ src/main.cpp -o naive $(LIBS)

FORCE: ;

clean:
	rm fortune naive
