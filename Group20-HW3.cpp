#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int vert; // Number of vertices in the graph
    vector<list<int>> adjList; // Adjacency list representation of the graph

public: //initialize the graph with a given number of vertices
    Graph(int v) : vert(v), adjList(v) {}

    void addEdge(int v, int w) { // Function to add an edge to the undirected graph
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
    // Function to perform Depth-First Search traversal
    void DFS(int v, vector<bool>& visited, vector<int>& comp) {
        visited[v] = true;
        comp.push_back(v); // Add the current vertex to the current connected component list
        // Iterate through all neighbors of the current vertex
        for (int nb : adjList[v]) {
            if (!visited[nb]) {
                DFS(nb, visited, comp);
            }
        }
    }
    // Function to find all connected components in the graph
    vector<vector<int>> getConComp() {
        vector<bool> visited(vert, false);
        vector<vector<int>> comps;
        // Iterate through all vertices
        for (int v = 0; v < vert; ++v) {
            if (!visited[v]) {
                vector<int> comp;
                DFS(v, visited, comp);
                comps.push_back(comp);
            }
        }

        return comps;
    }
    // Function to print the adjacency matrix
    void printAdjMatr() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vert; ++i) {
            vector<int> row(vert, 0);
            for (int nb : adjList[i]) {
                row[nb] = 1;
            }
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
    // Function to print all connected components found
    void printConComp() {
        vector<vector<int>> comps = getConComp();
        cout << "Connected Components:";
        for (const auto& comp : comps) {
            cout << "{ ";
            for (int vertex : comp) {
                cout << vertex << " ";
            }
            cout << "}\n";
        }
    }
};

int main() {
    int n, u, v;
    cout << "Number of vertices: ";
    cin >> n;

    Graph graph(n);

    cout << "Enter edges (end with -1):\n";
    while (true) {
        cin >> u;
        if (u == -1) break;
        cin >> v;
        graph.addEdge(u, v);
    }

    graph.printAdjMatr();
    graph.printConComp();

    return 0;
}