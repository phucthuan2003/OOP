#include <bits/stdc++.h>
#include "Graph.cpp"

using namespace std;

int main(){
    Graph g;
    g.readFile("Graph.txt");
    g.writeFile("WriteGraph.txt");
    g.DFS(1);
    g.display();
}