CC = g++
FLAGS = -Wall -Werror -pedantic --std=c++17
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = Sokoban.hpp matrix.hpp
PROGRAM = Sokoban test
OBJECTS = Sokoban.o matrix.o 

.PHONY: all clean lint

all: $(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(FLAGS) -c $< 

Sokoban: $(OBJECTS) main.o
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

test: $(OBJECTS) test.o
	$(CC) $(FLAGS) -o $@ $^ $(LIB) 

clean:
	rm *.o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp