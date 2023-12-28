#include <iostream>

#include "node.hpp"
//#include "graph.hpp"
//#include "algorithms.hpp"

int main(void){
    Node n1(5);
    Node n2(3);
    Node n3(7);
    Node n4(14);

    n1.insert_edge(&n2, 3);
    n2.insert_edge(&n3, 2);
    n1.insert_edge(&n3, 6);
    n4.insert_edge(&n1, 2);

    if (n1.change_edge_weight(3, 8)) {
        int weight = n1.get_edges()[0].weight;
        printf("%d", weight);
    }
}