all:proj4
proj4: main.o Graph.o priorityQueue.o
	g++ main.o Graph.o priorityQueue.o  -o proj4
Graph.o: Graph.cpp Graph.h priorityQueue.h
	g++ -c Graph.cpp

main.o: main.cpp Graph.h
	g++ -c main.cpp

priorityQueue.o: priorityQueue.cpp priorityQueue.h
	g++ -c priorityQueue.cpp

clean:
	rm -rf *o proj4
