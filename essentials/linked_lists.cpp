/*
###
Playing with linked lists
###

Definition:
list - Either singly linked or doubly linked, implemented with
node structs or classes. Linking list nodes together with pointers
to the next node. Circular lists are often considered corrupted or broken.
STL list - doubly linked list, size aware, with loads of convenient functions.
STL forward_list - singly linked list

ADT Properties:
Insert: O(1)
Search:
Remove: O(1)
Select:
Sort:
Join:

*/

#include<iostream>
#include<list>
using namespace std;

/*
###
list
###
*/

struct node
{
    int val;
    node* next;
    node(int v, node* t): val{v}, next{t} { };
};
typedef node* link;

// insert node x after t
link insertH(int val, link t)
{
    link x = new node(val, t->next);
    t->next = x;
    return x;
}

// Insert node at the tail
link insertT(int val, link t)
{
    link x = new node(val, 0);
    t->next = x;
    return x;
}

// remove node after x
link remove(link x)
{
    link t = x->next;
    x->next = t->next;
    delete t;
    return x;
}

// print list values
void printList(link head)
{
    while(head != 0)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// reverse linked list
link reverse(link x)
{
    // 1. maintain 3 consecutive pointers
    link processed = 0; // new head to start from
    link unprocessed = x; // first link in the chain to reverse
    link temporary;

    while(unprocessed != 0)
    {
        // 2. save third node in pointer & turn around second
        temporary = unprocessed->next;
        unprocessed->next = processed; // turn around pointer

        // 3. move forward first and second (processed & unprocessed part)
        processed = unprocessed;
        unprocessed = temporary;
    }
    return processed;

}

int main()
{

    /*
    ###
    Head List Insert
    ###
    */

    // creating null link to start from
    link head = new node(0,0);

    // creating list with 10 elem after head
    // head insert, element to insert after is constant = head
    int length = 10;
    for(int i=0; i<length; i++)
        insertH(i+length, head);

    cout << "List created at the head: ";
    printList(head);

    head = reverse(head);
    cout << "Head creation list reversed: ";
    printList(head);


    /*
    ###
    Tail List Insert
    ###
    */

    link head2 = new node(0,0);
    int length2 = 12;
    link t = head2;
    for(int i=0; i<length; i++)
        t = insertT(i+length, t);

    cout << "List created at the tail: ";
    printList(head2);

    head2 = reverse(head2);
    cout << "Tail creation list reversed: ";
    printList(head2);


    /*
    ###
    STL list (doubly linked list)
    ###
    */

    // list declaration
    list<int> l1;
    cout << l1.back() << endl; // returns default value for type int
    cout << l1.front() << endl; // returns default value for type int


    // list initialization with initializer list
    // even after declaration
    l1 = {1,2,3};
    for(auto elem : l1) cout << elem << " ";
    cout << endl;

    // print front and back item, no random access (selection)
    cout << l1.back() << endl; // 3
    cout << l1.front() << endl; // 1

    // remove first and last item
    l1.pop_front();
    l1.pop_back();

    // now front == back
    cout << l1.back() << endl; // 2
    cout << l1.front() << endl; // 2

    // merging lists in sorted order
    cout << "Size before merging: " << l1.size() << endl;
    list<int> l2 = {1,5,6};
    l1.merge(l2);
    for(auto elem : l1) cout << elem << " ";
    cout << endl;
    cout << "Size after merging: " << l1.size() << endl;

}
