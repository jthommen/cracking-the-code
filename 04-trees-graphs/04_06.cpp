/*
###
Question 4.6: Successor
###

Description:
Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent.


Example:

Hint:

Runtime:

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
    node* p;
    node(int x, node* l): key{x}, l{0}, r{0}, p{l} {}
};
typedef node* link;

void createBalancedTree(link& h, link& p, vector<int>& v, int start, int end)
{
    if(end < start) return;
    int mid = (start + end) /2;
    h = new node(v[mid], p);

    createBalancedTree(h->l, h, v, start, mid-1);
    createBalancedTree(h->r, h, v, mid+1, end);
}

link createBalancedTree(vector<int>& v)
{
    link h = 0;
    link p = 0;
    createBalancedTree(h, p, v, 0, v.size()-1);
    return h;
}

// Create binary search tree recursively
void insertR(link& h, int x)
{
    // insert when we found an empty node
    if(h == 0) {
        h = new node(x, h);
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
        h = new node(x, h);
        return;
    }
    if(h->l == 0) insertS(h->l, x);
    else insertR(h->r, x);
}

void inOrder(link& h)
{
    if(h == 0) return;
    inOrder(h->l);
    cout << h->key << " ";
    inOrder(h->r);
}

link nextNode(link& h)
{   
    // Cases
    // right node exists -> return right
    if(h->r != 0 && h->r->key > h->key) return h->r;
    
    // parent is bigger (left subtree) -> return parent
    // go up the tree as much as necessary
    link parent = h->p;
    while(parent != 0)
    {
        if(parent->key > h->key) return parent;
        parent = parent->p;
    }

    // No right element, no bigger parent (right subtree) -> biggest eleme return elem
    return h;
}

int main()
{
    vector<int> seed = {1,3,5,7,9,11};

    link head = createBalancedTree(seed);
    inOrder(head);
    cout << endl;

    /*
    cout << "root: " << head->key << endl;
    cout << "right: " << head->r->key << endl;
    cout << "right right: " << head->r->r->key << endl;
    cout << "right left: " << head->r->l->key << endl;
    cout << "left: " << head->l->key << endl;
    cout << "left right: " << head->l->r->key << endl;
    cout << "parent of right: " << head->r->p->key << endl;
    */

    cout << "---- \n";
    cout << "Node check: " << head->l->key << endl;
    link res = nextNode(head->l);
    cout << "Next node: " << res->key << endl;

    cout << "---- \n";
    cout << "Node check: " << head->l->r->key << endl;
    res = nextNode(head->l->r);
    cout << "Next node: " << res->key << endl;

    cout << "---- \n";
    cout << "Node check: " << head->r->l->key << endl;
    res = nextNode(head->r->l);
    cout << "Next node: " << res->key << endl;

    cout << "---- \n";
    cout << "Node check: " << head->r->r->key << endl;
    res = nextNode(head->r->r);
    cout << "Next node: " << res->key << endl;

    return 0;
}