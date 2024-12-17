
//Generate C++ code that will implement Prim`s algorithm
//using ADT with a time complexity of O(n^2)
//for a program that will determine the minimum spanning tree
//that will represent the least expensive path for laying
//the fiber cable
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void printMST(const vector<int>& parent) {
        cout << "Minimum Spanning Tree using Prim`s Algorithm: "<<endl;
        for (int i = 1; i < numVertices; i++)
            cout << parent[i] << " - " << i << " \t" << " \n";
    }

    int minKey(const vector<int>& key, const vector<bool>& mstSet) {
        int min = INT_MAX, minIndex;

        for (int v = 0; v < numVertices; v++)
            if (!mstSet[v] && key[v] < min)
                min = key[v], minIndex = v;

        return minIndex;
    }

    void primMST() {
        vector<int> key(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);
        vector<bool> mstSet(numVertices, false);

        key[0] = 0; // Start from the first vertex

        for (int count = 0; count < numVertices - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < numVertices; v++)
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v])
                    parent[v] = u, key[v] = adjMatrix[u][v];
        }

        printMST(parent);
    }
};

int main() {

    ifstream inputFile("fiberdata.txt");//Open input file

    //Check if opening input file is successful
    if(!inputFile)
    {
        cout<<"File failed to open"<<endl;
    }

    int V, E;
    inputFile >> V >> E; //Read number of vertices and edges from input file

 Graph g(V);

    int u, v, weight;
    //Loop to read all edges from the input file and add them to the graph
    for (int i = 0; i < E; i++) {
        inputFile >> u >> v >> weight;//Read edge information
        g.addEdge(u, v, weight); //Add the edge to the graph
    }

    inputFile.close(); //Close the input file

    g.primMST();

    return 0;
}
