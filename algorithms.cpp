#include <iostream>
#include <vector>
#include <queue>

#include "algorithms.hpp"
#include "graph.hpp"
#include "node.hpp"

/*
    ----------------------------------
             SSSP ALGORITHMS      
    ----------------------------------
*/

// Breadth-first-search
void Algorithms::SSSP::bfs(Graph& g, int s_id){
    // Get a pointer to the source node
    Node* s_p = g.get_node(s_id);

    // Validate the IDs
    if (s_p == nullptr){
        return;
    }

    // Initialize the source's members
    s_p -> change_colour('g');
    
    // Create the FIFO queue
    std::queue<Node*> bfs_queue;

    // Add the source to the queue
    bfs_queue.push(s_p);

    // While the queue is not empty
    while (!bfs_queue.empty()){
        // Remove the top of the queue
        Node* u_p = bfs_queue.front();
        bfs_queue.pop();

        std::vector<Edge>& u_edges = u_p -> get_edges();

        // Iterate through the nodes adjacent to u_p
        for (int edge_index = 0; edge_index < (int)u_edges.size(); edge_index++){
            Node* v_p = u_edges[(size_t)edge_index].to;

            // Change the attributes of the unvisited adjacent nodes
            if (v_p -> get_colour() == 'w'){
                v_p -> change_colour('g');
                v_p -> change_p(u_p);
                bfs_queue.push(v_p);
            }
        }

        // Mark the node as visited
        u_p -> change_colour('b');
    }
}

// Dijkstra's Algorithm
void dijkstra(Graph& g, int s_id){
    // Priority queue initialization
    std::priority_queue<Node*, std::vector<Node*>, Algorithms::Comparators::dist_comp> pq;

    // Get a pointer to the source node
    Node* s_p = g.get_node(s_id);

    // Validate the IDs
    if (s_p == nullptr){
        return;
    }

    // Initialize the source node and the queue
    s_p -> change_dist(0);
    s_p -> change_colour('g');
    pq.push(s_p);

    while (!pq.empty()){
        // Access and remove the node with the highest priority
        Node* u_p = pq.top();
        pq.pop();

        std::vector<Edge>& u_edges = u_p -> get_edges();

        for (int edge_index = 0; edge_index < (int)u_edges.size(); edge_index++){
            Node* v_p = u_edges[(size_t)edge_index].to;

            // Change the attributes for the unvisited node
            if (v_p -> get_colour() == 'w'){
                
            }
        }
    }
}

/*
    ----------------------------------
            UTILITY ALGORITHMS      
    ----------------------------------
*/

// Path relaxation
bool Algorithms::Utilities::relax(Edge* e){
    Node* u = e -> from;
    Node* v = e -> to;
    int w_uv = e -> weight;
    
    if (v -> get_dist() > u -> get_dist() + w_uv){
        // Update the distance and predecessor of node v
        v -> change_dist(u -> get_dist() + w_uv);
        v -> change_p(u);
        return true;
    }
    
    return false;
}

// Reconstruct the path from the destination ID
std::vector<Node*> Algorithms::Utilities::construct_path(Graph& g, int dest_id){
    std::vector<Node*> path_rev;
    std::vector<Node*> path;

    // Get a pointer to the destiation node and add it to the reversed path
    Node* d_p = g.get_node(dest_id);
    path_rev.push_back(d_p);

    // Iterate backwards through the predecessors until the source is found
    Node* curr = d_p -> get_p();
    while (curr != nullptr){
        path_rev.push_back(curr);
        curr = curr -> get_p();
    }

    // Reverse the path
    for (int node_index = (int)path_rev.size() - 1; node_index >= 0; node_index--){
        path.push_back(path_rev[(size_t)node_index]);
    }

    return path;
}

// Print a path
void Algorithms::Utilities::print_path(std::vector<Node*> path){
    std::cout << std::endl;
    for (int node_index = 0; node_index < (int)path.size(); node_index++){
        std::cout << path[(size_t)node_index] -> get_id();
        
        if (node_index < (int)path.size() - 1){
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}