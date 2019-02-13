/*
###
Question 4.5: Validate BST
###

Description:
Implement a function to check if a binary tree is a binary
search tree.


Example:

Hint:
Binary Tree - Every node has max. two children
Binary Search Tree - Binary tree where the child to the left is smaller
than the parten and the child to the right is bigger.

Runtime:
Time O(N), space O(log N)

*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>
using namespace std;


struct node
{
    int key;
    node* l;
    node* r;
    node(int x): key{x}, l{0}, r{0} {}
};
typedef node* link;

void createBalancedTree(link& h, vector<int>& v, int start, int end)
{
    if(end < start) return;

    int mid = (start + end) /2;
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

// Create binary search tree recursively
void insertR(link& h, int x)
{
    // insert when we found an empty node
    if(h == 0) {
        h = new node(x);
        return;
    }
    if(x < h->key) insertR(h->l, x);
    else insertR(h->r, x);
}

// Create binary tree recursively
void insertS(link& h, int x)
{
    if(h == 0)
    {
        h = new node(x);
        return;
    }
    if(h->l == 0) insertS(h->l, x);
    else insertS(h->r, x);
}

void inOrder(link h)
{
    if(h == 0) return;
    inOrder(h->l);
    cout << h->key << " ";
    inOrder(h->r);
}

bool isBST(link h, int min, int max)
{

    if(h == 0) return true;

    if((min != 0 && h->key <= min) || (max != 0 && h->key > max))
        return false;

    // Go left: max is udpated, min stays
    // Go right: min is updated, max stays
    if(!isBST(h->l, min, h->key) || !isBST(h->r, h->key, max))
        return false;
    
    return true;
}


int main()
{
    vector<int> seed = {1,3,5,7,9,11};

    link head = createBalancedTree(seed);
    inOrder(head);
    cout << endl;

    isBST(head, 0, 0) ? cout << "True\n" : cout << "False\n";

    link head2 = 0;
    for(auto n : seed) insertS(head2, n);
    inOrder(head2);
    cout << endl;

    isBST(head2, 0, 0) ? cout << "True\n" : cout << "False\n"; 

    return 0;
}