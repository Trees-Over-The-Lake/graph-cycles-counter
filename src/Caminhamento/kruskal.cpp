

#include "kruskal.hpp"

uint16_t Kruskal::kruskal_cycle_detection(Grafo g)
{

  auto arestas = g.get_arestas();
  uint16_t n_of_cycles = 0;

  std::sort(arestas.begin(), arestas.end());

  DisjointSets ds(g.num_vertex());

  // Iterar através de todos os nós do grafo
  for (auto it = arestas.begin(); it != arestas.end(); it++)
  {
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.procurar(u);
    int set_v = ds.procurar(v);

    // Verificando se v e u são um ciclo, será se os dois estiveram dentro do
    // mesmo set
    if (set_u != set_v)
    {
      // Escrever aresta final
      //std::cout << "Pesos: " << it->first << " \t| Arestas: " << u << " - "  << std::endl;
      ds.unir(set_u, set_v);
    }
    else { 
      n_of_cycles++;
    }
  }

  return n_of_cycles;
}

