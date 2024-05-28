// Coheny405@gmail.com
// 206386708

#include "PathNoWeight.hpp"
using namespace std;

// Color constants for marking the state of each vertex during traversal
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

namespace ariel{
    // Function to find the shortest path in an unweighted graph using BFS
    string PathNoWeight::shortestPathBFS(const Graph& g, size_t start, size_t end){
        size_t numV = g.getNumV();
        const vector<vector<int>> &inputMatrix = g.getMatrix();
        vector<int> color (numV, WHITE); // Initialize all vertices as unvisited (WHITE)
        vector<int> d(numV, numeric_limits<int>::max()); // Distance from start to each vertex
        vector<int> parent(numV, -1); // Parent of each vertex in the BFS tree

        // Initializes the first vertex
        color[start] = GRAY; // Mark start vertex as visiting (GRAY)
        d[start] = 0; // Distance to start vertex is 0

        queue<int> Q;
        Q.push(static_cast<int>(start)); // Enqueue start vertex
        while (!Q.empty()){
            int currentVer = Q.front(); // the first on the queue
            Q.pop(); // dequeue 
            // Visit all neighbors of the current vertex
            for (size_t neighbor = 0; neighbor<numV; ++neighbor){
                // Check if theres an edge between current V to its neighbors and check if its not already checked
                if(inputMatrix[size_t(currentVer)][neighbor]!=0) {
                    if (color[neighbor] == WHITE){
                        color[neighbor] = GRAY;
                        d[neighbor] = d[size_t(currentVer)]+1;
                        parent[neighbor] = currentVer;
                        Q.push(static_cast<int>(neighbor));
                    }
                }
            }
            color[size_t(currentVer)] = BLACK; // Mark current vertex as fully processed (BLACK)  
        }
        // Check if the end vertex is reachable from the start vertex
        if (color[end] == WHITE) {
            return "-1"; // Return -1 if the end vertex is not reachable
        }
       // Construct the shortest path string
        string pathStr;
        size_t current = end;
        while (current != start) {
            pathStr = "->" + to_string(current) + pathStr;
            current = size_t(parent[current]);
        }
        pathStr = to_string(start) + pathStr;
        return pathStr;
    }

    // Helper function for DFS to find cycles
    string PathNoWeight::DFSvisit(const Graph& g, size_t v, vector<int> &color,vector<int> &parent)  {
        const vector<vector<int>> &inputMatrix = g.getMatrix(); 
        color[v] = GRAY;  // Mark the current vertex as visited

        // Visit all neighbors of the current vertex
        for (size_t neighbor = 0; neighbor < g.getNumV(); ++neighbor) {
            if (inputMatrix[v][neighbor] != 0) { // Ensure edge from v to neighbor
                if (color[neighbor] == GRAY) {  // Back edge found, indicating a cycle
                    if (!(g.getIsDirected()) && parent[v] == static_cast<int>(neighbor)) {
                        continue; // Skip the backtracking edge in undirected graph
                    }
                    // Cycle found, construct the cycle path
                    string cycle = to_string(neighbor);
                    size_t current = v;
                    while (current != neighbor) {
                        cycle = to_string(current) + "->" + cycle;
                        current = size_t(parent[current]);
                    }
                    cycle = to_string(neighbor) + "->" +cycle;
                    return cycle;

                } else if (color[neighbor] == WHITE) { // Neighbor hasn't been visited yet
                    parent[neighbor] = v; // Update parent vertex
                    string cycle = DFSvisit(g,neighbor,color, parent); // Recursive function
                    
                    if (!cycle.empty()) {
                        return cycle;
                    }
                }
            }
        }
        color[v] = BLACK; // V is done
        return ""; // Return empty string if no cycle is found
    }

    // Function to detect cycles in the graph using DFS
    string PathNoWeight::DFScycle(const Graph& g){
        size_t numV = g.getNumV();
        if (numV == 0) {
            throw invalid_argument("Graph is empty.");
        }
        vector<int> color (numV, WHITE);
        vector<int> parent(numV, -1);

        // Perform DFS from each vertex
        for (size_t i = 0; i < numV; ++i) {
            if (color[i] == WHITE) {
                string cycle = DFSvisit(g,i,color, parent);
                 if (!cycle.empty()){
                    return "The cycle is: " +cycle;
                }
            }
        }
        return "0"; // No cycle 
    }
}
        
