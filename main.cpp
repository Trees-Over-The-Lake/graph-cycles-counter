#include <iostream>
#include "Simple-Graph/graph.cpp"

Graph teste01(Graph graph){
    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,4);
    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(3,5);
    graph.add_edge(5,6);
    graph.add_edge(5,7);
    graph.add_edge(5,8);
    graph.add_edge(7,8);
    graph.add_edge(8,9);
    
    return graph;
}

Graph teste02(Graph graph){
 graph.add_edge(0,3);
    graph.add_edge(3,2);
    graph.add_edge(2,1);
    graph.add_edge(0,1);
    graph.add_edge(1,3);
    return graph;
}



int main(int argc, char **argv){
    Graph graph;
    graph.add_edge(0,3);
    graph.add_edge(3,2);
    graph.add_edge(2,1);
    graph.add_edge(0,1);
    graph.add_edge(1,3);
    
    graph.print();

    id n_cycles = graph.bfs(0);
    
    std::cout << "Número de ciclos: " << n_cycles << std::endl;
    
    return 0;
}