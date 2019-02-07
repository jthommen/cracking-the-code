/*
###
Searching: Hashing with separate chaining (Singly linked list)
###

Description:
Using array of singly linked lists.

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
    Item nullItem;
    
    
    Item searchR(link t, Key v)
    {
        if(t==0) return nullItem;
        if(t->item.key() == v) return t->item;
        return searchR(t->next, v);
    }

    // Hashing funtion for int keys
    inline int hash(Key v, int M) { return v % M; }

    void printR(link x)
    {
        while(x->next != 0)
        {
            cout << x->item << " ";
            x = x->next;
        }
    }

    void removeR(Item x)
    {
        link t = x->next;
        x->next = t->next;
        delete x;
        return x;
    }

public:
    ST(int maxN): N{0}, M{maxN/5}, heads{new link[M]} 
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

    void printAll()
    {
        // Iterate over heads arrays
        // print elements
        for(int i=0; i<M; i++) printR(heads[i]);
        cout << endl;
        return;
    }

    void remove(Item x)
    { return removeR(x);}
};


int main()
{

    int N = 10;
    
    ST<int, int>* st = new ST<int, int>(N);

    // Create list of N elements
    int seed[N] = {1,2,3,1,2,3,1,2,3,4};

    //
    for(int i=0; i<N; i++) st->insert(rand() % 1000);

    cout << "Unsorted List: ";
    st->printAll();  

    // Create hash table with separate chaining

    return 0;

}