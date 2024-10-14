#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include<vector>
#include<set>
using namespace std;

class SparseGraph{
public:
    // Constructor Method (Using Initializer List)
    // Create 3 nodes with no edges
    SparseGraph() : nodes(3), edges(3) { }
    // Create n nodes with no edges
    SparseGraph(int n_in) : nodes(n_in), edges(n_in) { }

    // Copy Constructor
    SparseGraph(const SparseGraph& G) {
        this->nodes = G.nodes;
        this->edges = G.edges;
    }

    // Add Edge from a to b
    // Given edges from a to b is edges[a] = {b};
    void AddEdge(int a, int b) {
        edges[a].insert(b);
    }

    // Remove Edge from a to b
    void RemoveEdge(int a, int b) {
        edges[a].erase(b);
    }

    // Check if edges from a to b exists
    // If edges[a] doesn't have b, that means the edges doesn't exist
    bool DoesEdgeExist(int a, int b) const {
        return edges[a].find(b) != edges[a].end();
    }

    // Transpose a graph
    // Change all edges from (a,b) to (b,a)
    SparseGraph Transpose() const {
        // Create a graph with same nodes
        SparseGraph G(this->nodes);
        // Add edges (b,a)
        for(int a = 0; a < nodes; a++)
        {
            for(const auto &b : edges[a]) { G.AddEdge(b,a); }
        }
        return G;
    }

protected:
    // Class Properties
    int nodes;
    vector<set<int>> edges;
};
#endif // __SPARSE_GRAPH_H__