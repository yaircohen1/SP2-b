// Coheny405@gmail.com
// 206386708

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph operator + graph")
{
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 4},
        {1, 5, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 2, 1},
        {2, 0, 5},
        {1, 6, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3 == expectedGraph);
}

TEST_CASE("Test graph operator - graph"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    ariel::Graph g3 = g1 - g2;
    CHECK(expectedGraph == g3);
}

TEST_CASE("Test graph operator += graph"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 4, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 5, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    g1 += g2;
    CHECK(expectedGraph == g1);

}

TEST_CASE("Test print graph to ostream with operator"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    std::cout<<"Test print graph to ostream with operator"<<std::endl;
    CHECK_NOTHROW(cout<<++g1<<endl); //add 1 to all edges
    CHECK_NOTHROW(cout<<g1--<<endl); //sub 1 from all edges but wont be seein in the next print
    CHECK_NOTHROW(cout<<g1<<endl); //now the edges are back to the original
}

TEST_CASE("Test graph operator * ")
{
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK_THROWS(g1 * g2);
}

TEST_CASE("Test graph operator * scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel:: Graph g2 = g1*5;
    vector<vector<int>> expectedGraph = {
        {0, 5, 0},
        {5, 0, 5},
        {0, 5, 0}};
    ariel::Graph expected;
    expected.loadGraph(expectedGraph);
    CHECK(g2==expected);
}
TEST_CASE("Test graph operator >"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g2>g1);
}

TEST_CASE("Test graph operator <="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1<=g2);
}

TEST_CASE("Test graph operator <"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {2, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1<g2);
}

TEST_CASE("Test graph operator ++ postfix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1++ != g2);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph operator --prefix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(g1 == --g2);


}

TEST_CASE("Test graph operator postfix--"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2--);
    CHECK(g1 == g2);
}

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    // Test #1
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    --g;
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test #2
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 5, 1, 0, 0},
        {1, 0, 7, 0, 0},
        {1, 5, 0, -4, 0},
        {0, 0, 10, 0, 0},
        {-9, 0, 0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g2) == false);
    CHECK_THROWS(g1 *g2);
    

    // Test #3
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 5, 8, 0},
        {1, 0, 1, 0},
        {3, -3, 0, 0},
        {0, 0, 0, 0}};
    g3.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g3) == false);
    ariel::Graph g3535 = g3*5;
    CHECK(ariel::Algorithms::isConnected(g3535) == false);
} 

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    // Test #6
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");
    ariel::Graph g5 = g*5;
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");

    // Test #7
    ariel::Graph g21;
    vector<vector<int>> graph21 = {
        {0, 5, 1, 0, 0},
        {15, 0, 1, 0, 0},
        {1, 18, 0, 5, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 0, 0, 0}};
    g21.loadGraph(graph21);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g2, 0, 4) == "-1");

    ariel::Graph g212 = g21-g2;
    CHECK(ariel::Algorithms::shortestPath(g212, 0, 4) == "-1");


    // Test #8 #9 #10 #11 #12
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 5, 0, 0},
        {0, 0, 1, 0},
        {-3, 0, 0, 0},
        {0, 0, -2, 0}};
    g3.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g3, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g3, 2, 1) == "2->0->1");
    CHECK(ariel::Algorithms::shortestPath(g3, 2, 0) == "Negative path: 2->0");
    CHECK(ariel::Algorithms::shortestPath(g3, 1, 3) == "-1");

    ariel::Graph g33;
    vector<vector<int>> graph33 = {
        {0, 5, 0, 0},
        {0, 0, 1, 0},
        {6, 0, 0, 0},
        {0, 0, 4, 0}};
    g33.loadGraph(graph33);
    ariel::Graph g333 = g33 +g3;
    CHECK(ariel::Algorithms::shortestPath(g333, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g333, 2, 1) == "2->0->1");
    CHECK(ariel::Algorithms::shortestPath(g333, 2, 0) == "2->0"); // not negative path anymore
    CHECK(ariel::Algorithms::shortestPath(g333, 1, 3) == "-1");
    

    // Test #13 #14
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, -5, 0, 0},
        {0, 0, 0, 0},
        {-3, 0, 0, -8},
        {-6, 0, 0, 0}};
    g4.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g4, 1, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g4, 3, 1) == "Negative path: 3->0->1");
    
    ariel::Graph g44 = -g4;
    CHECK(ariel::Algorithms::shortestPath(g44, 1, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g44, 3, 1) == "3->0->1"); // no nagtive path anymore
    
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    ariel::Graph g0;
    vector<vector<int>> graph0 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g0.loadGraph(graph0);
    ariel::Graph g01 = g0+g;
    CHECK(ariel::Algorithms::isContainsCycle(g01) == "The cycle is: 0->1->2->0");
   
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g2) == "The cycle is: 0->1->2->0");
    
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0, 1, 1, 0},
        {10, 0, 10, 0, 0},
        {1, 10, 0, 5, 2},
        {1, 12, 1, 0, 0},
        {0, 0, 2, 0, 0}};
    g3.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g3)=="The cycle is: 0->2->0");
    CHECK_THROWS(g2 * g3);

    // Test #20
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, -4, 0, 0},
        {0, 0, 1, 1},
        {-3, 0, 0, -8},
        {-6, 0, 0, 0}};
    g4.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g4) == "The cycle is: 0->1->2->0");
    g4++;
    g4++;
    g4++;
    g4++;
    CHECK(ariel::Algorithms::isContainsCycle(g4) == "0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "Group A: {0, 2}\nGroup B: {1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
    
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}};    
    g2.loadGraph(graph2);
    CHECK_THROWS(g1+=g2);
}

TEST_CASE("Test negative cycle in the graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle found");
    g=g*(-1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative Cycle: 3->2->3");

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 5, 8, 0},
        {1, 0, 1, 0},
        {3, -3, 0, 0},
        {0, 0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g2) == "Negative Cycle: 1->2->1");
    g2=-g2;
    CHECK(ariel::Algorithms::negativeCycle(g2) == "Negative Cycle: 0->2->0");
    
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, -2, 0, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, -5}, 
        {-2, 0, 0, 0}} ;

    g3.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g3) == "Negative Cycle: 0->1->2->3->0");
}