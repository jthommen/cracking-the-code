/*
###
Question 4.9: BST Sequences
###

Description:
A binary search tree was created by traversing through an array from left
to right and inserting each element. Given a binary search tree with distinct
elements, print all possible arrays that could have led to this tree.

Example:


Hint:

Runtime:

*/

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int key;
    node* r;
    node* l;
    node(int x): key{x}, r{0}, l{0} { };
};
typedef node* link;


void inOrder(link h)
{
    if(h == 0) return;
    inOrder(h->l);
    cout << h->key << " ";
    inOrder(h->r);
}

void createBalancedTree(link&h, vector<int>& v, int start, int end)
{
    if(end < start) return;

    int mid = (start + end) / 2;
    h = new node(v[mid]);
    createBalancedTree(h->l, v, start, mid-1);
    createBalancedTree(h->r, v, mid+1, end);
}

link createBalancedTree(vector<int>& v)
{
    link h = 0;
    createBalancedTree(h, v, 0, v.size()-1);
    return h;
}

vector<vector<int>> createBSTsequences(link h)
{
    vector<vector<int>> sequences;
    int level = 0;
    while(h != 0)
    {
        vector<int> 
        // Go through tree level for level
        if(level == 0) 
        // add permutations to array sequence

    }

}

int main()
{
    vector<int> seed = {1,2,3};
    link head = createBalancedTree(seed);
    inOrder(head);
    cout << endl;

    return 0;
}
