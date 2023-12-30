#include <iostream>

#include "node.hpp"
#include "graph.hpp"
#include "algorithms.hpp"

int main(void){
    Graph g;

    for (int i = 1; i <= 8; i++){
        g.insert_node(i);
    }

    g.insert_edge(1, 2, 1);
    g.insert_edge(1, 6, 1);

    g.insert_edge(2, 3, 1);
    g.insert_edge(2, 8, 1);
    g.insert_edge(2, 8, 1);
    g.insert_edge(2, 7, 1);

    g.insert_edge(3, 4, 1);
    g.insert_edge(3, 8, 1);

    g.insert_edge(4, 5, 1);
    g.insert_edge(4, 8, 1);

    g.insert_edge(5, 1, 1);
    g.insert_edge(5, 8, 1);

    g.insert_edge(6, 3, 1);
    g.insert_edge(6, 7, 1);

    g.insert_edge(7, 4, 1);
    g.insert_edge(7, 8, 1);

    g.insert_edge(8, 5, 1);
    g.insert_edge(8, 6, 1);
    g.insert_edge(8, 8, 1);

    Algorithms::SSSP::bfs(g, 1);

    std::vector<Node*> path = Algorithms::Utilities::construct_path(g, 5);
    Algorithms::Utilities::print_path(path);
}