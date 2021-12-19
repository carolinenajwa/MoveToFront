// Caroline El Jazmi
// UW ID: 1942686

// This program implements the Move-to-front (MTF) list strategy in a list. The MTFList class is a subclass of LinkedList. 
// The MFT strategy is a self-organization method where every time an element is accessed, it is moved to the front of the list. 

#include <iostream>
#include <vector>
#include "LinkedList.h"

// MTFList class inherits LinkedList class
class MTFList: public LinkedList
{
    public:
    MTFList();
    bool moveToFront(int anEntry);
};
