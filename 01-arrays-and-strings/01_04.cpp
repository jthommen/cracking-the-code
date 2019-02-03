/*
###
Question 1.4: Palindrome Permutation
###

Description:
Given a string, write a funtion to check if it is a permutation
of a palindrome. The palindrome does not need to be limited to
just dictionary words.

Example:
Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)

Hint: 
Palindrome - A word or phrase that is the same forwards and backwards.
Permutation - Rearrangement of letters.

Runtime:
O(N)

*/

#include<iostream>
#include<map>
#include<string>
using namespace std;


bool isPalindrome(string& A)
// Palindrome when: all letter even number
// except 1 if word length odd
{  
    map<char, int> lc;
    int length = 0;
    bool length_even;
    bool found_odd = false;

    // Building a map
    for(auto c : A)
    {
        if(c == ' ') continue;
        lc[tolower(c)]++;
        length++;
    }

    length_even = length%2==0;

    /*
    // Debug: Print out maps
    for(auto it = lc.begin(); it != lc.end(); it++)
        cout << it->first << ": " << it->second << endl;
    */

    // If all letter count are divisible by 2 & word length even = palindrome
    for(auto it = lc.begin(); it != lc.end(); it++)
        // If not all dividable by two, 1 odd is allowed if word length is odd
        if(it->second%2!=0)
            if(!length_even)
                // There was already an odd one, return false
                if(!found_odd) found_odd = true;
                else return false;
            else return false;
    
    return true;
}


int main()
{

    string A = "Tact Coa";
    string B = "Tact Com";
    string C = "Anna";
    string D = "Baa raab";

    // Questions:
    // - Whitespace?
    // - Case sensitive?
    // - Letters occure more than one pair? E.g. Baa raab

    isPalindrome(A) ? cout << "True\n" : cout << "False\n";
    isPalindrome(B) ? cout << "True\n" : cout << "False\n";
    isPalindrome(C) ? cout << "True\n" : cout << "False\n";
    isPalindrome(D) ? cout << "True\n" : cout << "False\n";

    return 0;

}