/*
###
Playing with bubble sort (array)
###

Properties:
Sort: 
- Worst case: n^2
- Best case: n
- Average case: n^2
- Worst case space: 1
- stable

*/
#include<iostream>
using namespace std;


void exch(int& i, int& j)
{
    int t = i;
    i = j;
    j = t;
}

void compexch(int& a, int& b)
{
    if(b < a) exch(a, b);
}

void bubbleSort(int a[], int l, int r)
{
    for(int i=l; i<r; i++)
        for(int j=r; j>i; j--)
            compexch(a[j-1], a[j]);
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
    bubbleSort(a, 0, 9);

    cout << "Sorted:\n";
    printArray(a, 10);
}
