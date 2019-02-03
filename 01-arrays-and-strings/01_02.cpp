/*
###
Question 1.2: Check Permutation
###

Description:
Given two strings, write a method to decide if one is a
permutation of the other.

Hint: 
Permutation = An arrangement number or order of a list
(same elements, different order).

Runtime:
- string of length n has n! permutations
- comparing every character in A with B takes A*B steps
- sorting A & B and then comparing them in order takes A log A + B log B
*/

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool checkPermutation1(string A, string B)
// If it has the same characters = permutation
// runtime:  O(N^2) if length of A==B
{
    // Save characters in map (might have duplicate characters)
    vector<char> a;
    for(char c : A) a.push_back(c);

    // Check if character of B is in A
    for(char c : B)
    {

        // Linear search, search miss O(N)
        auto pos = find(a.begin(), a.end(), c);

        // not found -> no permutation
        if(pos == a.end()) return false;
        // found -> erase to account for duplicates
        a.erase(pos);
    }
    return true;
}

bool checkPermutation2(string A, string B)
// sort both strings, compare
// runtime: O(n log n) if length of A==B
{
    if(A.length() != B.length()) return false;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(A==B) return true;
    return false;
}


int main()
{
    string A = "Hello";
    string B = "elHlo";

    if(checkPermutation2(A, B)) cout << "True\n";
    else cout << "False\n";

    return 0;

}