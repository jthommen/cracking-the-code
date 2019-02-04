/*
###
Question 1.9: Remove Dups

Description:
Write code to remove duplicates from an unsorted linked list.
Follow-up: How would you solve this problem, if a temporary
buffer is not allowed?

Example:


Hint:

Runtime:

*/

#include<iostream>
using namespace std;

// Merge sort for singly linked list
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
    // delete x ? Memory leak?
    return t;
}

int main()
{
    int N = 10;

    // Create head node pointing to list
    node head(0, 0);

    // creating link (pointer) to head node
    link a = &head;

    // creating another link to head
    link t = a;

    // Create list of N elements
    int seed[N] = {1,2,3,1,2,3,1,2,3,4};

    for(int i=0; i<N; i++)
        // shorthand for create link, assign it to the 'old' t pointer
        // then update t to 'new' created node
        t = (t->next = new node(seed[i], 0));

    cout << "Unsorted List: ";
    printList(a);  
    
    // sort list
    a = mergesort(a);
    cout << "Sorted List: ";
    printList(a);

    // remove duplicates
    t = a->next;
    while(t != 0 && t->next != 0)
    {
        if(t->item == t->next->item)
            t = removeNode(t);
        else t = t->next;
    }

    cout << "Duplicates removed: ";
    printList(a);

    return 0;

}