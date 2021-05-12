#include "prim.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

enum COLORS { WHITE, BLACK };

struct EdgeColored {
 public:
  EdgeColored() {
    this->e = nullptr;
    this->color = WHITE;
  }
  Edge *e;
  COLORS color;
};

Graph prim(Graph graph) {
  Graph aux = graph;
  aux.sort_graph();
  Graph result = aux;

  result.all_edges.clear();

  std::vector<EdgeColored> coloredEdge;
  for (auto i : aux.all_edges) {
    EdgeColored tmp;
    tmp.e = i;
    coloredEdge.push_back(tmp);
  }

  for (auto i : aux.all_vertexes) {
    EdgeColored coloredEdgeFind;
    coloredEdgeFind.color = BLACK;
    coloredEdgeFind.e = i->edges.front();

    coloredEdge.push_back(coloredEdgeFind);

    if (std::find(coloredEdge.begin(), coloredEdge.end(), coloredEdgeFind) !=
        coloredEdge.end()) {
      continue;
    }

    result.all_edges.push_back(i);
  }

  return result;
}

int main() {}