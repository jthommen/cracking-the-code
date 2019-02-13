/*
###
Question 2.4: Partition
###

Description:
Write code to partition a linked list around value x, such that all nodes
less than x come before all nodes greater than or equal to x. If x is contained
within the list, the values of x only need to be after the elements less than
x (see below). The partition element x can appear anywhere in the "right
partition"; it does not need to appear between the left and right partitions.

Example:
Input: 3->5->8->5->10->2->1[partition=5]
Result: 3->1->2->10->5->5->8

Hint:

Runtime:

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

// links in t after d
link insert(link t, link d)
{
  t->next = d->next;
  d->next = t;
  return t;
}

link merge(link a, link b)
{
  link t=a;
  // find end of tail
  while(t->next != 0) { t = t->next; }
  cout << "t item: " << t->item << endl;
  // insert head into end of tail

  t->next = b->next;
  delete b;

  // return pointer to tail head
  return a;

}

void printList(link t)
// Prints list data members
{
    while(t->next != 0)
    {
        cout << t->next->item << " ";
        t = t->next;
    }
    cout << endl;
}


int main()
{
  // Create source list
  int N=7;
  int seed[7] = {3,5,8,5,10,2,1};

  link a = new node(0,0); // head node
  link t = a; // running pointer
  for(int i=0; i<N; i++)
    t = (t->next = new node(seed[i], 0));
  t = a;
  printList(a);


  int p = 5;
  link head = new node(0,0);
  link tail = new node(0,0);
  link hp = head;
  link tp = tail;

  while(t->next != 0)
  {
    link temp = new node(t->next->item, 0);
    if(t->next->item < p)
    {
      tp = insert(temp, tp);
    }
    else
    {
      hp = insert(temp, hp);
    }
    t = t->next;
  }

  cout << "tail: ";
  printList(tail);

  cout << "head: ";
  printList(head);

  a = merge(tail, head);
  printList(a);

}
