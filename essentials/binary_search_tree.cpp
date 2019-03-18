/*
###
Playing with binary search trees
###

Definition:
binary search tree (BST) - A binary tree that has a key associated with each of
its internal nodes, with the additional property that the key in any node
is larger than (or equal to) the keys in all nodes in that node's left subtree
and smaller than (or equal to) the keys in all nodes in that node's
right structure.
STL set/map - Red-Black Tree (self balancing binary search tree) using
rebalancing with rotations. Ordered tree structure, allowing fast access.

ADT Properties:
Insert: 1.39 lg N comp on average in a tree with N random keys, N worst case.
Search: 1.39 lg N comp on average in a tree with N random keys, N worst case.
Remove: Depending on strategy, e.g. lazy removal, periodical rebuild, etc.
Select: Same as search/insert
Sort: Already sorted, access via in-order traversal
Join: O(N) by using an additional array

Drawbacks:
- Using space for links
- Trees can become poorly balanced and loose average search time of 1.4 lg N
*/

#include<iostream>
#include<set> // using keys only
#include<vector>
using namespace std;

/*
###
Binary Search Tree
###
*/

class binarySearchTree
{
    struct node
    {
        int key;
        node* l;
        node* r;
        node(int x): key{x}, l{0}, r{0}{ };
    };

    typedef node* link;
    int count;
    link head;

    int searchBST(link l, int key)
    {
        if(l == 0) return -1;

        int r = l->key;

        if(key == r) return l->key;

        if(key < r) return searchBST(l->l, key);
        else return searchBST(l->r, key);
    }

    // Expects random values for a balanced tree
    void insertBST(link& l, int key)
    {
        if(l == 0)
        {
            l = new node(key);
            return;
        }
        if(key < l->key) insertBST(l->l, key);
        else insertBST(l->r, key);
    }


    // Creates a balanced tree from sorted vector
    void createBalancedBST(link& l, vector<int>& v, int start, int end)
    {
        if(end < start) return;

        int mid = (start + end) / 2;

        l = new node(v[mid]);
        count++;
        createBalancedBST(l->l, v, start, mid-1);
        createBalancedBST(l->r, v, mid+1, end);
    }

    void printInOrderBST(link l)
    {
        if(l == 0) return;
        printInOrderBST(l->l);
        cout << l->key << " ";
        printInOrderBST(l->r);
    }

public:
    binarySearchTree(): head{0}, count{0}{}

    int search(int key) { return searchBST(head, key); }

    void insert(int key) { insertBST(head, key); }

    void createBalanced(vector<int>& v)
    { createBalancedBST(head, v, 0, v.size()-1); }

    void printInOrder() { printInOrderBST(head); cout << endl;}
};

int main()
{
    /*
    ###
    Binary Search Tree
    ###
    */

    // balanced tree from random values
    binarySearchTree bst;

    for(int i=0; i<100; i++)
        bst.insert(rand() % 10000);

    cout << "Tree from random values:\n";
    bst.printInOrder();

    // balanced tree from sequence
    vector<int> seed;
    for(int i=0; i<100; i++)
        seed.push_back(i);

    binarySearchTree bst2;
    bst2.createBalanced(seed);

    cout << "Tree from sequential values:\n";
    bst2.printInOrder();


    /*
    ###
    STL map
    ###
    */

    // empty map container
    set<int> st;

    for(int i=0; i<100; i++)
        st.insert(rand() % 10000);

    cout << "STL set of random values:\n";
    set<int>::iterator iter;
    for(iter = st.begin(); iter != st.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // st.erase(int);
    // st.size();
    // st.begin();
    // st.end();
    // st.empty();
    // st.clear();
}
