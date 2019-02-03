/*
###
Question 1.5: One Away
###

Description:
There are three types of edits that can be performed on strings:
insert a character, remove a character or replace a character.
Given two strings, write a function to check if they are one edit
(or zero edits away).


Example:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false

Hint: 


Runtime:


*/

#include<iostream>
#include<string>
using namespace std;


bool oneAway(string& A, string& B)
{
    // identical, return true
    if(A == B) return true;

    int la = A.length();
    int lb = B.length();

    bool change = false;

    // if same size, skip to replace
    
    if(la != lb)
    {
        
        string& longer = (la > lb) ? A : B;
        string& shorter  = (longer == A) ? B : A;

        // insert & remove are complements
        // string length differ by 1
        int j = 0;
        for(int i=0; i<shorter.length(); j++,i++)
        {
            
            if(shorter[i] != longer[j])
                if(!change)
                { j++; change = true; }
                else return false;
        }
        
        
    }
    else
    {
        // replace
        // same size, one char is different
        for(int i=0; i<la; i++)
        {
            if(A[i] != B[i])
                if(!change)
                    change=true;
                else return false;
        }
    }
    
    return true;
}

int main()
{

    string A = "pale";

    string B = "ple";
    string C = "pales";
    string D = "bale"; 
    string E = "bake";
    string F = "cake";

    oneAway(A, B) ? cout << "True\n" : cout << "False\n";
    oneAway(C, A) ? cout << "True\n" : cout << "False\n";
    oneAway(A, D) ? cout << "True\n" : cout << "False\n";
    oneAway(A, E) ? cout << "True\n" : cout << "False\n";
    oneAway(F, A) ? cout << "True\n" : cout << "False\n";
}
