/*
###
Question 2.2: Return kth to last
###

Description:
Implement an algorithm to find the kth to last element
of a singly linked list.

Example:

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




int main()
{

    // Question to interviewer: Is the list size known?

    // create example list
    int N = 15; // list length
    link a = new node(0,0); // create head ndoe
    link t = a;

    for(int i=0; i<N; i++) t = (t->next = new node(rand() % 1000, 0));

    cout << "Unsorted list: ";
    printList(a->next);

    // print range
    cout << "kth to last elements: ";
    int k = 8;
    link kth = a;
    for(int i=0; i<k; i++) kth = kth->next;
    printList(kth);

    return 0;

}