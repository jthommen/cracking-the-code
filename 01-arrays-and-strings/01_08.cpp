/*
###
Question 1.8: Zero Matrix

Description:
Write an algorithm such that if an element in an
MxN matrix is 0, it's entire row and column
are set to 0.

Example:


Hint:

Runtime:

*/

#include<iostream>
#include<string>
#include<tuple>
#include<vector>
using namespace std;


void setZero(vector<vector<int>>& v)
{

    // Two steps:
    // Find zero indexes
    vector<tuple<int, int>> indices;

    for(int i=0; i<v.size(); i++)
        for(int j=0; j<v[0].size(); j++)
            if(v[i][j] == 0)
            {
                indices.push_back(tuple<int, int>(i, j));
            }

    // replace 0s
    // Go through rows
    // v[0][1]
    // i = 0;
    // j = 1;
    for(int l=0; l<indices.size(); l++)
    {
    for(int k=0; k<v.size(); k++)
        v[k][get<1>(indices[l])] = 0;

    // Go through columns
    for(int k=0; k<v[0].size(); k++)
        v[get<0>(indices[l])][k] = 0;
    }
}

void printMatrix(vector<vector<int>> v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> threeByTwo = { {1, 0, 3}, {4, 5, 6} };
    vector<vector<int>> fourByThree = { {1, 2, 3, 4}, {5, 6, 7, 8}, {0, 10, 11, 12} };

    printMatrix(threeByTwo);
    cout << "----\n";
    setZero(threeByTwo);
    printMatrix(threeByTwo);


    cout << "----\n";
    printMatrix(fourByThree);
    cout << "----\n";
    setZero(fourByThree);
    printMatrix(fourByThree);

    return 0;

}