/*
###
Question 1.6: String Compression
###

Description:
Implement a method to perform basic string compression
using the counts of repeated characters.
If the compressed string would not become smaller than
the original string, your method should return the original
string. You can assume the string has only uppercase and
lowercase letters (a-z).


Example:
Input: aabcccccaaa
Output: a2b1c5a3

Hint: 


Runtime:
Str concat... = O(k*n^2)

*/

#include<iostream>
#include<string>
using namespace std;

string compress(string& A)
{
    string B = "";

    // Iterate over characters
    // replace repeated characters with occurences
    // check size with original string
    // return compressed string

    char c = A[0];
    int cnt = 1;
    for(int i=1; i<=A.length(); i++)
    {
        if(A[i] == c) cnt++;
        else
        {
            B += c;
            B += to_string(cnt);
            c = A[i];
            cnt = 1;
        }

    }

    cout << "Size of A==" << A.size() << endl;
    cout << "Size of B==" << B.size() << endl;

    if(sizeof(A) >= sizeof(B)) { return B;}

    return A;
}

int main()
{

    string A = "aabcccccaaa";
    string B = "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccdddddddddddddddddddddddddeeeeeeeeeeeeeeee"
    "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccdddddddddddddddddddddddddeeeeeeeeeeeeeeee"
    "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccdddddddddddddddddddddddddeeeeeeeeeeeeeeee"
    "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccdddddddddddddddddddddddddeeeeeeeeeeeeeeee"
    "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccdddddddddddddddddddddddddeeeeeeeeeeeeeeee"
    "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccdddddddddddddddddddddddddeeeeeeeeeeeeeeee";

    cout << A << endl;
    cout << compress(A) << endl;
    
    cout << B << endl;
    cout << compress(B) << endl;

}

// Try 1: Very complicated to set the iterator right with in-place replacements
/*
string compress(string& A)
{
    string B = A;

    // Iterate over characters
    // replace repeated characters with occurences
    // check size with original string
    // return compressed string

    char c = B[0];
    int cnt = 1;
    for(int i=1; i<B.length(); i++)
    {
        cout << "---\n";
        cout << "[" << i << "]==" << B[i] << endl;
        cout << "cnt==" << cnt << endl;
        cout << B << endl;
        
        if(B[i] == c) cnt++;
        else
        {
            if(cnt == 1)
            {
                c = B[i];
                B.insert(i, to_string(cnt));
            }
            else
            {
                B.replace(i-(cnt-1), cnt-1, to_string(cnt));
                c = B[i];
                cnt = 1;
            }
        }

    }

    return B;
}
*/
