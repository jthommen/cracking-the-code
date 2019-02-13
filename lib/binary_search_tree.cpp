#include<iostream>
#include<list>
#include<vector>
using namespace std;

template<typename T>
class BST
{
private:
    struct node
    {
        T item;
        node* l;
        node* r;
        node(T x): item{x}, l{0}, r{0} {}
    };

    typedef node* link;
    int cnt;
    link head;
    link nullItem;

    T searchR(link h, T v)
    {
        // empty tree, return null
        if(h == 0) return nullItem;

        // get key of root item
        T t = h->item;

        // if it's the item searched for, return
        if(v == t) return h->item;

        // otherwise check if it's bigger or smaller than search key
        // smaller -> go left, bigger -> go right
        if(v < t) return searchR(h->l, v);
        else return searchR(h->r, v);
    }

    void insertR(link& h, T x)
    {
        // insert when we found an empty node
        if(h == 0) {
            h = new node(x);
            return;
        }
        if(x < h->item) insertR(h->l, x);
        else insertR(h->r, x);
    }

    // Create minimal balanced BST
    void createMinimal(link& h, vector<T>& v, int start, int end)
    {
        // check for range validity
        if(end < start) return;

        // Calculate middle of vector
        int mid = (start + end) / 2;

        // Create new item
        h = new node(v[mid]);
        cnt++;
        createMinimal(h->l, v, start, mid-1);
        createMinimal(h->r, v, mid+1, end);

    }

    void preOrder(link head)
    {
        if(head == 0) return;
        preOrder(head->l);
        preOrder(head->r);  
        cout << head->item << endl;
    }

    void inOrder(link head)
    {
        if(head == 0) return;
        inOrder(head->l);
        cout << head->item << endl;
        inOrder(head->r);
    }

    void postOrder(link head)
    {
        if(head == 0) return;
        cout << head->item << endl;
        postOrder(head->l);
        postOrder(head->r);
    }

    void depthListR(link head, int d, int cnt)
    {
        if(head == 0) return;
        if(cnt <= d)
        {
            cnt++;
            depthListR(head->l);
            // push to list with recursion depth
            depthListR(head->r);
        }

    }

public:
    BST(): head{0}, cnt{0}{};

    T search(T v) { return searchR(head, v); }

    void insert(T x) { insertR(head, x); }

    void createMinimalTree(vector<T>& v)
    { return createMinimal(head, v, 0, v.size()-1); }


    void printPreOrder() { preOrder(head); }
    void printInOrder() { inOrder(head); }
    void printPostOrder() { postOrder(head); }

    void depthList(int d)
    {
        int count=0;
        depthListR(head, d, count); 
    }
};