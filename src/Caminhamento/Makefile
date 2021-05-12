obj := prim.cpp ../../Simple-Graph/graph.cpp ../../Simple-Graph/graph/*.cpp
executable := graph.out

all:
	g++ $(obj) -O3 -o $(executable)

run: all
	clear
	./$(executable)
	
clean:
	rm $(executable)
