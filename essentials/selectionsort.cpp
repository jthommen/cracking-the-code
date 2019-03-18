/*
###
Playing with Selection Sort (array)
###

Properties:
Sort:
- Worst case: N^2
- Best case: N^2
- Average case: N^2
- Worst case space: 1
*/

#include<iostream>
using namespace std;

void exch(int& A, int& B)
{
  int t = A;
  A = B;
  B = t;
}

void selectionSort(int a[], int l, int r)
{
    // iterate through elements
    for(int i=l; i<r; i++)
    {
        int min = i;

        // compare each element forward
        for(int j=i+1; j<=r; j++)
            // udpate minimum
            if(a[j] < a[min]) min = j;
        // exchange minimum element
        exch(a[i], a[min]);
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
    selectionSort(a, 0, 9);

    cout << "Sorted:\n";
    printArray(a, 10);
}
