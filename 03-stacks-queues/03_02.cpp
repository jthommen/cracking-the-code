/*
###
Question 3.2: Stack Min

Description:
How would you design a stack which, in addition to push and pop,
has a function min, which returns the minimum element? Push, pop and min should
all operate in O(1) time.




*/

#include<iostream>
using namespace std;

struct Elem
{
  int data;
  Elem* min;
  Elem(int d=0): data{d}, min{0} {}
};

class Stack
{
  private:
    Elem** s; // head pointer
    int N; // elems in stack
    Elem* minimum;
  public:
    Stack(int maxN): s{new Elem*[maxN]}, N{0}, minimum{0} {}
    int empty() const { return N==0; }
    void push(Elem* item)
    {
      // Put item onto stack
      s[N++] = item;

      // Check if min is set
      if(minimum == 0) minimum = item;

      // Check if new element is the smallest
      if(item->data < minimum->data)
      {
          minimum = item;
          item->min = item;
      }
      // No condition, set minimum to set one
      else item->min = minimum;
    }

    Elem* pop()
    {
      Elem* e = s[--N];
      if(e == minimum)
      {
        if(N-1 == 0) minimum = 0;
        else minimum = s[--N]->min;
      }
      cout << "N==" << N << endl;
      return e;
    }

    Elem* min()
    {
      return minimum;
    }

};

class minStack : public Stack
{

};

int main()
{

  // Simple pushdown stack implemented with an array
  int N = 30;
  Stack s(N);

  for(int i=0; i<N; i++) s.push(new Elem(i));
  for(int i=0; i<N; i++)
   cout << s.pop()->data << " ";
  cout << endl;


  //cout << s.pop()->data << endl;


  s.empty() ? cout << "True\n" : cout << "False\n";


}
