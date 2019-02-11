#include<iostream>


template<typename T>
class Stack
{
private:
    T* s; // head pointer
    int N;
public:
    Stack(int maxN): s{new T[maxN]}, N{0} {}
    void push(T& item) { s[N++] = item; }
    T pop() { return s[--N]; }
    bool empty() { return N==0; }
    int size() { return N; }
    T peek() { return s[N-1]; }
};