// Coheny405@gmail.com
// 206386708

#pragma once

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <cstddef> // for ssize_t
#include <limits>
#include <algorithm> // for reverse function


using namespace std;

namespace ariel {
    class PathWeight{
        public:
            static string shortestPathDijkstra(const Graph & g, size_t start, size_t end);
            static string shortestPathBellmanFord(const Graph & g, size_t start, size_t end, bool flag);
    };
}