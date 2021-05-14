#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <bits/stdc++.h>

#include <iostream>
#include <vector>

// Grafo
struct Grafo {
  int V, E;
  std::vector<std::pair<int, std::pair<int, int>>> arestas;

  Grafo(int V, int E) {
    this->V = V;
    this->E = E;
  }

  // Adicionar novas arestas
  void addAresta(int peso, int aresta1, int aresta2) {
    this->arestas.push_back({peso, {aresta1, aresta2}});
  }

  // Algoritmo de Kruskal
  void static kruskal(const Grafo& obj);
};

#endif