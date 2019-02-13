/*
###
Question 4.1: Routes Between Nodes
###

Description:
Given a directed graph, design an algorithm to find out whether there 
is a route between the nodes.

Explanation:
Directed Graph - Graph with unidirectional connections

*/
#include<iostream>
#include "../lib/graph.cpp"
using namespace std;




int main()
{
    // Path problem on graph -> BFS (Breadth-First Search)
    directed_graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(0,5);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(3,4);

    cout << "Breath first traversal:\n";
    g.BFS(0);

    cout << "Search path between nodes: 0, 3\n";
    bool result = g.checkConnection(0, 3);
    result ? cout << "Connected!\n" : cout << "Not connected..\n";

    cout << "Search path between nodes: 1, 5\n";
    result = g.checkConnection(1, 5);
    result ? cout << "Connected!\n" : cout << "Not connected..\n";
    return 0;
    
}
