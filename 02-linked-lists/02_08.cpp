/*
###
Question 2.8: Given a circular linked list, implement an algorithm that returns
the node at the beginning of the loop

Description:

Example:
Input: A->B->C->D->E->C [the same C as earlier]
Output C

Hint:
Circula linked list - A (corrupt) linked list in which a node's next pointer
points to an earlier node, so as to make a loop in the linked list

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

int main()
{

  // creating first list
  link head = new node(0, 0);
  link t = head;
  link intersect;
  for(int i=1; i<10; i++)
  {
    t = (t->next = new node(i, 0));
    if(i == 5) intersect = t;
  }
  // creating circular (corrupt) list
  t->next = intersect;

  // slow runner + fast runnter
  link slow = head->next;
  link fast = head->next->next;
  int cnt = 1;
  while(slow != 0 && fast != 0)
  {
    cout << slow << " " << fast << endl;
    if(slow == fast) break;
    cnt++;
    slow = slow->next;
    fast = fast->next->next;
  }
  cout << "cnt: " << cnt << endl;

  slow = head;
  for(int i=0; i<cnt; i++)
  {
    slow = slow->next;
    fast = fast->next;
  }
  cout << (slow==fast) << endl;
  cout << slow->item << endl;

  //printList(head);

  return 0;
}
