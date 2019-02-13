#include<list>
#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<list<int>> adj;

    for(int i=1; i<=6; i++)
    {
        list<int> l;
        adj.push_back(l);
    }

    adj[1].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);

    cout << "Element 1, list 1: " << adj[1].back() << endl;
    cout << "Element 1, list 3: " << adj[3].back() << endl;
    cout << "Element 1, list 4: " << adj[4].back() << endl;

    for(auto c: adj)
        cout << c.back() << endl;
    
}