#include <iostream>
#include <vector>

#include "node.hpp"

// Constructor
Node::Node(int _id){
    id = _id;
    incidentEdges = {};

    colour = 'w'; // Initialize to white
    p = nullptr;
    dist = INT_MAX; // Initialize to "infinity"
}

// Access an ID
int Node::get_id(){
    return id;
}

// Access the node's colour
char Node::get_colour(){
    return colour;
}

// Access the node's predecessor
Node* Node::get_p(){
    return p;
}

// Access the node's distance
int Node::get_dist(){
    return dist;
}

// Access the incident edges
std::vector<Edge>& Node::get_edges(){
    return incidentEdges;
}

// Check if a specific edge exists
int Node::query_edge(int adj_id){
    for (int edge_index = 0; edge_index < (int)incidentEdges.size(); edge_index++){
        if ((incidentEdges[(long long unsigned int)edge_index].to) -> id == adj_id){
            return edge_index;
        }
    }

    return -1;
}

// Change the ID
void Node::change_id(int new_id){
    id = new_id;
}

// Change the node's colour
void Node::change_colour(char new_colour){
    colour = new_colour;
}

// Change the node's predecessor
void Node::change_p(Node* new_p){
    p = new_p;
}

// Change the node's distance
void Node::change_dist(int new_dist){
    dist = new_dist;
}

// Insert a node into the adjacency list
void Node::insert_edge(Node* to_node, int w){
    Edge new_edge(this, to_node, w);
    incidentEdges.push_back(new_edge);
}

// Delete a node from the adjacency list
bool Node::delete_edge(int del_id){
    int edge_index = query_edge(del_id);

    if (edge_index == -1){
        return false;
    }

    // Delete all connections
    while (edge_index != -1){
        incidentEdges.erase(std::next(incidentEdges.begin(), edge_index));
        edge_index = query_edge(del_id);
    }

    return true;
}

// Change the weight of an edge
bool Node::change_edge_weight(int to_id, int w){
    int edge_index = query_edge(to_id);

    if (edge_index != -1){
        incidentEdges[(long long unsigned int)edge_index].weight = w;
        return true;
    }

    return false;
}

// Reset the properties of a node
void Node::reset(){
    colour = 'w';
    p = nullptr;
    dist = INT_MAX;
}

// Clear the edges in a node
void Node::clear_edges(){
    incidentEdges = {};
}

// Print the adjacent nodes
void Node::print_adj_nodes(){
    for (int edge_index = 0; edge_index < (int)incidentEdges.size(); edge_index++){
        std::cout << "(ID: " << (incidentEdges[(long long unsigned int)edge_index].to) -> id << ", W: " << incidentEdges[(long long unsigned int)edge_index].weight << ") ";
    }
    std::cout << std::endl;
}