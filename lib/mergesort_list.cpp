/*
###
Sorting: Merge sort (Singly linked list)
###

Description:
Recursive version of merge sort,
implemented with a singly linked list.


*/

#include<iostream>
using namespace std;

// simple structure holding int & link to next node
struct node
{
    int item;
    node* next;
    node(int x, node* t): item{x}, next{t} { };
};

typedef node* link;


// merging two lists pointed to by a & b
link merge(link a, link b)
{
    // Create dummy node to insert in order
    node dummy(0, 0);
    link head = &dummy;
    link c = head;

    // Keep adding pairs from the lists
    while( (a != 0) && (b != 0))
    {
        if(a->item < b->item)
        {
            c->next = a; // add a to list
            c = a; // udpate head of list pointer
            a = a->next; // advance list a
        }
        else
        {
            c->next = b; // add b to list
            c = b; // udpate head of list pointer
            b = b->next; // advance list b
        }
    }

    // Update final element dependin on which list terminated loop
    c->next = (a==0) ? b : a;

    // return pointer to first element after dummy node
    return head->next;
}

// Expects 0 terminated list
link mergesort(link c)
{
    // c is the end of the list, return
    if(c == 0 || c->next == 0) return c;


    link a = c; // first half
    link b = c->next;

    //cout << "c: " << c->item << endl;

    // while we're not at the end, continue splitting
    // faster runne is break condition, two conditions, since two steps
    while( (b != 0) && (b->next != 0))
    {
        
        //cout << "c->next: " << c->next->item << endl;
        //cout << "b->next->next: " <<  b->next->next->item << endl;
        c = c->next; // go over list one step
        b = b->next->next; // go over list two steps at a time (Runner technique)
    }

    
    //cout << "Final b: " << b->item << endl;
    //cout << "Final c: " << c->item << endl;
    

    // Set b to middle of list
    // since b went twice as fast as c, when b reaches the end, c is in the middle
    b = c->next;
    c->next = 0; // why?
    return merge(mergesort(a), mergesort(b));
}

void printList(link t)
// Prints list data members
{
    while(t != 0)
    {
        cout << t->item << " ";
        t = t->next;
    }
    cout << endl;
}

int length(link t)
// returns list length excl. head node
{
    int cnt=0;
    while(t->next != 0)
    {
        cnt++;
        t = t->next;
    }
    return cnt;
}

// removes the link after t
link removeNode(link t)
{
    link x = t->next;
    t->next = x->next;
    delete x;
    return t;
}

int main()
{
    int N = 15;

    // Create head node pointing to list
    node head(0, 0);

    // creating link (pointer) to head node
    link a = &head;

    // creating another link to head
    link t = a;

    // Create list of N random elements between 0 and 999
    for(int i=0; i<N; i++)
        // shorthand for create link, assign it to the 'old' t pointer
        // then update t to 'new' created node
        t = (t->next = new node(rand() % 1000, 0));

    // print list length
    cout << "List length: " << length(a) << endl;
    
    // print link
    printList(a);

    
    
    // sort list
    mergesort(a);
    cout << "List length: " << length(a) << endl;
    printList(a);

    removeNode(a);
    printList(a);

   return 0;

}
