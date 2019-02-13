/*
###
Question 4.2: Minimal Tree
###

Description:
Given a sorted (increasing order) array with unique integer elements,
write an algorithm to create a binary search tree with minimal height.

Example:

Hint:

Runtime:
Traverse through the tree for each item O(N log N)
Divide and conquer cuts away the tree traversal until search failure.

*/

#include<iostream>
#include<vector>
#include "../lib/binary_search_tree.cpp"
using namespace std;

int main()
{

    vector<int> seed = {1,3,5,7,9,11,13,15};

    BST<int> bst;

    bst.createMinimalTree(seed);


    cout << "Pre Order:\n";
    bst.printPreOrder();

    cout << "In Order:\n";
    bst.printInOrder();

    cout << "Post Order:\n";
    bst.printPostOrder();


}