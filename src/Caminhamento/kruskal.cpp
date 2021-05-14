#include "../Grafo.hpp"

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
  std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
  for (it = arestas.begin(); it != arestas.end(); it++) {
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.procurar(u);
    int set_v = ds.procurar(v);

    // Verificando se v e u são um ciclo, será se os dois estiveram dentro do
    // mesmo set
    if (set_u != set_v) {
      // Escrever aresta final
      std::cout << "Pesos: " << it->first << " \t| Arestas: " << u << " - " << v
                << std::endl;
      ds.unir(set_u, set_v);
    }
  }
}

// Driver program to test above functions
int main() {
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