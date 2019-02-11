/*
###
Question 3.4: Queue via Stacks

Description:
Implement a MyQueue class which implements a queue using two stacks.


*/
#include<iostream>
#include<vector>
#include "../lib/stack_vector.cpp"
using namespace std;

template<typename T>
class MyQueue
{
private:
    Stack<T> s0;
    Stack<T> s1;
    Stack<T>* temp; // marks the temporary stack
    bool lastOp;
public:
    MyQueue(): temp{&s1} {}
    void push(const T&);
    T pop();
};

template<typename T>
void MyQueue<T>::push(const T& t)
{
    if(temp == &s1) s0.push(t);
    else s1.push(t);
    lastOp = true;
}

template<typename T>
T MyQueue<T>::pop()
{
    // checking which one is the temp stack
    Stack<T>& s = (temp == &s1 ? s0 : s1);
    Stack<T>& t = (temp == &s1 ? s1 : s0);

    if(!lastOp) return s.pop();

    // getting stack size to identify last elem
    int size = s.size();
    // shift all objects before last onto temp stack
    for(int i=0; i<size-1; i++)
    {
        auto elem = s.pop();
        t.push(elem);
    }
    temp = &s;
    lastOp = false;
    return s.pop();
    // switch temp stacks
    // return last item

}

int main()
{
    MyQueue<int> q;

    cout << "Fill up first, then empty: \n";
    for(int i=0; i<5; i++) q.push(i);
    for(int i=0; i<5; i++) cout << q.pop() << endl;

    cout << "Switching push and pops: \n";
    for(int i=0; i<5; i++)
    {
        q.push(i);
        cout << q.pop() << endl;
    }

}
