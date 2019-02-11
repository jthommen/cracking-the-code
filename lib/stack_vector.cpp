#include<iostream>
#include<stdexcept>
#include<vector>
using namespace std;

template<typename T>
class Stack
{
private:
    vector<T> s;
public:
    int size() const { return s.size(); }
    bool empty() const { return s.empty(); }
    void push(const T&);
    T pop();
    T peek();
};

template<typename T>
void Stack<T>::push(const T& t)
{
    s.push_back(t);
}

template<typename T>
T Stack<T>::pop()
{
    if(empty())
        throw out_of_range("underflow");
    auto x = s.back(); // assign elem
    s.pop_back(); // remove elem from back
    return x;
}

template<typename T>
T Stack<T>::peek()
{
    if(empty())
        throw out_of_range("underflow");
    return s.back();
}
