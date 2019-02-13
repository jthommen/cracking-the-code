/*
###
Question 2.6: Palindrome
###

Description:
Implement a function to check if a linked list is
a palindrome.

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

link reverse(link t)
{
  link p = 0; // already processed
  link u = t; // part unseen
  link temp; // temp link

  while(u != 0)
  {
    temp = u->next; // save step ahead
    u->next = p; // reverse link
    p = u; // update processed part
    u = temp; // update unseen part
  }
  return p;

}

link copyList(link t)
{
  link head = new node(t->item, 0);
  link p = head;
  t = t->next;
  while(t != 0)
  {
    p = (p->next = new node(t->item, 0));
    t = t->next;
  }

  cout << "Copy function: ";
  printList(head);
  return head;
}

bool isPalindrome(link t)
{
  link r = copyList(t);
  cout << "copied: ";
  printList(r);

  r = reverse(r);

  cout << "reversed: ";
  printList(r);

  // compare
  while(t != 0 || r != 0 )
  {
    cout << t->item << " = " << r->item << endl;
    if(t->item != r->item) return false;
    t = t->next;
    r = r->next;
  }
  return true;

}

int main()
{
  int N = 7;
  int seed[7] = {1,2,3,4,3,2,1};

  link head = new node(seed[0],0);
  link t = head;
  for(int i=1; i<N; i++)
    t = (t->next = new node(seed[i], 0));

  printList(head);
  isPalindrome(head) ? cout << "True\n" : cout << "False\n";

  return 0;
}
