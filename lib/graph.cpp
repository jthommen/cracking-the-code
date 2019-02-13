#include<iostream>
#include<list>
using namespace std;

class directed_graph
{
private:
    // Number of vertices
    int V;
    // Pointer to array containing adj lists
    list<int>* adj;
public:
    directed_graph(int v): V{v}, adj{new list<int>[V]}{};
    void addEdge(int v, int w) { adj[v].push_back(w); }

    void BFS(int);
    bool checkConnection(int, int);

};

void directed_graph::BFS(int s)
{
    // pointer to bool array
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    // list working as queue
    list<int> queue;

    // setting source as visited
    visited[s] = true;
    // pushing source to back of queue
    queue.push_back(s);

    // STL iterator to use for adj lists
    list<int>::iterator i;

    //
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i=adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }

    }
    cout << endl;

}


bool directed_graph::checkConnection(int a, int b)
{
    if(a==b) return true;

    // bfs queue
    list<int> queue;

    bool* visited = new bool[V];
    for(int i=0; i<V; i++) visited[i] = false;

    visited[a] = true;
    queue.push_back(a);

    list<int>::iterator i;

    while(!queue.empty())
    {
        a = queue.front();
        if(a == b) return true;
        queue.pop_front();

        for(i=adj[a].begin(); i != adj[a].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}