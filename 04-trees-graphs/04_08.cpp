/*
###
Question 4.8: First Common Ancestor
###

Description:
Design an algorithm and write code to find the first common ancestor
of two nodes in a binary tree. Avoid storing additional nodes in a 
data structure. NOTE: This is not necessarily a binary search tree.

Example:


Hint:
Don't forget to ask:
- If the elements are present in the tree or we have to check that they exist
- If the tree node have links to the parent element

Runtime:

*/

#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node
{
    int key;
    node* r;
    node* l;
    node* p;
    node(int x, node* a): key{x}, r{0}, l{0}, p{a} { };
};
typedef node* link;

void insertS(link& h, link& p, int x)
{

    // check if bottom of tree
    if(h == 0)
    {
        h = new node(x, p);
        return;
    }
    int rnd = rand() % 2;
    if(rnd) insertS(h->l, h, x);
    else insertS(h->r, h, x);
}

void inOrder(link h)
{
    if(h == 0) return;
    inOrder(h->l);
    cout << h->key << " ";
    inOrder(h->r);
}

int getLevel(link& h, int l)
{
    if(h->p == 0) return l;
    l++;
    l = getLevel(h->p, l);
    return l;
}

link commonAncestor(link a, link b)
{
    // get levels
    int la = getLevel(a, 0);
    int lb = getLevel(b, 0);

    // if they're not the same bring lower up
    if(la != lb)
    {
        link& lower  = min(la, lb) == la ? a : b; 
        int diff = max(la, lb) - min(la, lb);
        for(int i=0; i<diff; i++) lower = lower->p;
        min(la, lb) == la ? a = lower : b = lower;
    }


    // start comparing parents until common ancestor isfound
    while(a->p != 0)
    {
        if(a->p == b->p) return a->p;
        a = a->p;
        b = b->p;
    }
    return 0;
        
}

int main()
{
    int seed[20];

    for(int i=0; i<20; i++) seed[i] = rand() % 20;

    link head = 0;
    for(int i=0; i<20; i++) insertS(head, head, seed[i]);

    inOrder(head);
    cout << endl;

    cout << "root: " << head->key << endl;
    cout << "root level: " << getLevel(head, 0) << endl;

    cout << "right right: " << head->r->r->key << endl;
    cout << "right right parent: " << head->r->r->p->key << endl;
    cout << "right right level: " << getLevel(head->r->r, 0) << endl;

    link ancestor = commonAncestor(head->r->r, head->l->l);
    cout << "ancestor of ->r->r & ->l->l: " << ancestor->key << endl;

    cout << "left right: " << head->l->r->key << endl;
    cout << "left left: " << head->l->l->key << endl;
    link ancestor2 = commonAncestor(head->l->r, head->l->l);
    cout << "ancestor of ->l->r & ->l->l: " << ancestor2->key << endl;

    return 0;
}
