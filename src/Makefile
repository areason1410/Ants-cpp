LIBS= -lsfml-graphics -lsfml-window -lsfml-system
FILES= main.cpp world.cpp ant.cpp colony.cpp food.cpp trail.cpp grid.cpp
OUTS= main.o world.o ant.o colony.o food.o trail.o grid.o
sfml: main.cpp
	g++ -c ${FILES} -I../include
	g++ ${OUTS} -o sfml-app $(LIBS)
	./sfml-app
	rm ${OUTS}