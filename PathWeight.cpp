// Coheny405@gmail.com
// 206386708

#include "PathWeight.hpp"
using namespace std;

namespace ariel{
    // Function to find the shortest path in a weighted graph using Dijkstra's algorithm
    string PathWeight::shortestPathDijkstra(const Graph& g, size_t start, size_t end){
        size_t numV = g.getNumV();
        const vector<vector<int>> &inputMatrix = g.getMatrix();
        vector<int> d(numV, numeric_limits<int>::max());
        vector<int> parent(numV, -1);

        d[start] = 0;
        // Priority queue to store vertices with their distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int start_int = static_cast<int>(start);
        pq.push({0,start_int}); // first pair is distance = 0, and ver = start_int
        // Dijkstra's algorithm loop
        while (!pq.empty()) {
            int dCurrentVer = pq.top().first;
            int currentVer = pq.top().second;
            pq.pop(); // Remove the vertex with the smallest distance
            for (size_t neighbor = 0; neighbor<numV; ++neighbor){
                // Check if theres an edge between current V to its neighbors and check if its not already checked
                if(inputMatrix[size_t(currentVer)][neighbor]!=0) {
                  int weight = inputMatrix[size_t(currentVer)][neighbor];
                  // Relaxation step
                    if (d[neighbor] > d[size_t(currentVer)] + weight) {
                        d[neighbor] = d[size_t(currentVer)] + weight;
                        parent[neighbor] = currentVer;
                        pq.push({d[neighbor], static_cast<int>(neighbor)}); // Update the priority queue with the new distance
                        }
                    }
                }
        }

        // Check if there's no path from the start vertex to the end vertex
        if (d[end] == numeric_limits<int>::max()) {
            return "-1"; // Return -1 if the end vertex is not reachable
        }
        // Construct the shortest path string
        string pathStr = to_string(end);
        size_t current = end;
        while (parent[current] != parent[start]) {
            pathStr = to_string(parent[current]) + "->" + pathStr;
            current = size_t(parent[current]);
        }
        return pathStr; // Return the constructed path string
    }   

    // Function to find the shortest path in a weighted graph with negative edges using the Bellman-Ford algorithm
    string PathWeight::shortestPathBellmanFord(const Graph& g, size_t start, size_t end, bool flag) {
        size_t numV = g.getNumV();
        const vector<vector<int>> &inputMatrix = g.getMatrix();
        vector<int> d(numV, numeric_limits<int>::max()); // stores the shortest distance from the start vertex to each vertex.
        vector<int> parent(numV, -1); // stores the parent of each vertex in the path.

        d[start] = 0;

        // Relax edges numV-1 times
        for (size_t relax = 1; relax < numV; ++relax) {
            for (size_t u = 0; u < numV; ++u) {
                for (size_t v = 0; v < numV; ++v) {
                    // Check if there's an edge from u to v and if d[u] isn't max to add weight
                    if (inputMatrix[u][v] != 0 && d[u] != numeric_limits<int>::max()) {
                        int weight = inputMatrix[u][v];
                        if (d[u] + weight < d[v]) {
                            d[v] = d[u] + weight;
                            parent[v] = static_cast<int>(u);
                        }
                    }
                }
            }
        }

        // Check for negative-weight cycles (one more round of relaxtion)
        bool negativeCycleFound = false;
        int cycleStart = static_cast<int>(numV);
        for (size_t u = 0; u < numV; ++u) {
            for (size_t v = 0; v < numV; ++v) {
                // Check if there's an edge from u to v and if d[u] isn't max to add weight
                if (inputMatrix[u][v] != 0 && d[u] != numeric_limits<int>::max()) { 
                    int weight = inputMatrix[u][v];
                    if (d[u] + weight < d[v]) {
                        cycleStart = u;
                        negativeCycleFound = true;
                        break;
                    }   
                }
            }
            if (negativeCycleFound) break;
        }
        if (negativeCycleFound) {
            // if flag is true the function got a call from negativeCycle(g)
            if(flag){
                vector<int> cycle; // A vector to store the vertices in the negative cycle.
                vector<bool> visited(numV, false);
                int currentVer = cycleStart; //  the vertex where the negative cycle was detected.
                // The loop continues until it revisits a vertex, indicating the start of a cycle
                while (!visited[size_t(currentVer)]) { 
                    visited[size_t(currentVer)] = true;
                    currentVer = parent[size_t(currentVer)];
                }

                int cycleEnd = currentVer; // marking the vertex where the cycle was detected.
                // The cycle is constructed by tracing back from cycleEnd to itself.
                cycle.push_back(cycleEnd);
                currentVer = parent[size_t(cycleEnd)];
                while (currentVer != cycleEnd) {
                    cycle.push_back(currentVer);
                    currentVer = parent[size_t(currentVer)];
                }
                cycle.push_back(cycleEnd);
                 
                // The cycle vector is reversed to present the cycle in the correct order.
                reverse(cycle.begin(), cycle.end());
                string cycleStr;
                for (size_t i = 0; i < cycle.size(); ++i) {
                    if (i > 0) cycleStr += "->";
                    cycleStr += to_string(cycle[i]);
                }
                return "Negative Cycle: " + cycleStr;
            } else {
                return "error: negative cycle";
            }
        }

        if (!negativeCycleFound && flag) {
            return "No negative cycle found";
        }

        if (d[end] == numeric_limits<int>::max()) {
            return "-1";
        }

        // Construct the shortest path string
        string pathStr;
        int current = size_t(end);
        while (current != -1) {
            pathStr = to_string(current) + (pathStr.empty() ? "" : "->" + pathStr);
            current = parent[size_t(current)];
        }
        if (d[end]<0) return "Negative path: "+ pathStr; // Return negative path if the distance is negative
    
        return pathStr;   
    }
}