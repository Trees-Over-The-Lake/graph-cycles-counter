#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <bits/stdc++.h>

#include <iostream>
#include <vector>

// Criando uma estrutura de mapa para dois inteiros
typedef struct std::pair<int, int> parInteiros;

// Grafo
struct Grafo {
  int V, E;
  std::vector<std::pair<char, parInteiros>> arestas;

  Grafo(int V, int E) {
    this->V = V;
    this->E = E;
  }

  // Adicionar novas arestas
  void addAresta(char vertice, int aresta1, int aresta2) {
    this->arestas.push_back({vertice, {aresta1, aresta2}});
  }

  // Algoritmo de Kruskal
  void kruskal();
};

// Disjoint Sets para usar no algoritmo de kruskal
struct DisjointSets {
  int *pai, *profundidade;
  int tam;

  DisjointSets(int tam) {
    this->tam = tam;
    pai = new int[tam + 1];
    profundidade = new int[tam + 1];

    // No começo todos os vértices estão em sets diferentes e a profundidade 0
    for (int i = 0; i <= tam; i++) {
      profundidade[i] = 0;
      // Todo mundo é pai de si mesmo
      pai[i] = i;
    }
  }

  // Procurar pelo pai do nó 'tmp'
  int procurar(int tmp) {
    // Fazer tmp apontar para pai[tmp]
    if (tmp != pai[tmp]) tmp = procurar(pai[tmp]);
    return tmp;
  }

  // Unir os elementos por profundidades
  void unir(int x, int y) {
    x = procurar(x), y = procurar(y);

    // Montar uma árvore de menor profundidade que a árvore anterior
    if (profundidade[x] > profundidade[y])
      pai[y] = x;
    else
      pai[x] = y;

    if (profundidade[x] == profundidade[y]) profundidade[y]++;
  }
};

void Grafo::kruskal() {
  // Ordenando o grafo para facilitar o trabalho futuro
  std::sort(arestas.begin(), arestas.end());

  DisjointSets ds(this->V);

  // Iterar através de todos os nós do grafo
  std::vector<std::pair<char, parInteiros>>::iterator it;
  for (it = arestas.begin(); it != arestas.end(); it++) {
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.procurar(u);
    int set_v = ds.procurar(v);

    // Verificando se v e u são um ciclo, será se os dois estiveram dentro do
    // mesmo set
    if (set_u != set_v) {
      // Escrever aresta final
      std::cout << "Vértice: " << it->first << " \t| Arestas: " << u << " - "
                << v << std::endl;
      ds.unir(set_u, set_v);
    }
  }
}

#endif