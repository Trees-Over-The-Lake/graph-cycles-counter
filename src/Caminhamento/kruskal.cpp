#ifndef KRUSKAL_CPP
#define KRUSKAL_CPP

#include "kruskal.hpp"

static uint16_t kruskal(Grafo g)
{

  auto arestas = g.get_arestas();
  uint16_t n_of_cycles = 0;

  std::sort(arestas.begin(), arestas.end());

  // Iterar através de todos os nós do grafo
  for (auto it = arestas.begin(); it != arestas.end(); it++)
  {
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.procurar(u)
    int set_v = ds.procurar(v);

    // Verificando se v e u são um ciclo, será se os dois estiveram dentro do
    // mesmo set
    if (set_u != set_v)
    {
      // Escrever aresta final
      std::cout << "Pesos: " << it->first << " \t| Arestas: " << u << " - " << v
                << std::endl;
      ds.unir(set_u, set_v);
    }
  }
}

#endif