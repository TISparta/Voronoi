CC = g++
LIBS = -lGL -lglfw
TARGET = fortune naive

ALL: $(TARGET)

fortune: FORCE
	$(CC) src/main.cpp -o fortune -DFORTUNE

naive: src/main.cpp header/Point.hpp
	$(CC) src/main.cpp -o naive $(LIBS) -O2

FORCE: ;

clean:
	rm fortune naive
