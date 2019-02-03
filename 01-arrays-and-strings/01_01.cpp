/*
###
Question 1.1: Is Unique
###

Description:
Implement an algorithm to determine if a string has all unique characters.
What if yo cannot use additional data structures?
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

bool isUnique(string& A)
{
    set<char> chars;

    // Iterate over characters
    for(auto c : A)
    {   
        // If not there already, insert into set, otherwise not unique
        if(chars.find(c) == chars.end())
        {
            chars.insert(c);
        } else return false;
    }
    return true;
}

int main()
{


    // Question to ask:
    // - Character set? ASCII or UTF-8?
    // - Case sensitive?
    // - Whitespace relevant?
    string A = "Hello";
    string B = "abc";
    string C = "nice";
    string D = "None";
    
    (isUnique(A)) ? cout << "True\n" : cout << "False\n";
    (isUnique(B)) ? cout << "True\n" : cout << "False\n";
    (isUnique(C)) ? cout << "True\n" : cout << "False\n";
    (isUnique(D)) ? cout << "True\n" : cout << "False\n";

    return 0;

}