/*
###
Question 1.7: Rotate Matrix
###

Description:
Given an image represented by an NxN matrix, where each pixel in the
image is 4 bytes, write a method to rotate the image by 90 degrees.
Can you do this in place?

Example:


Hint:
4 bytes = int data type
Matrix = array of arrays

Runtime:
O(N^2) best we can do for this problem

*/

#include<iostream>
#include<string>
using namespace std;

#define N 4

void rotate(int a[N][N])
{
    for(int i=0; i<N/2; i++)
    {
        for(int j=i; j < N-i-1; j++)
        {
            // Hard to get the iterators right
            // They i & j aren't fixed or rows or cols
            int temp = a[i][j];
            a[i][j] = a[N-1-j][i];
            a[N-1-j][i] = a[N-1-i][N-1-j];
            a[N-1-i][N-1-j] = a[j][N-1-i];
            a[j][N-1-i] = temp;

        }
    }
}

void printMatrix(int a[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int threeByThree[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int fourByFour[N][N] = {{1, 2, 3, 4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    printMatrix(fourByFour);
    cout << "----\n";
    rotate(fourByFour);
    printMatrix(fourByFour);

    return 0;

}