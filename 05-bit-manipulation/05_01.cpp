/*
###
Question 5.1: Insertion
###

Description:
You are given two 32-bit numbers, N and M and two bit positions, i and j.
Write a method to insert M into N such that M starts at bit j and ends at bit i.
You can assume that the bits j through i have enough space to fit all of M.
That is, if M = 10011, you can assume that there are at least 5 bits between j
and i. You would not, for example, have j=3 and i=2, because M could not fully
fit between bit 3 and bit 2.

Example:
Input : N = 10000000000, M = 10011, i = 2, j = 6
Output: N = 10001001100

Hint:

Runtime:

*/

#include<bitset>
#include<iostream>
#include<string>
using namespace std;

template<typename T>
void printBinary(T n)
{
    cout << bitset<sizeof(T)*8>{n} << endl;
}

int updateBit(int num, int i, char bitIs1)
{
    int value = (int)bitIs1;
    // create a binary int with the 1 set at position 1
    // then negate all bits
    int mask = ~(1 << i);
    cout << bitset<sizeof(int)*8>(mask) << endl;
    // using the mask to clear the bit at i
    // (num & mask)

    // shifting desired value into right bit

    // Adding those two numbers, updating value at i
    return (num & mask) | (value << i);
    
    
}

// Expects two 32bit numbers bin and indices in dec
int insertion(int N, int M, int i, int j)
{
    // insert M at position j to i in N
    string Mbin = bitset<sizeof(int)*8>(M).to_string();
    int index = 0;
    for(int k = j; k <= i; k++)
    {
        updateBit(N, k, Mbin[index++]);
    }
    
}

int main()
{

    string N = "10000000000";
    unsigned long Ndec = bitset<sizeof(int)*8>(N).to_ulong();
    cout << Ndec << endl;

    string Nbin = bitset<sizeof(int)*8>(N).to_string();
    cout << Nbin << endl;

    string M = "10011";
    unsigned long Mdec = bitset<sizeof(int)*8>(M).to_ulong();
    cout << Mdec << endl;

    string Mbin = bitset<sizeof(int)*8>(M).to_string();
    cout << Mbin << endl;


    int i = 2;
    int j = 6;
    int result = insertion(Ndec, Mdec, i, j);
    cout << "Result: " << bitset<sizeof(int)*8>(result) << endl;

    return 0;
}