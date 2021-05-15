#include "src/Caminhamento/kruskal.cpp"
#include "src/Permutacao/bfs.cpp"

Grafo carregarTeste01(Grafo g)
{
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
  return g;
}

Grafo carregarTeste02(Grafo g)
{
  //  making above shown graph
  g.addArestaSemPeso(0, 1);
  g.addArestaSemPeso(0, 2);
  g.addArestaSemPeso(0, 3);
  g.addArestaSemPeso(1, 2);
  g.addArestaSemPeso(2, 3);

  return g;
}

Grafo carregarTeste03(Grafo g)
{
  //  making above shown graph
  g.addArestaSemPeso(0, 1);
  g.addArestaSemPeso(0, 2);

  g.addArestaSemPeso(2, 1);
  g.addArestaSemPeso(2, 3);
  g.addArestaSemPeso(2, 4);

  g.addArestaSemPeso(5, 4);  
  g.addArestaSemPeso(5, 6); 
  g.addArestaSemPeso(5, 7); 
  g.addArestaSemPeso(5, 8);

  g.addArestaSemPeso(7, 9);
  g.addArestaSemPeso(7, 8);  

  
  return g;
}



void runKruskal (){

}







// Driver program to test above functions
int main(int argc, char *argv[])
{
  /* Let us create above shown weighted
     and unidrected graph */
  int V = 10, E = 11;
  Grafo g(V, E);

  g = carregarTeste02(g);
  //std::cout << "As arestas da MST são: " << std::endl;

  BFS bfs;

  auto result = bfs.bfs_cycle_detection(g,0);

  std::cout << "Quantidade de ciclos: " << result << std::endl;

  return 0;
}