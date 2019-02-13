/*
###
Question 1.9: String Rotation
###

Description:
Assume you have a method isSubstring which checks if one
word is a substring of another.
Given two strings, s1 and s2, write code to check if s2
is a rotation of s1 using only one call to isSubstring.

Example:
waterbottle is a rotation of erbottlewat

Hint:

Runtime:

*/

#include<iostream>
#include<string>
using namespace std;


bool isRotation(string A, string B)
{
    // check that string are same length and not empty
    if(A.length() != B.length() || A.length() == 0 || B.length() == 0)
        return false;

    // double A
    string AA = A + A;
    
    // test for substring of B in AA
    // If it's a substring rotation, the whole must be in AA
    return isSubstring(AA, B);
}

int main()
{

   return 0;

}