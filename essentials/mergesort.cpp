/*
###
Playing with mergesort(list)
###

Definition:
mergesort - Divide (combine) and conquer sorting algorithm
STL merge - For merging two containers in sorted fashion

Properties:
Sort: 
- Worst case: N log N
- Average case: N log N
- Stack size: worst case N

*/

#include<algorithm>
#include<list>
#include<iostream>
using namespace std;

/*
###
Mergesort
###
*/

struct node
{
    int val;
    node* next;
    node(int x, node* t): val{x}, next{t}{ }
};

typedef node* link;

link merge(link a, link b)
{
    link head = new node(0,0);
    link c = head;

    while( a != 0 && b != 0)
    {
        // a is smaller, add a
        if(a->val < b->val)
        {
            c->next = a;
            c = a;
            a = a->next;
        }
        // b is smaller, add b
        else
        {
            c->next = b;
            c = b;
            b = b->next;
        }
    }

    // Add final element, depending on which list terminated the loop
    c->next = (a==0) ? b : a;

    return head->next;
    
}

link mergesort(link c)
{
    if(c == 0 || c->next == 0) return c;

    // determining the middle link
    link a = c;
    link b = c->next;

    while( b != 0 && b->next != 0)
    {
        c = c->next;
        b = b->next->next;
    }

    // middle
    b = c->next;
    c->next = 0; // reset c
    merge(mergesort(a), mergesort(b));
}

void printList(link t)
// Prints list data members
{
    t = t->next;
    while(t != 0)
    {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{

    /*
    ###
    Mergesort
    ###
    */
    int N = 10;

    link a = new node(0,0);
    link t = a;

    for(int i=0; i<N; i++)
        t = (t->next = new node(rand() % 100, 0));

    printList(a);

    mergesort(a);
    printList(a);

    /*
    ###
    STL merge
    ###
    */

    list<int> l1 = {2,4,6,8};
    list<int> l2 = {1,3,5,7};

    l1.merge(l2);
    
    for(auto elem : l1) cout << elem << " ";
    cout << endl;

}
