#include "../Grafo.hpp"

// Driver program to test above functions
int main() {
  /* Let us create above shown weighted
     and unidrected graph */
  int V = 9, E = 14;
  Grafo g(V, E);

  //  making above shown graph
  g.addAresta('A', 1, 4);
  g.addAresta('B', 2, 8);
  g.addAresta('A', 7, 8);
  g.addAresta('B', 7, 11);
  g.addAresta('C', 3, 7);
  g.addAresta('C', 8, 2);
  g.addAresta('C', 5, 4);
  g.addAresta('D', 4, 9);
  g.addAresta('D', 5, 14);
  g.addAresta('E', 5, 10);
  g.addAresta('F', 6, 2);
  g.addAresta('G', 7, 1);
  g.addAresta('H', 8, 6);
  g.addAresta('I', 8, 7);

  std::cout << "As arestas da MST são: " << std::endl;
  g.kruskal();

  return 0;
}