#include <iostream>

#include "graph.hpp"
#include "node.hpp"

// Constructor
Graph::Graph(){
    nodes = {};
}

// Get the index of a node by its ID
int Graph::get_node_index(int id){
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        if (nodes[(long long unsigned int)node_index].get_id() == id){
            return node_index;
        }
    }

    return -1;
}

// Check if a graph edge exists. If so, return all instances of it
std::vector<Edge*> Graph::query_edges(int from_id, int to_id){
    int from_index = get_node_index(from_id);
    int to_index = get_node_index(to_id);

    // If either ID does not exist in the graph
    if (from_index == -1 || to_index == -1){
        return {};
    }
    
    return nodes[(long long unsigned int)from_index].query_edges(to_id);
}

// Get the number of nodes in the graph
int Graph::get_n_nodes(){
    return (int)nodes.size();
}

// Get the number of edges in the graph
int Graph::get_n_edges(){
    int n_edges = 0;

    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        n_edges += (int)(nodes[(long long unsigned int)node_index].get_edges().size());    
    }

    return n_edges;
}

// Get a pointer to a node by index
Node* Graph::get_node(int id){
    int node_index = get_node_index(id);

    if (node_index == -1){
        std::cout << "Error: No node exists with ID " << id << std::endl;
        return nullptr;
    }

    return &nodes[(long long unsigned int)node_index];
}

// Insert an edge into the graph
bool Graph::insert_edge(int from_id, int to_id, int w){
    int to_index = get_node_index(to_id);
    int from_index = get_node_index(from_id);

    if (from_index == -1){
        std::cout << "Error: No node exists with ID " << from_id << std::endl;
        return false;
    }
    else if (to_index == -1) {
        std::cout << "Error: No node exists with ID " << to_id << std::endl;
        return false;
    }
    
    Node* p_to_node = &nodes[(long long unsigned int)to_index];

    nodes[(long long unsigned int)from_index].insert_edge(p_to_node, w);
    return true;
}

// Delete an edge from the graph
bool Graph::delete_edge(int from_id, int to_id){
    int to_index = get_node_index(to_id);
    int from_index = get_node_index(from_id);
    
    if (from_index == -1){
        std::cout << "Error: No node exists with ID " << from_id << std::endl;
        return false;
    }
    else if (to_index == -1) {
        std::cout << "Error: No node exists with ID " << to_id << std::endl;
        return false;
    }

    return nodes[(long long unsigned int)from_index].delete_edge(to_id);
}

// Insert a node into the graph
bool Graph::insert_node(int id){
    // If a matching ID exists in the graph
    if (get_node_index(id) != -1){
        std::cout << "Error: A node already exists with ID " << id << std::endl;
        return false;
    }

    Node new_node(id);
    nodes.push_back(new_node);
    return true;
}

// Delete a node from the graph
bool Graph::delete_node(int del_id){
    int del_index = get_node_index(del_id);
    if (del_index == -1){
        std::cout << "Error: No node exists with ID " << del_id << std::endl;
        return false;
    }
    
    // Delete the connections
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        while (nodes[(long long unsigned int)node_index].delete_edge(del_id));
    }

    // Delete the node
    nodes.erase(std::next(nodes.begin(), del_index));
    return true;
}

// Operator overload for access by index
Node* Graph::operator[](int index){
    return &nodes[(long long unsigned int)index];
}

// Reset the nodes in the graph
void Graph::reset(){
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        nodes[(long long unsigned int)node_index].reset();
    }
}

// Clear the edges in the graph (keep the nodes)
void Graph::clear_edges(){
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        nodes[(long long unsigned int)node_index].reset();
        nodes[(long long unsigned int)node_index].clear_edges();
    }
}

// Clear the graph
void Graph::clear_nodes(){
    nodes = {};
}

// Print the graph
void Graph::print_graph(){
    std::cout << std::endl;
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        std::cout << "ID: " << nodes[(long long unsigned int)node_index].get_id() << " -> ";
        nodes[(long long unsigned int)node_index].print_adj_nodes();
    }
    std::cout << std::endl;
}