/*
###
Question 4.4: Check Balanced
###

Description:
Implement a function to check if a binary tree is balanced. For the purpose of this
question, a balanced tree is defined to be a tree that the heights of the two subtrees
of any node never differ by more than one.


Example:

Hint:

Runtime:


*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>
using namespace std;

const int ERROR = numeric_limits<int>::min();

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

void inOrder(link h)
{
    if(h == 0) return;
    inOrder(h->l);
    cout << h->key << " ";
    inOrder(h->r);
}

int checkHeight(link h)
{
    // null tree check
    if(h == 0) return -1;

    int leftHeight = checkHeight(h->l);
    if(leftHeight == ERROR) return ERROR;

    int rightHeight = checkHeight(h->r);
    if(rightHeight == ERROR) return ERROR;

    int heightDiff = leftHeight - rightHeight;
    if(abs(heightDiff) > 1) return ERROR;
    else return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(link h)
{
    return checkHeight(h) != ERROR;
}



int main()
{
    // Balanced Tree
    vector<int> seed = {0,1,2,3,4,5,6,7,8,9};

    link head = createBalancedTree(seed);
    inOrder(head);
    cout << endl;

    isBalanced(head) ? cout << "True\n" : cout << "False\n";

    // Unbalanced Tree

    link head2 = 0;
    for(auto c : seed) insertR(head2, c);

    inOrder(head2);
    cout << endl;

    isBalanced(head2) ? cout << "True\n" : cout << "False\n";
}