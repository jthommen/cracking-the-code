#include<iostream>
using namespace std;


template<typename T>
class Stack
{
private:
    struct node
    {
        T value;
        node* next;
        node* prev;
        node(T v, node* n): value{v}, next{n} {}
    };
    typedef node* link;
    link head;
public:
    Stack(): head{0} {}
    void push(const T&);
    T pop();
    T peek() { return head->value; }
    bool isEmpty() { return head==0; }
};

// push to front
template<typename T>
void Stack<T>::push(const T& t)
{
    head = new node(t, head);
}

// pop from front
template<typename T>
T Stack<T>::pop()
{
    T elem = head->value; 
    link t = head->next;
    delete head;
    head = t;
    return elem;
}