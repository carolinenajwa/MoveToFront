// Caroline El Jazmi
// UW ID: 1942686

// This program implements a singly linked list called LinkedList, a subclass of ILish.h. This linked list manipulates a list by adding/removing nodes from
// a list, clearing out the list, searching for a specific element inside the list, checking if the list is empty, as well as keeps count of the length
// of the list as well as the number of times a linked list is travered when searching for an element inside of the list.

#include <iostream>
#include <vector>
#include "LinkedList.h"

// Class constructor 
LinkedList::LinkedList() 
{

    // Declaration of list size
    this->length_ = 0;
    // Declaration of traverse count as node travels through list
    this->traverseCount = 0;
    // Dangling nodes safety net
    this->head_= nullptr;
    this->tail_ = nullptr;
}

// // Destructor
LinkedList::~LinkedList() 
{
    Node *next = this->head_;
    Node *current = nullptr;
    while (next != nullptr) {
        current = next;
        next = next->next;
        delete current;
    }
}

// Removes all elemends from list
void LinkedList::clear()
{
    // Next node points to head
    Node *next = this->head_;
    // current nodes is nulled
    Node *current = NULL;
    // While head node is not empty
	while(head_ != NULL)
	{
        // current node points to head
		current = head_;
        // current node points to Node after head
		head_ = head_->next;
        // current is removed from list
		delete current;
	}
    // List size now = 0
    length_ = 0;
}

// Add new element from list
bool LinkedList::add(int newEntry) {
    // New node is created
    Node *current = new Node;
    // If list is empty, new node becomes head node
    if (isEmpty()) {
        //Node *current = new Node;
        current = this->head_;
        this->head_ = current;
        return true;

    // If list is not empty, new node is added to end of list
    } else {
        current = this->tail_;
        current->next = new Node;
        return true;
       // current = current->next;
    }
    // New node stores new int data
    current->data = newEntry;
    current->next = nullptr;
    this->tail_ = current;
    // Increases list size
    this->length_++;
    return true;
}

// Remove existing element from the list
bool LinkedList::remove(int anEntry) 
{
    // current node points to head
    Node *current = this->head_;
    // Temp Node pointer created
    Node *temp;

    // While list is not empty and current node
    // has reached int data from list
    while (!isEmpty() && current->data == anEntry) {
        temp = current;
        // 
        this->head_ = current->next;
        current = current->next;
        delete temp;
        this->length_--;
        return true;
    }
    
    // While list is not empty and next node is not empty
    while(!isEmpty() && current->next != nullptr) 
    {
        // If current node data equals to int data
        if (current->next->data == anEntry) {
            // temp Node stores current node
            temp = current->next;
            // current node stores 1 node past removed int data
            current->next = current->next->next;
            // temp node is deallocated
            delete temp;
            // updates tail
            if (current->next == nullptr) {  
                this->tail_ = current;
            }
            this->length_--;
        }
        current = current->next;
        return true;
    }

    // If list empty 
    // tail is removed
    if (isEmpty()) 
    {
        this->tail_ = nullptr;
    }
    return false;
}

// Returns true if list is empty
// false if list is not empty
bool LinkedList::isEmpty() 
{
    return this->head_ == nullptr;
}

// Returns current list size
int LinkedList::getCurrentSize() 
{
    return this->length_;
}

// Returns traverse count when traversing 
// through list  
int LinkedList::getTraverseCount() 
{
    return this->traverseCount;
}

// Resets traverse count when traversing 
// through list to 0
void LinkedList::resetTraverseCount() 
{ 
    this->traverseCount = 0;
}

// Returns true if list contains int data
// returns false if list does not contain int data
 bool LinkedList::contains(int anEntry)
{
    Node *current = this->head_;
    
    while (current != NULL)
    {
        this->traverseCount++;
        current = current->next;
        if (current->data == anEntry)
            return true;
    }
    return true;
    
};
