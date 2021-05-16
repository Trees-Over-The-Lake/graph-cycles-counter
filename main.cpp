#include "src/Caminhamento/kruskal.cpp"
#include "src/Permutacao/bfs.cpp"

Grafo carregarTeste01()
{
  Grafo graph(14, 12);
  graph.addAresta(1, 1, 4);
  graph.addAresta(1, 2, 8);
  graph.addAresta(2, 7, 8);

  graph.addAresta(3, 7, 11);
  graph.addAresta(5, 3, 7);
  graph.addAresta(7, 8, 2);

  graph.addAresta(9, 5, 4);
  graph.addAresta(10, 4, 9);
  graph.addAresta(1, 5, 14);

  graph.addAresta(3, 5, 10);
  graph.addAresta(4, 6, 2);
  graph.addAresta(6, 7, 1);
  
  graph.addAresta(5, 8, 6);
  graph.addAresta(3, 8, 7);

  return graph;
}

Grafo carregarTeste02()
{
  Grafo graph(4, 4);
  graph.addArestaSemPeso(0, 1);
  graph.addArestaSemPeso(0, 2);
  graph.addArestaSemPeso(0, 3);

  graph.addArestaSemPeso(1, 2);
  graph.addArestaSemPeso(2, 3);

  return graph;
}

Grafo carregarTeste03()
{
  Grafo graph(10, 11);

  graph.addArestaSemPeso(0, 1);
  graph.addArestaSemPeso(0, 2);
  graph.addArestaSemPeso(2, 1);

  graph.addArestaSemPeso(2, 3);
  graph.addArestaSemPeso(2, 4);
  graph.addArestaSemPeso(5, 4);

  graph.addArestaSemPeso(5, 6);
  graph.addArestaSemPeso(5, 7);
  graph.addArestaSemPeso(5, 8);

  graph.addArestaSemPeso(7, 9);
  graph.addArestaSemPeso(7, 8);

  return graph;
}

Grafo carregarTeste04()
{
  Grafo graph(6, 9);

  graph.addAresta(10, 0, 1);
  graph.addAresta(10, 0, 2);
  graph.addAresta(2, 1, 2);

  graph.addAresta(4, 1, 3);
  graph.addAresta(8, 1, 4);
  graph.addAresta(9, 2, 4);

  graph.addAresta(10, 3, 5);
  graph.addAresta(6, 3, 4);
  graph.addAresta(10, 4, 5);

  return graph;
}

Grafo carregarTeste05()
{
  Grafo graph(10, 15);

  graph.addAresta(5, 0, 1);
  graph.addAresta(10, 0, 4);
  graph.addAresta(2, 0, 6);

  graph.addAresta(8, 1, 2);
  graph.addAresta(1, 1, 7);
  graph.addAresta(4, 2, 3);
 
  graph.addAresta(4, 2, 8);
  graph.addAresta(5, 3, 4);
  graph.addAresta(3, 3, 9);

  graph.addAresta(15, 4, 5);
  graph.addAresta(12, 6, 8);
  graph.addAresta(7, 6, 9);

  graph.addAresta(3, 8, 5);
  graph.addAresta(3, 5, 7);
  graph.addAresta(8, 7, 9);

  return graph;
}

// Driver program to test above functions
int main(int argc, char *argv[])
{
  /* Let us create above shown weighted
     and unidrected graph */
  int V = 10, E = 10;
  Grafo g(V, E);

  g = carregarTeste04();

  BFS bfs;
  Kruskal kruskal;

  // auto result = bfs.bfs_cycle_detection(g, 0);

  auto result = kruskal.kruskal_cycle_detection(g);

  std::cout << "Quantidade de ciclos: " << result << std::endl;

  return 0;
}
