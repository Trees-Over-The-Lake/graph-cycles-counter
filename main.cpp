#include <iostream>
#include "Simple-Graph/graph.cpp"



int main(int argc, char **argv){
    Graph graph;
   
    graph.add_edge(0,1);
    graph.add_edge(1,2);

    graph.print();
    return 0;
}