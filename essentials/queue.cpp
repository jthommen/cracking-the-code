/*
###
Playing with Queues
###

Definition:
Queue - Data structure only allowing insertion at the end and retrieval at
the front.
STL queue - Adaptor on a container, using deque per default (deque is a
T** of vectors).
https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container

ADT Properties:
Insert: O(1) on the bottom
Search: -
Remove: O(1) top element
Select: -
Sort:  -
Join:  O(N) by inserting

*/

#include<iostream>
#include<queue>
using namespace std;

/*
###
Queue
###
*/

class queueArray
{
    int* q;
    int N;
    int head;
    int tail;

public:
    queueArray(int maxN): q{new int[maxN+1]}, N{maxN+1}, tail{0}
    { head = N; }

    // full if head equals tail
    bool empty() const { return head % N == tail; }

    void put(int x)
    {
        // insert element, increment tail
        q[tail++] = x;
        tail = tail % N;
    }

    int get()
    {
        // wraps around head to first element again
        // returns 0 if head is 0
        head = head % N;

        // return first inserted element
        return q[head++];
    }

    void printStatus()
    {
        cout << "Head: " << head << endl;
        cout << "Tail: " << tail << endl;
        cout << "Empty: " << empty() << endl;
    }

};

int main()
{

    /*
    ###
    Queue
    ###
    */

    queueArray qa(3);

    for(int i=0; i<3; i++)
        qa.put(i);

    for(int i=0; i<3; i++)
        cout << qa.get() << " ";
    cout << endl;

    /*
    ###
    STL queue
    ###
    */

    queue<int> q;
    for(int i=0; i<3; i++)
        q.push(i);

    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "size: " << q.size() << endl;

    for(int i=0; i<3; i++)
    {
        cout << q.back() << " " << q.front() << endl;
        q.pop();
    }
    cout << "size: " << q.size() << endl;
}
