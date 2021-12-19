// Caroline El Jazmi
// UW ID: 1942686

// This program implements a singly linked list called LinkedList, a subclass of ILish.h. This linked list manipulates a list by adding/removing nodes from
// a list, clearing out the list, searching for a specific element inside the list, checking if the list is empty, as well as keeps count of the length
// of the list as well as the number of times a linked list is travered when searching for an element inside of the list.


#include "IList.h"
#include <vector>
#include <iostream>

// Node constructor
struct Node {
    // Store data
    int data;
    // Pointer to next node
    Node *next;
};

// Class LinkedList
class LinkedList
{
    public:
    LinkedList();

    int length_;
    int traverseCount;
    Node *head_;
    Node *tail_;
    // Store data
    int data;
    // Pointer to next node
    Node *next;

    // Functions declaration
    bool add(int newEntry);
    bool remove(int anEntry);
    int getCurrentSize();
    bool isEmpty();
    void clear();
    bool contains(int anEntry);
    int getTraverseCount();
    void resetTraverseCount();
    ~LinkedList();
};
