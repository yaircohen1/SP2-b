// Coheny405@gmail.com
// 206386708

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include "PathNoWeight.hpp"
#include "PathWeight.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstddef> // for ssize_t

using namespace std;

namespace ariel {
    class Algorithms {
    public:
        // Function to check if the graph is connected using BFS
        static bool isConnected (const Graph &g);

        // Function to find the shortest path between two vertices in the graph
        static string shortestPath(const Graph &g,size_t start,size_t end);

        // Function to check if the graph contains a cycle using DFS
        static string isContainsCycle(const Graph &g);
        
        // Function to check if the graph is bipartite
        static string isBipartite(const Graph &g);

        // Function to check if the graph contains a negative cycle using the Bellman-Ford algorithm
        static string negativeCycle(Graph& g);
    };
}
    
#endif // ALGORITHMS_HPP
