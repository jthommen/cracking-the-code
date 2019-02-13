/*
###
Question 4.3: List of Depths

Description:
Given a binary tree, design an algorithm which creates a linked list of all the
nodes at each depth(e.g., if you have a tree with depth D, you'll have D linked lists.)

Example:

Hint:

Runtime:


*/

#include<iostream>
#include<list>
#include<vector>
using namespace std;


struct node
{
    int key;
    node* l;
    node* r;
    node(int x): key{x}, l{0}, r{0} {}
};
typedef node* link;

void createMinimalTree(link& n, vector<int>& v, int start, int end)
{
    if(end < start) return;

    int mid = (start + end) / 2;
    n = new node(v[mid]); 

    createMinimalTree(n->l, v, start, mid-1);
    createMinimalTree(n->r, v, mid+1, end);
}

link createMinimalTree(vector<int>& v)
{
    link head = 0;
    createMinimalTree(head, v, 0, v.size()-1);
    return head;
}

void inOrder(link h)
{
    if(h == 0) return;
    inOrder(h->l);
    cout << h->key << endl;
    inOrder(h->r);
}

void createLevelLinkedList(link h, vector<list<link>>& lists, int level)
{
    if(h == 0) return;

    list<link> l;
    
    try
    {
        list<link> l = lists.at(level);
    }
    catch(const std::exception& e)
    {
        lists.push_back(l);
    }
    
    lists[level].push_back(h);
    
    createLevelLinkedList(h->l, lists, level+1);
    createLevelLinkedList(h->r, lists, level+1);
    
}

vector<list<link>> createLevelLinkedList(link head)
{
    vector<list<link>> lists;
    // Specify link to start frome, list to save result and level
    createLevelLinkedList(head, lists, 0);
    return lists;
}

int main()
{
    vector<int> seed = {0,1,2,3,4,5,6,7,8,9};

    link head = createMinimalTree(seed);
    inOrder(head);

    vector<list<link>> lists = createLevelLinkedList(head);
    
    for(int i=0; i<lists.size(); i++)
    {
        while(!lists[i].empty())
        {
            cout << "Level " << i << ": " << lists[i].back()->key << endl;
            lists[i].pop_back();
        }
    }

    cout << "\n\nHead: " << head->key << endl << endl;
    cout << "Right Sub Tree:\n";
    cout << "right: " << head->r->key << endl;
    cout << "right right: " << head->r->r->key << endl;
    cout << "right left: " << head->r->l->key << endl;
    cout << "right left right: " << head->r->l->r->key << endl;
    cout << "right right right: " << head->r->r->r->key << endl;
    cout << endl;

    cout << "Left Sub Tree:\n";
    cout << "left: " << head->l->key << endl;
    cout << "left right: " << head->l->r->key << endl;
    cout << "left left: " << head->l->l->key << endl;
    cout << "left right right: " << head->l->r->r->key << endl;
   
    
    return 0;

}