#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main()
{
    vector<list<int>> lists;
    list<int> list;
    lists.push_back(list);

    lists[0].push_back(4);

    cout << lists[0].back() << endl;
    
}