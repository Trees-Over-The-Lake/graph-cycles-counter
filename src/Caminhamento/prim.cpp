#include <iostream>
#include <vector>

#include "../../Simple-Graph/graph.hpp"

Graph prim(Graph graph) {
  Graph aux = graph;
  aux.sort_graph();
  Graph result = new Graph();

  // Visited Vertex
  std::vector<Vertex> visitedVertex;

  for (auto i : aux.all_vertexes) {
    Edge *menor = i->edges.front();
    for (auto j : i->edges) {
      if (j->get_value() < menor->get_value()) {
        menor = j;
      }
    }

    Vertex *vert = new Vertex(i->get_vertex_value());
    Edge *insertEdge = new Edge(vert, i, menor->get_value(), false);
    vert->add_edge(menor);

    bool achou = false;
    for (auto j : visitedVertex) {
      if (j.get_vertex_value() == i->get_vertex_value()) achou = true;
    }

    if (!achou) {
      visitedVertex.push_back(*vert);
      result.insert_vertex(vert);
    }
  }

  return result;
}

int main() {
  Vertex *a = new Vertex(1);
  Vertex *b = new Vertex(4);
  Vertex *c = new Vertex(7);
  Vertex *d = new Vertex(2);

  Edge *UnionA_B = new Edge(a, b, 12, true);
  Edge *UnionA_C = new Edge(a, c, 47, false);

  Graph graph;
  graph.insert_vertex(a);
  graph.insert_vertex(b);
  graph.insert_vertex(c);
  graph.insert_vertex(d);

  graph.insert_edge(UnionA_B);
  graph.insert_edge(UnionA_C);

  graph.print_all_vertexes();
  graph.print_all_edges();
  graph.print_all_graph();

  std::cout << std::endl << "PRIM" << std::endl;

  Graph primGraph = prim(graph);

  primGraph.print_all_vertexes();
  primGraph.print_all_edges();
  primGraph.print_all_graph();

  return 0;
}