/*
###
Playing with Arrays & Vectors
###

Definition:
array - contiguous storage for a predefined amount of data with a specified type,
is not aware of it's own size and doesn't check bounds. Direct correspondence with
memory system.
STL vector - dynamic array with the ability to resize itself

ADT Properties:
Insert: O(N) for N elements
Search:
Remove:
Select: O(1) selection by index
Sort:
Join:


*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    /*
    ###
    Arrays
    ###
    */

    // Declares array holding 5 ints
    int a[5];
    cout << a[0] << endl; // prints garbage value

    // Arrays can't be assigned after its declaration
    // a = {1,3,5,7,9}; // error

    // Either initialize at declaration
    int a1[5] = {1,3,5,7,9};
    cout << a1[0] << endl;

    // Or initialize each element using a loop
    for(int i=0; i<5; i++) a[i] = 1;
    cout << a[0] << endl;


    /*
    ###
    Vectors
    ###
    */

    // declars a vector holding ints
    vector<int> v; 
    //cout << v[0] << endl; // segmentation fault, not space allocated at pos 0

    // initialization with initializer list
    v = {1,3,5,7,9};
    cout << v[0] << endl;

    // By using push_back()
    vector<int> v1;
    for(int i=0; i<5; i++)
        v1.push_back(i);
    cout << v1[3] << endl;

    // Replacing values, but index must exist already by allocation or push_back
    for(int i=0; i<5; i++)
        v1[i] = 10;
    cout << v1[2] << endl;

    // Index start at 0 for both data structures otherwise, out of range error occurs
    vector<int> v2;
    // Generates elements 1-5 at index 0-4
    for(int i=1; i<=5; i++)
        v2.push_back(i);
    cout << v2[4] << endl; // prints 5

    // arrays or vectors can't have "holes"
}