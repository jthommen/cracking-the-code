/*
###
Playing with binary search (array)
###

Properties:
Sort: 
- Worst case: log N
- Best case: 1
- Average case: log N 
- Worst case space: 1

*/
#include<iostream>
using namespace std;


int binarySearch(int a[], int v, int l, int r)
{
    while(r >= l)
    {
        int m = (l+r)/2;
        if(v == a[m]) return m;
        if(v < a[m]) r = m-1; else l = m+1;
    }
    return -1;
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
        a[i] = i;

    cout << "Sorted Array:\n";
    printArray(a, 10);

    cout << "Finding element 4: " << binarySearch(a, 4, 0, 9) << endl;

}
