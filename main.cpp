#include "src/Caminhamento/kruskal.cpp"

// Driver program to test above functions
int main(int argc, char* argv[]) {
  /* Let us create above shown weighted
     and unidrected graph */
  int V = 9, E = 14;
  Grafo g(V, E);

  //  making above shown graph
  g.addAresta(1, 1, 4);
  g.addAresta(1, 2, 8);
  g.addAresta(2, 7, 8);
  g.addAresta(3, 7, 11);
  g.addAresta(5, 3, 7);
  g.addAresta(7, 8, 2);
  g.addAresta(9, 5, 4);
  g.addAresta(10, 4, 9);
  g.addAresta(1, 5, 14);
  g.addAresta(3, 5, 10);
  g.addAresta(4, 6, 2);
  g.addAresta(6, 7, 1);
  g.addAresta(5, 8, 6);
  g.addAresta(3, 8, 7);

  std::cout << "As arestas da MST são: " << std::endl;
  g.kruskal();

  return 0;
}