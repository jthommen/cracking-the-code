/*
###
Question 3.5: Sort Stack

Description:
Write a program to sort a stack such that the smallest items are on the top.
You can use an additional temporary stack, but you may not copy the elements into
any other data structure (such as an array). The stack supports the following operations:
push, pop, peek, and isEmpty.

Runtime:
O(N^2) time and O(N) space

*/
#include<iostream>
#include<limits>
#include "../lib/stack_list.cpp"
using namespace std;


/* Too many stacks
template<typename T>
void sort(Stack<T>& s)
{
    Stack<T> temp;
    Stack<T> sorted;

    while(!s.isEmpty())
    {
        T min=numeric_limits<T>::max();

        // find min by shifting to temp stack
        while(!s.isEmpty())
        {   
            T val = s.pop();
            if(val < min) min = val;
            temp.push(val);
        }

        // push min onto sorted stack
        sorted.push(min);

        // shift element except min back to stack
        // could implement swapping temp and real stack
        
        while(!temp.isEmpty())
        {
            T val = temp.pop();
            if(val != min) s.push(val);
        }
    }
    s = sorted; 
}
*/

template<typename T>
void sort(Stack<T>& s)
{
    // temporary stack
    Stack<T> t;

    // repeat until everything is sorted in temp stack
    while(!s.isEmpty())
    {
        // Pop of elem to sort in origin stack
        T tmp = s.pop();

        // shift elems from temp to origin stack until 
        // we find the right place for the tmp element
        while(!t.isEmpty() && t.peek() > tmp)
        {
            s.push(t.pop());
        }
        // Once the right spot is found, insert the elem
        t.push(tmp);
    }
    // Replace unsorted with sorted stack
    s = t;
}

int main()
{
    Stack<int> s;

    for(int i=0; i<15; i++) s.push(rand()%1000);
    
    sort(s);
    for(int i=0; i<15; i++) cout << s.pop() << endl;
    
}
