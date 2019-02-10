/*
###
Question 3.1: Three in One

Description:
Describe how you could use a single array to implement three stacks.


*/

/*

  Fixed size:
  1. Could partition an array of size stack size * 3, then offset stack 2 & 3.
  2. Could interleave the stacks by granting one stack the size starting from 0
  another one the positions from 1 and the last one from 2. Increasing each
  position by three each time the stack grows.


  Flexible size:
  1. Could have the arrays flexible and shift & grow them depending on how the
  stacks grow or shrink

*/

#include<iostream>
using namespace std;

template<typename Item>
class Stack
{
  private:
    Item* s; // head pointer
    int N; // elems in stack
  public:
    Stack(int maxN): s{new Item[maxN]}, N{0} {}
    Stack(Item* sz): s{sz}, N{0} {}
    int empty() const { return N==0; }
    void push(Item item) { s[N++] = item; }
    Item pop() { return s[--N]; }

};

int main()
{

  // Simple pushdown stack implemented with an array
  int N = 30;
  Stack<int> s(N);
  for(int i=0; i<N; i++) s.push(i);
  for(int i=0; i<N; i++)
  {
    cout << s.pop() << " ";
  }
  cout << endl;
  s.empty() ? cout << "True\n" : cout << "False\n";

  // Three stacks in one array, fixed
  int multi[30];
  for(int i=0; i<30; i++) multi[i] = 0;
  int* p1 = &multi[0];
  int* p2 = &multi[10];
  int* p3 = &multi[20];
  Stack<int> s1(p1);
  Stack<int> s2(p2);
  Stack<int> s3(p3);

  for(int i=0; i<5; i++) s1.push(1);
  for(int i=0; i<7; i++) s2.push(2);
  for(int i=0; i<3; i++) s3.push(3);

  for(int i=0; i<N; i++)
    cout << multi[i] << " ";
  cout << endl;

  // One array, three variable size stacks
  // Too complex for an interview
  // have circular array
  // shift around arrays by one pos while they expand and shrink


}
