// Coheny405@gmail.com
// 206386708

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <cstddef> // for ssize_t
using namespace std;


namespace ariel {

    class Graph {
        private:
            vector<vector<int>> Matrix; // a dynamic array that can grow and shrink in size at runtime.
            size_t numV; // The number of vertices in the graph
            size_t numE; // The number of edges in the graph
            bool isDirected; // Boolean variable whether the graph is directed or not
            bool isWeighted; // Boolean variable whether the graph is weighted or not
            bool isNegative; // Boolean variable if the graph contains negative edges or not
    
        public: 
            Graph(); // Default Constructor
            void loadGraph(const vector<vector<int>> &matrix);
            void printGraph() const;
            const vector<vector<int>>& getMatrix() const;
            size_t getNumV() const;
            size_t getNumE() const;
            bool getIsDirected() const;
            bool getIsWeighted() const;
            bool getHasNegativeEdges() const;
            ~Graph(); //destructor

            //EX2
            friend ostream& operator<<(ostream& stream, const Graph& g); // Provides direct access to the private members of the Graph class
            bool checkSameSize(const Graph& first, const Graph& second) const; 
            Graph operator+(const Graph& other) const;
            Graph operator+=(const Graph& other);
            Graph operator+() const;
            Graph& operator++();
            Graph operator++(int);
            Graph operator-(const Graph& other) const;
            Graph operator-=(const Graph& other);
            Graph operator-() const;
            Graph& operator--();
            Graph operator--(int);
            Graph operator*(int scalar) const;
            Graph operator*(const Graph& other) const;
            bool isContained(const Graph& other) const;
            bool operator==(const Graph& other) const;
            bool operator!=(const Graph& other) const;
            bool operator<(const Graph& other) const;
            bool operator<=(const Graph& other) const;
            bool operator>(const Graph& other) const;
            bool operator>=(const Graph& other) const;







    };
}

#endif // GRAPH_HPP
