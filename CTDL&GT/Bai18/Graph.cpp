#include <bits/stdc++.h>
#include "Stack_for_Array.cpp"

#ifndef ___Graph___cpp___
#define ___Graph___cpp___

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > adjMatrix;

public:
    Graph(){
        V = 0;
    }
    Graph(int vertices){
        adjMatrix.resize(V , vector<int>(V , 0));
    }
    void addEdge(int u, int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    void readFile(const string &filename){
        ifstream file(filename);
        if(file.is_open()){
            file >> V;
            adjMatrix.resize(V , vector<int>(V , 0));
            int edges;
            file >> edges;
            if(edges <= 0){
                cerr << "Invalid number of edges !" << endl;
                file.close();
                return;
            }
            int u , v;
            while(edges -- ){
                file >> u >> v;
                if(u < 0 || u >=V  || v < 0 || v >= V){
                    cerr << "Invalid vertex indices !" << endl;
                    continue;;
                }
                addEdge(u , v);
            }
            file.close();
        }else {
            cerr << "Unable to open file :" << filename << endl;
        }
    }
    void writeFile(const string &filename){
        ofstream file(filename);
        if(file.is_open()){
            file << V << "\n";
            for(int i=0 ; i < V ; i++){
                for(int j = i+1 ; j < V ; j++){
                    if(adjMatrix[i][j] == 1){
                        file << i << "  " << j << "\n";
                    }
                }
            }
            file.close();
        }else{
            cerr << "Unable to open file ";
        }
    }
    void DFS(int startVertex){
        ArrayStack<int> stack;
        vector<bool> visited(V, false);

        stack.push(startVertex);
        visited[startVertex] = true;

        cout << "Depth First Traversal: ";

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << currentVertex << " ";
            for (int i = 0; i < V; ++i) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
    void display(){
        if (V == 0) {
            cout << "Empty graph" << endl;
            return;
        }
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<vector<int> > floydWarshall(vector<vector<int> >& graph) {
        int V = graph.size();
        vector<vector<int> > dist = graph;

        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
};
#endif
