/*
###
Question 2.3: Delete Middle Node

Description:
Implement an algorithm to delete a node in the middle
(i.e., any  node but the first and last node, not necessarily
the exact middle) of a singly linked list, given only access
to that node.

Example:
Input: the node c from the linekd list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks lik
a->b->d->e->f

Hint:

Runtime:
O(N)

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

void remove(link t, int N)
{
    link x;
    while(t != 0)
    {
        if(t->item == N)
        {
            x->next = t->next;
            delete t;
            return;
        }
        x = t;
        t = t->next;
    }
    return;
}

int main()
{

    // Problem: Can't go back in singly linked list
    // Have to do sequential search for item

    // Interviewer question:
    // - Do I have access to the head node?
    // - Is the element to be deleted the one that was given to me?

    // Important: Last element can't be deleted that way

    // create example list
    int N = 15; // list length
    link a = new node(0,0); // create head ndoe
    link t = a; // running pointer

    for(int i=0; i<N; i++) t = (t->next = new node(rand() % 1000, 0));
    t = a->next;

    cout << "Unsorted list: ";
    printList(t);

    // delete middle item
    int middle = 335;
    remove(a, middle);

    cout << "Element removed:";
    printList(t);


    return 0;

}
