// Coheny405@gmail.com
// 206386708

#include "Graph.hpp"
using namespace std;

namespace ariel {
    // Constructor for the Graph class
    Graph::Graph(): Matrix(), numV(0), numE(0), isDirected(false), isWeighted(false), isNegative(false) {}

    // Function to load a graph from an input matrix
    void Graph::loadGraph(const vector<vector<int>> &inputMatrix) {
        //Check if inputMatrix is valid
        // Check if the num of rows (mat.size) == num of columns (mat[0].size)
        if (inputMatrix.size() != inputMatrix[0].size()) {
            throw invalid_argument ("Invalid graph: The graph is not a square matrix.");
        }
        // Check if inputMatrix is empty (it has zero rows)
        if(inputMatrix.empty()){
            throw invalid_argument ("Invalid graph:: the matrix is empty");
        }
        // Check if there are no diagonal elements
        for(size_t i = 0; i < inputMatrix.size(); i++) {
            if (inputMatrix[i][i] != 0) {
                throw invalid_argument("Invalid graph: The matrix has non-zero diagonal elements.");
            }
        }
        // Load the matrix and set the number of vertices
        this->Matrix = inputMatrix;
        this->numV = inputMatrix.size();
        // Count the edges
        this->numE = 0; // Resets to default
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]!=0){
                    this->numE++;
                }
            }
        }
        // Check if the Graph is directed (if matrix is symmetric: yes - undirected, otherwise - directed)
        this->isDirected = false; // Resets to default 
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]!=Matrix[j][i]){
                    this->isDirected = true;
                    break;
                }
            }
        }
        // If the Graph is undirected (symmetric), the num of edges is numE/2
        if (!(isDirected)){
            this->numE = this->numE/2;
        }
        // Check if the Graph is weighted (if matrix has values other than 1 or 0 in the cells: yes - weighted, otherwise - weighted)
        this->isWeighted = false; // Resets to default 
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]!=1 && Matrix[i][j]!=0){
                    this->isWeighted = true;
                    break;
                }
            }
        }
        // Check if the Graph has negative weighted edges (if matrix has values less than 0: yes - negative , otherwise - un-negative)
        this->isNegative = false; // Resets to default 
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]<0){
                    this->isNegative = true;
                    break;
                }
            }
        }
    }

    // Function to print information about the graph
    void Graph::printGraph() const {
        cout << "Graph Info:" << endl;
        cout << "Directed: " <<  (this->isDirected ? "true" : "false") << endl; 
        cout << "Weighted: " << (this->isWeighted ? "true" : "false") << endl;
        cout << "Negative Edge: " << (this->isNegative ? "true" : "false") << endl;
        cout << "Number of Vertices: " << this->numV << endl;
        cout << "Number of Edges: " << this->numE << endl;    
    
        const vector<vector<int>>& matrix = this->Matrix;
        for (size_t row=0; row< this->numV; ++row){
            for (size_t column=0; column<this->numV; ++column) {
                cout << matrix[row][column]<< " ";
            }
            cout <<endl;
        }
        cout <<endl;
    }

    // Getters 
    const vector<vector<int>>& Graph::getMatrix() const {return this->Matrix;}
    size_t Graph::getNumV() const {return this->numV;}
    size_t Graph::getNumE() const {return this->numE;}
    bool Graph::getIsDirected() const {return this->isDirected;}
    bool Graph::getIsWeighted() const {return this->isWeighted;}
    bool Graph::getHasNegativeEdges() const {return this->isNegative;}

    // Destructor for the Graph class
    Graph::~Graph() {}

    // EX2

    // Implementation of operator printing the graph - print graph's matrix
    ostream& operator<<(ostream &stream, const Graph &g) {
        const vector<vector<int>> & matrix = g.Matrix;
        for (size_t row=0; row< g.numV; ++row){
            stream << "[" ;
            for (size_t column=0; column<g.numV; ++column) {
            stream << matrix[row][column]; 
            if (column < g.numV -1) {
                    stream << ", ";
            }
            }
            stream << "]" << endl;
        }
        stream << endl;
        return stream;
    }

    // Function to check if two graphs have the same size of matrix (n x n)
    bool Graph::checkSameSize(const Graph& first ,const Graph& second) const{
        if (first.getMatrix().size() != second.getMatrix().size()) {
            return false;
        }
        return true;
    }

    // Operator '+' to add two graphs
    Graph Graph::operator+(const Graph& other) const {
        if(!checkSameSize(*this, other)) {
            throw invalid_argument("Error: the graphs have different size");
        }
        Graph sum;
        const vector<vector<int>> &matrix1 = this->Matrix;
        const vector<vector<int>> &matrix2 = other.getMatrix();
        vector<vector<int>> sumMatrix( matrix1.size(), vector<int>(matrix1[0].size(), 0));
        
        for (size_t row=0; row<other.getNumV(); ++row){
            for (size_t column=0; column<other.getNumV(); ++column) {
                sumMatrix[row][column] = matrix1[row][column] + matrix2[row][column];
            }
        }
        // load graph from the sumMatrix
        sum.loadGraph(sumMatrix);
        return sum;
    }

    // Operator '+=' to add two graphs: a+=b -> a=a+b
    Graph& Graph::operator+=(const Graph& other) {
        if(!checkSameSize(*this, other)) {
            throw invalid_argument("Error: the graphs have different size");
        }
        const vector<vector<int>> &matrix1 = other.getMatrix();
        for (size_t row=0; row<other.getNumV(); ++row){
            for (size_t column=0; column<other.getNumV(); ++column) {
                this->Matrix[row][column] += matrix1[row][column];
            }
        }

        // return the matrix
        return *this;
    }

    // Operator + unary
    Graph Graph::operator+() const {
        return Graph(*this);
    }

    // Prefix add operator to add the weight of the edges in the graph by 1
    Graph& Graph::operator++() {
        for (size_t row = 0; row < Matrix.size(); ++row) {
            for (size_t column = 0; column < Matrix[row].size(); ++column) {
                if (Matrix[row][column] !=0) {
                    Matrix[row][column] += 1; // add each edge weight by 1
                }    
            }
        }
        return *this; // Return the current graph
    }

    // Postfix add operator to add the weight of the edges in the graph by 1
    Graph Graph::operator++(int) {
        Graph old = *this; //  Create a copy of the current state of the graph.
        for (size_t row=0; row<old.getNumV(); ++row){
            for (size_t column=0; column<old.getNumV(); ++column) {
            if (Matrix[row][column] !=0) {
                    Matrix[row][column] += 1; // add each edge weight by 1
                }    
            }
        }
        return old; // return the orignal version
    }

    // Operator '-' to subtract between two graphs
    Graph Graph::operator-(const Graph& other) const {
        if(!checkSameSize(*this, other)) {
            throw invalid_argument("Error: the graphs have different size");
        }
        Graph substract;
        const vector<vector<int>> &matrix1 = this->Matrix;
        const vector<vector<int>> &matrix2 = other.getMatrix();
        vector<vector<int>> substractMatrix(matrix1.size(), vector<int>(matrix1[0].size(), 0));
        
        for (size_t row=0; row<other.getNumV(); ++row){
            for (size_t column=0; column<other.getNumV(); ++column) {
                substractMatrix[row][column] = matrix1[row][column] - matrix2[row][column];
            }
        }
        // load graph from the sumMatrix
        substract.loadGraph(substractMatrix);
        return substract;
    }

    // Operator '-=' to to subtract between two graphs: a-=b -> a=a-b
    Graph& Graph::operator-=(const Graph& other) {
        if(!checkSameSize(*this, other)) {
            throw invalid_argument("Error: the graphs have different size");
        }
        const vector<vector<int>> &matrix1 = other.getMatrix();
        for (size_t row=0; row<other.getNumV(); ++row){
            for (size_t column=0; column<other.getNumV(); ++column) {
                this->Matrix[row][column] -= matrix1[row][column];
            }
        }
        return *this;
    }

    // Operator - unary
    Graph Graph::operator-() const{
        Graph g (*this);
        for (size_t row=0; row<g.getNumV(); ++row){
            for (size_t column=0; column<g.getNumV(); ++column) {
            g.Matrix[row][column] *= -1;
            }
        }
        return g;
    }

    // Prefix decrement operator to decrease the weight of the edges in the graph by 1
    Graph& Graph::operator--() {
        for (size_t row = 0; row < Matrix.size(); ++row) {
            for (size_t column = 0; column < Matrix[row].size(); ++column) {
                if (Matrix[row][column] !=0) {
                    Matrix[row][column] -= 1; // decrease each edge weight by 1
                }    
            }
        }
        return *this; // Return the current graph
    }

    // Postfix decrement operator to decrease the weight of the edges in the graph by 1
    Graph Graph::operator--(int) {
        Graph old = *this; //  Create a copy of the current state of the graph.
        for (size_t row=0; row<old.getNumV(); ++row){
            for (size_t column=0; column<old.getNumV(); ++column) {
                if (Matrix[row][column] !=0) {
                    Matrix[row][column] -= 1; // decrease each edge weight by 1
                }
            }
        }
        return old; // return the orignal version
}
    // Scalar multiplication operator to multiply the weight of all edges by an integer scalar
    Graph Graph::operator*(int scalar) const {
        Graph result = *this; // Create a copy of the current graph
        for (size_t row = 0; row < result.getNumV(); ++row) {
            for (size_t column = 0; column < result.getNumV(); ++column) {
                result.Matrix[row][column] *= scalar; // Multiply each edge weight by the scalar
            }
        }
        return result; // Return the new graph with scaled edge weights
    }

    // Operator '*' to multiply between two graphs
    Graph Graph::operator*(const Graph& other) const {
        if (Matrix[0].size() != other.getMatrix().size()) {
            throw invalid_argument("Error: the graphs aren't compatible for multiplication (g1: nxm, g2: mxz)");
        }
        Graph multiply;
        const vector<vector<int>> &matrix1 = Matrix;
        const vector<vector<int>> &matrix2 = other.getMatrix();
        vector<vector<int>> multiplyMatrix(matrix1.size(), vector<int>(matrix1[0].size(), 0));
        
        for (size_t row=0; row<matrix1.size(); ++row){
            for (size_t column=0; column< matrix2[0].size(); ++column) {
                for (size_t k = 0; k < matrix1[0].size(); ++k) {
                    multiplyMatrix[row][column] += matrix1[row][k] * matrix2[k][column];
                }
            }
        }
        // load graph from the multiplyMatrix
        multiply.loadGraph(multiplyMatrix);
        return multiply;
    }

    // A graph G1 is larger than a graph G2 if the graph G2 is contained directly in the graph G1. 
    // If neither graph is exactly contained in the other and the graphs are unequal, 
    //then graph G1 is greater than graph G2 if the number of edges in G1 is greater than the number of edges in G2. 
    //If the number of edges is the same, then the graph G1 is larger than the graph G2 if the representative matrix of G1 has a greater size than G2.

    // Function return true is G1 is containe G2, else return false;
    // G2 is contained in G1 if G1 has more or equal V than G2 and has the same wigheted edges
    bool Graph::isContained(const Graph& other) const {
        if (other.getNumV()> numV) {
            return false;
        }
        const vector<vector<int>> &otherMatrix = other.getMatrix();
        // Check same edges
        for (size_t row = 0; row < other.getNumV(); ++row) {
            for (size_t column = 0; column < other.getNumV(); ++column) {
                // Check if the edge in the other graph exists
                if (otherMatrix[row][column] != 0) {
                    if (Matrix[row][column]!=otherMatrix[row][column]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }  

    // Operator '==' : if G1 and G2 has equals matrix return true; else return false 
    bool Graph::operator==(const Graph& other) const {
        return Matrix == other.getMatrix();
    }

    // Operator '!=' : if G1 and G2 hasn't equals matrix return true; else return false
    bool Graph::operator!=(const Graph& other) const {
        return  !(*this == other);
    }

    // Operator '>' : if G1 is bigger than G2 return true; else return false
    bool Graph::operator>(const Graph& other) const {
        // if G2 is directly contained in G1
        if (isContained(other) && !(*this == other)){
            return true;
        }

        // if G1 has more edges than G2
        if (numE != other.getNumE()){
            return numE > other.getNumE(); 
        }
        
        // if the number of edges is the same, compare the number of vertices
        return numV > other.getNumV();      
    }
    
    // Operator '>=' : if G1 is bigger than or equal to G2 return true; else return false
    bool Graph::operator>=(const Graph& other) const {
        return *this > other ||  *this == other;   
    }

    // Operator '<' : if G1 is smaller than G2 return true; else return false
    bool Graph::operator<(const Graph& other) const {
        return !(*this >= other);
    }

    // Operator '<=' : if G1 is smaller than ot equal to G2 return true; else return false
    bool Graph::operator<=(const Graph& other) const {
        return *this < other || *this == other;
    }
}
