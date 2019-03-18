/*
###
Playing with insertion sort (array)
###

Properties:
Sort:
- Worst case: N^2
- Best case: N
- Average case: N^2
- Worst case space: N

*/

#include<iostream>
using namespace std;

void exch(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

// if b is smaller than a, swap
void compexch(int& a, int & b)
{
    if(b < a) exch(a, b);
}

void insertionSort(int a[], int l, int r)
{
    int i;
    // put smallest element in position (sentinel)
    for(i = r; i > l; i--)
        compexch(a[i-1], a[i]);

    cout << "a[" << i << "]==" << a[i] << endl;

    // moving through elements left to right
    for(i = l+2; i <= r; i++)
    {
        int j = i;
        int v = a[i];

        // search from sorted part backwards
        // until elem is not smaller anymore
        while(v < a[j-1])
        {
            a[j] = a[j-1];
            j--;
        }
        // Found right spot insorted portion, insert
        a[j] = v;
    }
}

void printArray(int a[], int l)
{
    for(int i=0; i<l; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{

    int a[10];
    for(int i=0; i<10; i++)
        a[i] = rand() % 100;

    cout << "Unsorted:\n";
    printArray(a, 10);

    insertionSort(a, 0, 9);

    cout << "Sorted:\n";
    printArray(a, 10);
}
