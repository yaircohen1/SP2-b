// Coheny405@gmail.com
// 206386708

#include "Algorithms.hpp"

namespace ariel{

    bool Algorithms::isConnected (const Graph &g) {
        const vector<vector<int>> &inputMatrix = g.getMatrix();
        size_t numVer= g.getNumV(); // Size of rows == num of ver
        vector<bool> checked (numVer,false); //  Keep track of whether each v in a graph has been checked or not.
        queue<size_t> Q;

        size_t startVer = 0; // start V for BFS traversal
        Q.push(startVer);
        checked[startVer] = true; // Mark the start V as checked
        
        // BFS loop
        while (!Q.empty()) {
            size_t currentVer = Q.front(); // the first on the queue
            Q.pop(); // Dequeue 
            
            // Visit all neighbors of the current vertex
            for (size_t neighbor = 0; neighbor<numVer; neighbor++){
                // Check if theres an edge between current V to its neighbors and check if its not already checked
                if(inputMatrix[currentVer][neighbor]!=0 && !checked[neighbor]) {
                    Q.push(neighbor);
                    checked[neighbor] = true;
                }
            }
        }
        // Check if all vertices are visited
        for (size_t i = 0; i < numVer; i++) {
            if (!checked[i]) {
                return false; // Graph is not connected
        }
        }
        return true; // Graph is connected
    }

    string Algorithms::shortestPath (const Graph &g, size_t start, size_t end) {
        // Check for invalid input
        if(g.getNumE()==0 || start >= g.getNumV() || end >= g.getNumV()){
            return "Invalid input";
        } 
        // Use BFS for unweighted graphs
        if(!g.getIsWeighted()) {
            return PathNoWeight::shortestPathBFS(g, start, end);
        } else {
            // Use Dijkstra's algorithm for weighted graphs without negative edges
            if(!g.getHasNegativeEdges()) {
                return PathWeight::shortestPathDijkstra(g,start,end);
                } else {
                    // Use Bellman-Ford algorithm for graphs with negative edges
                    bool flag = false;
                    return PathWeight::shortestPathBellmanFord(g,start,end,flag);
                }
            }
    }

    string Algorithms::isContainsCycle(const Graph &g) {
        return PathNoWeight::DFScycle(g);
    }

    string Algorithms::isBipartite(const Graph& g) {
        size_t numV = g.getNumV();
        const vector<vector<int>>& inputMatrix = g.getMatrix();
        vector<int> color(numV, -1); // -1: uncolored, 0: color 1, 1: color 2
        vector<int> groupA;
        vector<int> groupB;

        // Perform BFS from each vertex
        for (size_t start = 0; start < numV; ++start) {
            if (color[start] == -1) { // Not colored yet
                queue<int> Q;
                Q.push(start);
                color[start] = 0;
                groupA.push_back(start);

                while (!Q.empty()) {
                    int u = Q.front();
                    Q.pop();
                    
                    // Visit all neighbors of the current vertex
                    for (size_t v = 0; v < numV; ++v) {
                        if (inputMatrix[size_t(u)][v] != 0) { // There is an edge
                            if (color[v] == -1) { // If the vertex v is not colored
                                color[v] = 1 - color[size_t(u)]; // Assign alternate color to this adjacent v of u
                                 if (color[v] == 0) {
                                    groupA.push_back(static_cast<int>(v));
                                } else {
                                    groupB.push_back(static_cast<int>(v));
                                }
                                Q.push(v);
                            } else if (color[v] == color[size_t (u)]) { // If the vertex v has the same color as u
                                return "0"; // The graph is not bipartite.
                            }
                        }
                    }
                }
            }
        }

        string result = "Group A: {";
        for (size_t i = 0; i < groupA.size(); ++i) {
            result += to_string(groupA[i]);
            if (i != groupA.size() - 1) {
                result += ", ";
            }
        }
        result += "}\nGroup B: {";
        for (size_t i = 0; i < groupB.size(); ++i) {
            result += to_string(groupB[i]);
            if (i != groupB.size() - 1) {
                result += ", ";
            }
        }       
        result += "}";
        return result;
    }

    string Algorithms::negativeCycle(Graph& g) {
        bool flag = true;
        return PathWeight::shortestPathBellmanFord(g,0,g.getNumV()-1,flag);
    }    
}


