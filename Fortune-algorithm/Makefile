CC = g++
LIBS = -lGL -lglfw -fopenmp
TARGET = fortune naive

ALL: $(TARGET)

fortune: FORCE
	$(CC) src/main2.cpp -o fortune -DFORTUNE

naive: src/main.cpp header/Point.hpp header/Visualization.hpp header/Naive.hpp
	$(CC) src/main2.cpp -o naive $(LIBS) -O2

FORCE: ;

clean:
	rm fortune naive
