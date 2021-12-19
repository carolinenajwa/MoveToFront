// Caroline El Jazmi
// UW ID: 1942686

// This program implements the Move-to-front (MTF) list strategy in a list. The MTFList class is a subclass of LinkedList. 
// The MFT strategy is a self-organization method where every time an element is accessed, it is moved to the front of the list. 

#include <iostream>
#include <vector>
#include "MTFList.h"



// Class decleration 
MTFList::MTFList()
{
    // Declaration of list size
    this->length_ = 0;
    // Declaration of traverse count as node travels through list
    this->traverseCount = 0;
    // Dangling nodes safety net
    this->head_ = nullptr;
    this->tail_ = nullptr;
}

// Move to front strategy to rearrange 
// List. Take in anEntry and places it at 
// the front of the list
bool MTFList::moveToFront(int anEntry)
{
    // Current node pointer-pointing to head node
    Node *curr = this->head_;
  
    // Pointer to previous node set to empty
    Node* prev = NULL;
  
    // While current pointer does not point
    // to empty node, search for anEntry continues
    while (curr != NULL) {
  
        // If anEntry is found
        if (curr->data == anEntry) {
  
            // if anEntry is not head node
            if (prev != NULL) {
  
                // anEntry is placed at the front
                // of the list
                prev->next = curr->next;
                curr->next = head_;
                head_ = curr;
            }
            // anEntry is found
            return true;
        }
        // Search for node continues
        prev = curr;
        curr = curr->next;
    }
  
    // anEntry is not found
    return false;
};
