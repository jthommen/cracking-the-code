/*
###
Question 4.7: Built Order
###

Description:
You are given a list of projects and a list of dependencies
(which is a list of pairs of projects, where the first project
is dependent on the second project). All of a project's dependencies
must be built before the project is. Find a build order that will
allow the projects to be built. If there is no valid build order,
return an error.

Example:
Input:
    projects; a, b, c, d, e, f
    dependencies: (d, a), (b, f), (d, b), (a, f), (c, d)
Output: f, e, a, b, d, c

Hint:

Runtime:
O(P+D) where P = number of projects and D = number of dependencies

*/

#include<algorithm>
#include<iostream>
#include<list>
#include<vector>
using namespace std;


int main()
{

    int projects = 6;
    vector<list<int>> deps;

    for(int i=0; i<projects; i++)
    {
        list<int> l;
        deps.push_back(l);
    }

    deps[3].push_back(0);
    deps[1].push_back(5);
    deps[3].push_back(1);
    deps[0].push_back(5);
    deps[2].push_back(3);

    vector<int> buildOrder;

    while(buildOrder.size() < projects)
    {
        for(int i = 0; i < projects; i++)
        {
            if(deps[i].size() == 0)
            {
                buildOrder.push_back(i);
                
                deps.at(i).push_back(-1);

                
                for(int j=0; j < projects; j++)
                {
                    list<int>::iterator iter = find(deps[j].begin(), deps[j].end(), i);
                    if(iter != deps[j].end()) deps[j].erase(iter);
                }
                
            }
        }
    }

    for(int p : buildOrder) cout << p+1 << " ";
    cout << endl;

    return 0;
}