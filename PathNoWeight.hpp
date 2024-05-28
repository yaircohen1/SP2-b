// Coheny405@gmail.com
// 206386708

#pragma once

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <cstddef> // for ssize_t
#include <limits>


using namespace std;

namespace ariel {
    class PathNoWeight{
        private:
            static string DFSvisit(const Graph& g, size_t v, vector<int> &color,vector<int> &parent);

        public:
            static string shortestPathBFS (const Graph& g, size_t start, size_t end);
            static string DFScycle(const Graph& g);  
    }; 
} 
