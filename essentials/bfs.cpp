/*
###
Playing with breadth first search (queue)
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
#include<queue>
#include<unordered_map>

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
public:
    directedGraph(): V{0}{}
    void addEdge(int v, int w){ addEdgeDG(v, w); }
    int size() { return V; }
    void printEdges(int v) { printEdgesDG(v); }
    void BFS(int);
};

// breadth-first search starting from source
void directedGraph::BFS(int s)
{
    if(s > V) return;

    // create visited bool vector
    vector<bool> v;
    for(int i=0; i<V; i++)
        v.push_back(false);

    // create queue for traversal
    queue<int> q;

    // start with source vertices, mark visited
    v[s] = true;
    q.push(s);

    // Iterate over edges
    forward_list<int>::iterator i;

    while(!q.empty())
    {
        // get next vertex from the queue
        s = q.front();
        // print path of bfs
        cout << s << " ";

        // remove elem
        q.pop();

        // Iterate over it's edges, mark as visited and it to the queue
        for(i = adj[s].begin(); i != adj[s].end(); i++)
            if(!v[*i])
            {
                v[*i] = true;
                q.push(*i);
            }
    }
    cout << endl;
}


int main()
{

    directedGraph dg;
    dg.addEdge(0, 1); 
    dg.addEdge(0, 4); 
    dg.addEdge(0, 5); 
    dg.addEdge(1, 3); 
    dg.addEdge(1, 4); 
    dg.addEdge(2, 1); 
    dg.addEdge(3, 2); 
    dg.addEdge(3, 4); 

    cout << "BFS starting from vertex 0: ";
    dg.BFS(0);

    return 0;
}
