/*
###
Question 2.1: Remove Dups
###

Description:
Write code to remove duplicates from an unsorted linked list.
Follow-up: How would you solve this problem, if a temporary
buffer is not allowed?

Example:


Hint:

Runtime:
O(N)

*/

#include<iostream>
using namespace std;


// Symbol table for hash table with separate chaining
template<typename Item, typename Key>
class ST
{
private:

    struct node
    {
        Item item;
        node* next;
        node(Item x, node* t): item{x}, next{t} { };
    };

    typedef node* link;

    link* heads;
    int N, M;
    int nullItem;
    
    
    Item searchR(link t, Key v)
    {
        if(t==0) return nullItem;
        if(t->item == v) return t->item;
        return searchR(t->next, v);
    }

    // Hashing funtion for int keys
    inline int hash(Key v, int M) { return v % M; }

    inline void printR(link x)
    { cout << x->item << " "; }

    void removeR(Item x)
    {
        link t = x->next;
        x->next = t->next;
        // delete x ? Memory leak?
        return x;
    }

public:
    ST(int maxN): N{0}, M{(maxN+5)/5}, heads{new link[M]}, nullItem{0}
    { for(int i=0; i<M; i++) heads[i] = 0; }

    int count() { return N; }

    Item search(Key v)
    { return searchR(heads[hash(v, M)], v); }

    void insert(Item x)
    {
        int i = hash(x, M);
        heads[i] = new node(x, heads[i]);
        N++;
    }

    void remove(Item x)
    { return removeR(x);}

    void print(Item x)
    { return printR(x); }
};


int main()
{

    int N = 10;
    

    // Create array of N elements
    int seed[N] = {2,3,4,2,1,3,5,3,1,3};

    // Print array
    cout << "Unsorted Array with duplicates:\n";
    for(int i=0; i<N; i++) cout << seed[i] << " ";
    cout << endl;

    // using hashtable to remove duplicates
    cout << "Unsorted, duplicates removed:\n";
    ST<int, int>* st = new ST<int, int>(N);
    for(int i=0; i<N; i++)
    {
        if(st->search(seed[i]) == 0)
        {
            st->insert(seed[i]);
            cout << seed[i] << " ";
        }
    }
    cout << endl;

    return 0;

}