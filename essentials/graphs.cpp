/*
###
Playing with graphs
###

Definition:
Graph - A graph is a set of nodes together with a set of edges that connect pairs
of distinct nodes (with at most one edge connecting any pair of nodes).


ADT Properties:
Insert: 
Search: 
Remove: 
Select:
Sort: 
Join: 


*/

#include<iostream>
#include<forward_list>
#include<unordered_map>
using namespace std;

// using doubly linked lists (could use forward_list)
// and a unordered_map to represent a graph in and adjacency matrix

class directedGraph
{
    int V;
    unordered_map<int, forward_list<int>> adj;

    void addEdgeDG(int v, int w)
    {
        if(adj.count(v) == 0)
        {
            forward_list<int> fl;
            V++;
            adj[v] = fl;
        }
        adj[v].push_front(w);
    }

    void printEdgesDG(int v)
    {
        if(adj.count(v) != 0)
            for(auto edge : adj[v])
                cout << edge << " ";
            cout << endl;
    }
public:
    directedGraph(): V{0}{}
    void addEdge(int v, int w){ addEdgeDG(v, w); }
    int size(){ return V; }
    void printEdges(int v) { printEdgesDG(v); }
};

int main()
{
    directedGraph dg;
    dg.addEdge(3,0);
    dg.addEdge(1,5);
    dg.addEdge(3,1);
    dg.addEdge(0,5);
    dg.addEdge(2,3);

    cout << "Edges of 3:\n";
    dg.printEdges(3);

    return 0;
}