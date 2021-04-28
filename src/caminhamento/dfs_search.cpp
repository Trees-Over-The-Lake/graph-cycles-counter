// Modelo de pesquisa em grafo usando busca em largura ou profundidade

#include "../../Simple-Graph/graph.hpp"
#include <stdio.h>

class Solution {

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
    //for (int edge_index : graph[node]) {
     // dfs(edges[edge_index].to);
   // }

    pmark[node] = true;
    mark[node] = false;
  }

};