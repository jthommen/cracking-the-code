/*
###
Playing with quicksort (array)
###

Definition:
quicksort - (sRecursive) Sorting algorithm using random partitioning, requires random element access.
C qsort - C quicksort implementation for fast, unstable sorting
STL sort  - very fast sorting with introsort (hybrid algorithm: quicksort, heapsort & insertion sort)

Properties:
Sort: 
- Worst case: N^2/2 (sorted or reverse order)
- Average case: 2N ln N
- In place, unstable
- Stack size proportional to lg N for random files
- Make it faster with hybrid for small files (e.g. insertion sort)


*/
#include<algorithm>
#include<iostream>
using namespace std;

/*
###
Quicksort
###
*/

void printArray(int a[], int l)
{
    for(int i=0; i<l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

}

// Exchange function by reference
void exch(int& i, int& j)
{
    int t = i;
    i = j;
    j = t;
}

int partition(int a[], int l, int r)
{
    int i = l-1;
    int j = r;
    int v = a[r]; // arbitrary choice of partition element

    printArray(a, r-l+1);
    cout << "Partition element: " << a[r] << ", left: " << a[l] << ", right: " << a[r] << endl;
    while(true)
    {
        // scan from the left until we find an element
        // greater than the partition element
        while(a[++i] < v);

        // scan from the right until we find an element
        // smaller than the partition element
        while(v < a[--j])
            if(j == l) break; // we went all the way left, stop.

        // if left pointer equals or is bigger than right pointer
        // (pointer cross) we break the main loop
        if (i >= j){
            cout << "Break loop: a[i]==" << a[i] << " >= a[j]==" << a[j] << endl;
            break;
        }
            

        // else we keep going exchanging out of place elems between
        // partition sizes
        cout << "Exchanging " << a[i] << " with " << a[j] << endl;
        exch(a[i], a[j]);
    }

    // exchange partition element with the leftmost element of the right subfile
    // element pointed to by left pointer
    cout << "Final partition element exchange: " << a[i] << " with " << a[r] << endl;
    exch(a[i], a[r]);
    cout << "New partition element: " << a[i] << endl;
    return i;
}

void quicksort(int a[], int l, int r)
{
    if(r <= l) return; // base case
    int i = partition(a, l, r); // create partition
    quicksort(a, l, i-1); // recurse
    quicksort(a, i+1, r);
}

int main()
{

    /*
    ###
    Quicksort
    ###
    */
    int a[10];
    for(int i=0; i<10; i++)
        a[i] = rand() % 100;

    cout << "Unsorted:\n";
    printArray(a, 10);

    quicksort(a, 0, 9);

    cout << "Sorted:\n";
    printArray(a, 10);

    /*
    ###
    STL sort
    ###
    */

    cout << "STL sort:\n";
    int a1[10];
    for(int i=0; i<10; i++)
        a1[i] = rand() % 100;
    
    printArray(a1, 10);
    sort(a1, a1+10);
    printArray(a1, 10);

}