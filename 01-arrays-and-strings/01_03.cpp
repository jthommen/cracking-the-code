/*
###
Question 1.3: URLify
###

Description:
Write a method to replace all spaces in a string with '%20'.
You may assume that the string has sufficient space at the end to hold
the additional characters, and that you are given the 'true' length
of the string.

Example:
Input: "Mr John Smith ", 13
Output: "Mr%20John%20Smith"

Hint: 

Runtime:

*/

#include<iostream>
#include<string>
using namespace std;


string& URLify(string& A)
// Search for ' ', replace with '%20'
// Problem, %20 = multicharacter constant
// runtime:
{

    // Iterate over string
    for(int i=0; i<A.size(); i++)
        if(A[i] == ' ')
            A.replace(i, 1, "%20");

    return A;
}


int main()
{

    string A = "Mr John Smith";
    cout << URLify(A) << endl;

    return 0;

}