/*
###
Question 2.7: Intersection

Description:
Given two (singly) linked lists, determine if the two lists intersect. Return
the intersecting node. Note that the intersection is defined based on reference,
not value. That is, if the kth node of the first linked list is the exact same
node (by reference) as the jth node of the second linked list, then they are
intersecting.

Example:

Hint:

Runtime:

*/
#include<iostream>
using namespace std;

struct node
{
  int item;
  node* next;
  node(int x, node* n): item{x}, next{n} { };
};

typedef node* link;

void printList(link t)
{
  while(t != 0)
  {
    cout << t->item << " ";
    t = t->next;
  }
  cout << endl;
}

link intersect(link l1, link l2)
{
  link l2head = l2;
  while(l1 != 0)
  {
    while(l2 != 0)
    {
      if(l1 == l2) return l1;
      l2 = l2->next;
    }
    l2 = l2head;
    l1 = l1->next;
  }

  return 0;
}

int main()
{

  // creating first list
  link head1 = new node(0, 0);
  link t1 = head1;
  for(int i=1; i<6; i++)
    t1 = (t1->next = new node(i, 0));

  // creating second list
  link head2 = new node(6, 0);
  link t2 = head2;
  t2 = (t2->next = new node(7,0));
  //t2 = (t2->next = new node(8,0));

  // linking second list to first list
  link con = head1;
  for(int i=0; i<3; i++) con = con->next;

  // Toggle intersection
  t2->next = con;

  cout << "First list: ";
  printList(head1);
  cout << "Second list: ";
  printList(head2);

  cout << "Result: ";
  con = intersect(head1, head2);
  if(con)
  {
    cout << "True! Connector: " << con->item << endl;
  }
  else cout << "False! No intersection.\n";

  return 0;
}
