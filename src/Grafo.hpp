#ifndef GRAFO_HPP
#define GRAFO_HPP
//#include <bits/stdc++.h>

#include <iostream>
#include <vector>

// Grafo
struct Grafo
{
  int V, E;

  std::vector<std::pair<int, std::pair<int, int>>> arestas;

  Grafo(int V, int E)
  {
    this->V = V;
    this->E = E;
  }


  // Adicionar novas arestas
  void addAresta(int peso, int aresta1, int aresta2)
  {
    this->arestas.push_back({peso, {aresta1, aresta2}});
  }

  // Adicionar novas arestas sem pesos
  void addArestaSemPeso(int aresta1, int aresta2)
  {
    addAresta(0, aresta1, aresta2);
  }

  void addEdges(int aresta1, int aresta2, int peso)
  {
    addAresta(peso, aresta1, aresta2);
  }

  int num_vertex();

  int num_edge();

  std::vector<std::pair<int, std::pair<int, int>>> get_arestas();

  std::vector<int> get_vertex_adj(int vertex);
};

// Disjoint Sets para usar no algoritmo de kruskal
struct DisjointSets
{
  int *pai, *profundidade;
  int tam;

  DisjointSets(int tam)
  {
    this->tam = tam;
    pai = new int[tam + 1];
    profundidade = new int[tam + 1];

    // No começo todos os vértices estão em sets diferentes e a profundidade 0
    for (int i = 0; i <= tam; i++)
    {
      profundidade[i] = 0;
      // Todo mundo é pai de si mesmo
      pai[i] = i;
    }
  }

  // Procurar pelo pai do nó 'tmp'
  int procurar(int tmp)
  {
    // Fazer tmp apontar para pai[tmp]
    if (tmp != pai[tmp])
      tmp = procurar(pai[tmp]);
    return tmp;
  }

  // Unir os elementos por profundidades
  void unir(int x, int y)
  {
    x = procurar(x), y = procurar(y);

    // Montar uma árvore de menor profundidade que a árvore anterior
    if (profundidade[x] > profundidade[y])
      pai[y] = x;
    else
      pai[x] = y;

    if (profundidade[x] == profundidade[y])
      profundidade[y]++;
  }
};

std::vector<std::pair<int, std::pair<int, int>>> Grafo::get_arestas()
{
  return this->arestas;
}

int Grafo::num_vertex()
{
  return this->V;
}

int Grafo::num_edge()
{
  return this->E;
}


std::vector<int> Grafo::get_vertex_adj(int vertex)
{
  std::vector<int> result;

  for (auto i = arestas.begin(); i != arestas.end(); i++)
  {
    if (i->second.first == vertex)
    {
      result.push_back(i->second.second);
    }
    else if (i->second.second == vertex)
    {
      result.push_back(i->second.first);
    }
  }

  return result;
}
#endif