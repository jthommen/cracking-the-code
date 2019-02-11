/*
###
Question 3.3: Stack of Plates

Description:
Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous
stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
SetOfStacks should be composed of several stacks and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is pop() should return the same values as it
would if there were just a single stack).

Follow-up: Implement a function popAt(int index) which performs a pop operation on a
specific sub-stack.


*/
#include<iostream>
#include<vector>
#include "../lib/stack_array.cpp"
using namespace std;

template<typename T>
class SetOfStacks
{
private:
    int hlimit; // max height of a stack
    int nlimit; // max number of stacks
    vector<Stack<T>*> stacks; // pointer to stacks
    int active; // Number of active stack
    int elems; // Total elements in the stacks
public:
    SetOfStacks(int n, int l): hlimit{l}, nlimit{n}, active{0}, elems{0}
    {
        stacks.push_back(new Stack<T>(hlimit));
    }
    int setSize() { return active+1; }
    int elemSize() { return elems; }
    void push(T& t)
    {
        // get active stack
        // check if stack is full
        if(stacks[active]->size() >= hlimit)
        {
            // check if max stacks is reached
            if(stacks.size() < nlimit)
            {
                // create new stack
                stacks.push_back(new Stack<T>(hlimit));
                active++;
            }
            else
            {
                throw out_of_range("max limit reached");
            }
        }
        // push onto active stack
        elems++;
        stacks[active]->push(t);
    }
    T pop()
    {
        if(stacks[active]->size() < 1)
        {
            delete stacks[active--];
        }
        elems--;
        return stacks[active]->pop();
    }

    // Follow up
    T popAt(int i)
    {
        if(i > stacks.size()-1) throw out_of_range("No stack with this index");
        if(stacks[i]->size() < 1) throw out_of_range("Empty stack");
        elems--;
        return stacks[i]->pop();
    }
};


int main()
{
    SetOfStacks<int> stacks(3, 10);

    for(int i=0; i<15; i++) stacks.push(i);
    cout << "Active Stacks: " << stacks.setSize() << endl;
    cout << "Number of elements: " << stacks.elemSize() << endl;

    cout << "Poped at Index: " << stacks.popAt(0) << endl;
    cout << "Number of elements: " << stacks.elemSize() << endl;

    
    int size = stacks.elemSize();
    for(int i=0; i<size; i++) cout << stacks.pop() << endl;
    cout << "Active Stacks: " << stacks.setSize() << endl;
    cout << "Number of elements: " << stacks.elemSize() << endl;


}
