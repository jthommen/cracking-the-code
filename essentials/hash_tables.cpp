/*
###
Playing with hash tables (using sets and separate chaining)
###

Definition:
hashtable - Data structure that maps keys to values for highly efficient lookup
Here using separate chaining with a hashing function and a vector of linked lists.
STL unordered_set - hashmap implementation since C++11, allowing O(1) insert and search.
Uses separate chaining for collision resolution. Doesn't allow duplicates.

ADT Properties:
Insert: O(1)
Search: with low collisions O(1), worst case O(N)
Remove: O(1)
Select: O(1)
Sort: -
Join: O(N)


*/
#include<iostream>
#include<unordered_set> // Only using keys, no values
using namespace std;

/*
###
hash table
###
*/

class hashTable
{
    // node for linked lists
    struct node
    {
        int key;
        node* next;
        node(int x, node* t): key{x}, next{t}{}
    };
    typedef node* link;

    // holding buckets of linked lists
    // initialized during constructor with bucket size
    link* buckets;
    int N; // number of elements in the  hashtable
    int bucketSize = 5; // size of buckets
    int M; // number of buckets

    link searchHT(link h, int key)
    {
        if(h==0) return NULL;
        if(h->key == key) return h;
        return searchHT(h->next, key);
    };

    // Hash function to allocate buckets
    inline int hash(int key){ return key % M; }

    void insertHT(int key)
    {
        int i = hash(key);

        // insert item at the head of the linked list
        buckets[i] = new node(key, buckets[i]);
        N++;
    }

    void removeHT(int key)
    {
        link r = searchHT(buckets[hash(key)], key);
        if(r->key != -1) {
            delete r; // breaks the chain need r->prev to remove
        }
    }

    void printBucket(link x)
    {
        while(x->next != 0)
        {
            cout << x->key << " ";
            x = x->next;
        }
    }

public:
    hashTable(int maxN): N{0}, M{maxN/bucketSize}
    {
        buckets = new link[M];

        // Initialize buckets to 0
        for(int i=0; i<M; i++)
            buckets[i] = 0;
    }

    int size() { return N; }

    int search(int key)
    {
        link r = searchHT(buckets[hash(key)], key);
        if(r) return r->key; 
        else return -1;
    }

    void insert(int key){ insertHT(key); }

    void remove(int key) { removeHT(key); }

    void printAll()
    {
        for(int i=0; i<M; i++)
            printBucket(buckets[i]);
        cout << endl;
        return;    
    }
};

int main()
{

    /*
    ###
    hash table
    ###
    */

    // Max hashTable size
    int N = 100;
    hashTable ht(N);

    for(int i=0; i<N; i++)
        ht.insert(rand() % 100000);

    cout << "Hash Table Size: " << ht.size() << endl;
    ht.printAll();

    // find element
    int search = ht.search(95060);
    if(search != -1) cout << "Found: " << search << endl;
    else cout << "Not found...\n";

    /*
    ###
    STL unordered_set
    ###
    */
    unordered_set<int> us;
    for(int i=0; i<N; i++)
        us.insert(rand() % 100000);
    
    cout << "Unordered Set Size: " << us.size() << endl;
    for(int elem : us) cout << elem << " ";
    cout << endl;

    // find element
    unordered_set<int>::iterator iter  = us.find(31011);
    if(iter  != us.end()) cout << "Found: " << *iter << endl;
    else cout << "Not found...\n";

    // remove element
    us.erase(31011);
    iter  = us.find(31011);
    if(iter  != us.end()) cout << "Found: " << *iter << endl;
    else cout << "Not found...\n";


    return 0;
}