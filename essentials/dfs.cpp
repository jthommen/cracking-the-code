/*
###
Playing with depth first search ()
###

Properties:
Sort: 
- Worst case:
- Best case:
- Average case:
- Worst case space
- stable

*/
#include<forward_list>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

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

    void DFSUtil(int s, vector<bool>& v)
    {
        v[s] = true;
        cout << s << " ";

        // recurse through all edges of s
        forward_list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            cout << "\nEdge of " << s << ": " << *i << endl;
            if(!v[*i])
                DFSUtil(*i, v);
        }
    }

public:
    directedGraph(): V{0}{}
    void addEdge(int v, int w){ addEdgeDG(v, w); }
    int size() { return V; }
    void printEdges(int v) { printEdgesDG(v); }
    void DFS(int s)
    {
        if(s > V) return;

        // create visited vector
        vector<bool> v;
        for(int i=0; i<V; i++)
            v.push_back(false);
        
        DFSUtil(s, v);
        cout << endl;
    }
};




int main()
{

    directedGraph dg;
    dg.addEdge(0, 1); 
    dg.addEdge(0, 2); 
    dg.addEdge(1, 2); 
    dg.addEdge(2, 0); 
    dg.addEdge(2, 3); 
    dg.addEdge(3, 3);

    cout << "Size: " << dg.size() << endl;

    cout << "DFS starting from vertex 0:\n";
    dg.DFS(2);

    return 0;
}
