#include "src/Caminhamento/kruskal.cpp"
#include "src/Permutacao/bfs.cpp"
#include <limits>

long NTESTE = 1000000;

typedef std::numeric_limits<double> dbl;

Grafo carregarTeste01()
{
  Grafo graph(14, 12);
  graph.addAresta(1, 1, 4);
  graph.addAresta(1, 2, 8);
  graph.addAresta(2, 7, 8);

  graph.addAresta(3, 7, 11);
  graph.addAresta(5, 3, 7);

  graph.addAresta(9, 5, 4);
  graph.addAresta(10, 4, 9);
  graph.addAresta(1, 5, 14);

  graph.addAresta(3, 5, 10);
  graph.addAresta(4, 6, 2);
  graph.addAresta(6, 7, 1);

  graph.addAresta(5, 8, 6);


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

  graph.addAresta(5, 0, 1);
  graph.addAresta(8, 0, 2);
  graph.addAresta(7, 2, 1);

  graph.addAresta(3, 2, 3);
  graph.addAresta(4, 2, 4);
  graph.addAresta(1, 5, 4);

  graph.addAresta(9, 5, 6);
  graph.addAresta(12, 5, 7);
  graph.addAresta(1, 5, 8);

  graph.addAresta(9, 7, 9);
  graph.addAresta(14, 7, 8);

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

//
Grafo carregarTeste06()
{
  Grafo graph(8, 13);

  graph.addAresta(15, 0, 1);
  graph.addAresta(25, 0, 2);

  graph.addAresta(10, 1, 2);
  graph.addAresta(20, 1, 3);

  graph.addAresta(18, 2, 3);
  graph.addAresta(14, 2, 4);

  graph.addAresta(10, 3, 5);
  graph.addAresta(1, 3, 4);

  graph.addAresta(9, 4, 5);
  graph.addAresta(10, 4, 6);

  graph.addAresta(2, 5, 6);
  graph.addAresta(30, 5, 7);

  graph.addAresta(6, 5, 7);

  return graph;
}

Grafo carregarTeste07()
{
  Grafo graph(5, 8);

  graph.addAresta(2, 1, 0);
  graph.addAresta(3, 3, 0);
  graph.addAresta(1, 0, 4);
  graph.addAresta(1, 1, 4);
  graph.addAresta(0, 3, 1);
  graph.addAresta(1, 4, 3);
  graph.addAresta(1, 2, 1);
  graph.addAresta(1, 2, 3);

  return graph;
}

void benchmarkKruskal()
{
  clock_t time01 = 0;
  clock_t min01 = 1000000000;
  clock_t max01 = 0;
  Grafo graph(0, 0);
  Kruskal kruskal;

  std::cout.precision(dbl::max_digits10);

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "|          Benchmark Kruskal           |" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  graph = carregarTeste01();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }

  //Mostrar resultados
  std::cout << "Rodada 01 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 14 e Arestas 12" << std::endl;

  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  //nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste02();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 02 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 4 e Arestas 4" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste03();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 03 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 10 e Arestas 11" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste04();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 04 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 6 e Arestas 9" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;
  graph = carregarTeste05();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 05 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 10 e Arestas 15" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;
  graph = carregarTeste06();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 06 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 7 e Arestas 13" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste07();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    kruskal.kruskal_cycle_detection(graph);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 07 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 5 e Arestas 8" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

void benchmarkBFS()
{
  clock_t time01 = 0;
  clock_t min01 = 1000000000;
  clock_t max01 = 0;
  Grafo graph(0, 0);
  BFS bfs;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "|          Benchmark BFS                 |" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  graph = carregarTeste01();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 01 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 14 e Arestas 12" << std::endl;
  std::cout << "Grafo com  " << NTESTE << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  //nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste02();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 02 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 4 e Arestas 4" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste03();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 03 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 10 e Arestas 11" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste04();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 04 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 6 e Arestas 9" << std::endl;

  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;
  graph = carregarTeste05();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 05 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 10 e Arestas 15" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;
  graph = carregarTeste06();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 06 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 7 e Arestas 13" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Nova rodada de teste
  time01 = 0;
  min01 = 1000000;
  max01 = 0;

  graph = carregarTeste07();
  for (long i = 0; i < NTESTE; i++)
  {

    clock_t start = clock();
    bfs.bfs_cycle_detection(graph, 0);
    clock_t end = clock() - start; // Get the time needed to run the function

    time01 += end;
    if (end > max01)
    {
      max01 = end;
    }

    if (end < min01)
    {
      min01 = end;
    }
  }
  //Mostrar resultados
  std::cout << "Rodada 07 de teste         | Número de testes " << NTESTE << std::endl;
  std::cout << "Grafo com Vertices 5 e Arestas 8" << std::endl;
  std::cout << "Quantidade tempo total gasto nas operações: " << ((double)time01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade media de tempo gasto nas operações: " << ((double)(time01 / NTESTE)) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade minima de tempo gasto nas operações: " << ((double)min01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << "Quantidade Maximo de tempo gasto nas operações: " << ((double)max01) / ((CLOCKS_PER_SEC / 1000)) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

// Driver program to test above functions
int main(int argc, char *argv[])
{
  benchmarkKruskal();
  benchmarkBFS();

  return 0;
}
