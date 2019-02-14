/*
###
Playing with stacks
###

Definition:
Stack - An abstract data structure that comprises two basic operations: insert (push) a
new item on top of the stack and remove (pop) the item off the stack that was most
recently inserted. Here are implementations via vectors.
STL stack - Adaptor on a container, using deque per default (deque is a T** of vectors).
https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container

ADT Properties:
Insert: O(1) on top
Search: -
Remove: O(1) top element
Select: - 
Sort:  -
Join:  O(N) by inserting


*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
###
Stack
###
*/

class vectorStack
{
    vector<int> s;
public:
    int size() { return s.size(); }
    int empty() { return s.empty(); }
    void push(int t) { s.push_back(t); }
    void pop()
    {
        if(empty()) throw out_of_range("underflow");
        s.pop_back();
    }
    int peek()
    { 
        if(empty()) throw out_of_range("underflow");
        return s.back();
    }
};



int main()
{

    /*
    ###
    Stack
    ###
    */

    // creating empty structure (declaration)
    vectorStack vs;

    // pushing elements on the stack
    for(int i=0; i<10; i++)
        vs.push(i);

    // peeking and popping until empty
    while(!vs.empty())
    {
        cout << vs.peek() << " ";
        vs.pop();
    }
    cout << endl;

    /*
    ###
    STL stack
    ###
    */
    stack<int> s;

    for(int i=0; i<10; i++)
        s.push(i);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;


}