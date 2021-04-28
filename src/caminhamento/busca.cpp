// Modelo de pesquisa em grafo usando busca em largura ou profundidade

#include "../../Simple-Graph/graph.hpp"
#include <stdio.h>
#include <vector>

class Solution {
  std::vector<Edge> edges;
  // graph[vertex_id] -> vector of index of outgoing edges from @vertex_id.
  std::vector<std::vector<int>> graph;
  std::vector<bool> mark;
  std::vector<bool> pmark;
  int cycles;

  void dfs(int node) {
    if (pmark[node]) {
      return;
    }
    if (mark[node]) {
      cycles++;
      return;
    }
    mark[node] = true;

    // Try all outgoing edges.
    for (int edge_index : graph[node]) {
      dfs(edges[edge_index].to);
    }

    pmark[node] = true;
    mark[node] = false;
  }

  int CountCycles() {
    // Build graph.
    // ...

    cycles = 0;
    mark = std::vector<bool>(graph.size(), false);
    pmark = std::vector<bool>(graph.size(), false);
    for (int i = 0; i < (int) graph.size(); i++) {
      dfs(i);
    }

    return cycles;
  }
};