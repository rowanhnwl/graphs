#include <vector>

#ifndef NODE_HPP
#define NODE_HPP

class Node;

class Edge {
    public:
        Node* from;
        Node* to;
        int weight;

        Edge(Node* f, Node* t, int w){
            from = f;
            to = t;
            weight = w;
        }
};

class Node {
    private:
        int id;
        std::vector<Edge> incidentEdges; // Holds nodes and weights CHANGE
        
        // Members for searching
        char colour;
        Node* p; // Predecessor
        int dist; // Distance

    public:
        // Constructor
        Node(int);

        // Accessors
        int get_id();
        char get_colour();
        Node* get_p();
        int get_dist();
        std::vector<Edge>& get_edges(); // Access an adjacent node and the edge weight by index
        std::vector<Edge*> query_edges(int to_id); // Check if a specific edge exists (returns all instances)

        // Modifiers
        void change_colour(char new_colour);
        void change_p(Node* new_p);
        void change_dist(int new_dist);
        void insert_edge(Node* new_node, int w);
        bool delete_edge(int del_id); // Delete an edge based on its ID (returns the status)

        // Utilities
        void reset();
        void clear_edges();

        // Printing
        void print_adj_nodes();
};

#endif /* NODE_HPP */