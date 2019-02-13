/*
###
Question 3.2: Stack Min
###

Description:
How would you design a stack which, in addition to push and pop,
has a function min, which returns the minimum element? Push, pop and min should
all operate in O(1) time.


*/
#include<cmath>
#include<limits>
#include<iostream>
#include "../lib/stack_vector.cpp"
using namespace std;


struct NodeWithMin
{
  int value;
  int min;
  NodeWithMin(int v, int m): value{v}, min{m} {};
};

ostream& operator<<(ostream& os, const NodeWithMin& n)
{
  return os << n.value << endl;
}

class StackWithMin : public Stack<NodeWithMin>
{
public:
  void push(int value)
  {
    int newMin = std::min(value, min());
    Stack<NodeWithMin>::push(NodeWithMin(value, newMin));
  }

  int min()
  {
    if(empty()) return numeric_limits<int>::max();
    else return peek().min;
  }
};


int main()
{
  
  // Simple pushdown stack implemented with a vector
  int N = 30;
  StackWithMin s;

  for(int i=1; i<N; i++) { s.push(i); }

  cout << "Size: " << s.size() << endl;
  cout << "Min: " << s.min() << endl;
  cout << "Empty: " << s.empty() << endl;
  cout << "Peek: " << s.peek();
  

}
