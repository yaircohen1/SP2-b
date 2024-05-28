// Coheny405@gmail.com
// 206386708


#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1); // Load the graph to the object.

    ariel::Graph g2;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 5, 9},
        {6, 5, 1},
        {0, 1, 1}};
    g2.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g3;
    // 4x4 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 8, 0},
        {5, 4, 1},
        {0, 6, 0} 
        };
    g3.loadGraph(graph3); // Load the graph to the object.

    // Create an instance of Graph to call checkSameSize
    ariel::Graph checker;
    cout << checker.checkSameSize(g1, g2) << endl;
    cout << checker.checkSameSize(g1, g3) << endl;
    ariel::Graph g4 = g1 + g2;
    cout << "Graph 4:" << endl;
    g4.printGraph();
    ariel::Graph g5 = g4 - g2;
    cout << "Graph 5:" << endl;
    g5.printGraph(); 
    g4+=g1;
    cout << "Graph 4:" << endl;
    g4.printGraph(); 
    g4-=g1;
    cout << "Graph 4:" << endl;
    g4.printGraph();
    ariel::Graph g6=-g4; 
    cout << "Graph 6: ( - unary)" << endl;
    g6.printGraph();
    g6++;
    cout << "Graph 6: (++)" << endl;
    g6.printGraph();
    g6--;
    cout << "Graph 6: (--)" << endl;
    g6.printGraph();
    ariel::Graph g7=g1*g3; 
    cout << "Graph 7: (g1*g3)" << endl;
    cout << g7 << endl;

    ariel::Graph g8;
    vector<vector<int>> graph8 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g8.loadGraph(graph8);

    ariel::Graph g9;
    vector<vector<int>> graph9 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    g9.loadGraph(graph9);

    cout << "Graph 8:" << endl;
    cout << g8 << endl;

    cout << "Graph 9:" << endl;
    cout << g9 << endl;

    ariel::Graph g10;
    std::vector<std::vector<int>> graph10 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g10.loadGraph(graph10);

    ariel::Graph g12;
    std::vector<std::vector<int>> graph12 = {
        {1, 2},
        {4, 5}
    };
    g12.loadGraph(graph12);

    std::cout << "Graph 10:\n" << g10 << std::endl;
    std::cout << "Graph 12:\n" << g12 << std::endl;

    std::cout << "Graph 10 is greater than Graph 12: " << (g10 > g12) << std::endl;
    std::cout << "Graph 10 is greater than or equal to Graph 12: " << (g10 >= g12) << std::endl;
    std::cout << "Graph 10 is less than Graph 12: " << (g10 < g12) << std::endl;
    std::cout << "Graph 10 is less than or equal to Graph 12: " << (g10 <= g12) << std::endl;

    return 0;
}



