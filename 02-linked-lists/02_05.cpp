/*
###
Question 2.5: Sum Lists

Description:
You have two numbers represented by a linked list, where each node contains
a single digit. The digits are stored in reverse order, such that the 1's digit
is at the head of the list. Write a function that adds the two numbers and
returns the sum as a linked list.

Example:
Input: (7->1->6) + (5->9->2)
Result: 2->1->9

Hint:

Runtime:

*/
#include<iostream>
using namespace std;

struct node
{
  int item;
  node* next;
  node(int x, node* t): item{x}, next{t} { };
};

typedef node* link;

void printList(link t)
{
  while(t->next != 0)
  {
    cout << t->next->item << " ";
    t = t->next;
  }
  cout << endl;
}

link insert(link t, link d)
{
  t->next = d->next;
  d->next = t;
  return t;
}

link sumLists(link l1, link l2)
{
  link r = new node(0,0);
  link t = r;
  int sum, carry = 0;
  while( (l1->next != 0) || (l2->next !=0) )
  {
    sum = l1->next->item + l2->next->item + carry;
    if(sum/10 > 0)
    {
      carry = 1;
      sum -=10;
    }

    link temp = new node(sum, 0);
    t = insert(temp, t);

    l1 = l1->next;
    l2 = l2->next;
  }

  return r;
}

int main()
{
  int N = 3;
  int arr1[3] = {7,1,6};
  int arr2[3] = {5,9,2};
  link l1 = new node(0,0);
  link l2 = new node(0,0);
  link t1 = l1;
  link t2 = l2;

  for(int i=0; i<N; i++)
    t1 = (t1->next = new node(arr1[i], 0));

  for(int i=0; i<N; i++)
    t2 = (t2->next = new node(arr2[i], 0));

  printList(l1);
  printList(l2);


  link r = sumLists(l1, l2);
  printList(r);

}
