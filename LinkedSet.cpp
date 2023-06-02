//Mark Hentges 5814125 2/23/2023
#include <iostream>
/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for the class LinkedSet.
 *
 *  Adapted from pages 139-148 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Mark Hentges
 *
 *  @date 23 Feb 2023
 *
 *  @version 7.0 */

#include <vector>

#include "LinkedSet.h"

template <typename ItemType>
LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aSet) {

    itemCount = aSet.itemCount;

    if (!aSet.headPtr) {
        headPtr = nullptr;
    }
    else {
        NodePtr origChainPtr(aSet.headPtr);

        headPtr = new Node<ItemType>(origChainPtr->getItem() );

        NodePtr newChainPtr(headPtr);

        origChainPtr = origChainPtr->getNext();

        while (origChainPtr) {
            newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()) );

            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
    }
}

template <typename ItemType>
LinkedSet<ItemType>::~LinkedSet() {

   clear();
}

template <typename ItemType>
int LinkedSet<ItemType>::getCurrentSize() const {

   return itemCount;
}

template <typename ItemType>
bool LinkedSet<ItemType>::isEmpty() const {

   return !itemCount;
}

template <typename ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newEntry) {\
    if(contains(newEntry)) return false;
    headPtr = new Node<ItemType>(newEntry,
                                headPtr);

    ++itemCount;

    return true;
}

template <typename ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anEntry) {

   NodePtr entryNodePtr(getPointerTo(anEntry) );

   // If 'entryNodePtr' is pointing at a node:
   if (entryNodePtr) { // entryNodePtr != nullptr (nullptr == false)
      entryNodePtr->setItem(headPtr->getItem() );

      NodePtr nodeToDeletePtr(headPtr);

      headPtr = headPtr->getNext();

      delete nodeToDeletePtr;

      --itemCount;
   }

   return static_cast<bool>(entryNodePtr);
}

template <typename ItemType>
Node<ItemType>*
LinkedSet<ItemType>::getPointerTo(const ItemType& target) const {

   NodePtr curPtr(headPtr);

   while (curPtr) { // curPtr != nullptr
      if (curPtr->getItem() == target) {
         return curPtr;
      }

      curPtr = curPtr->getNext();
   }

   return nullptr; // curPtr == nullptr so 'return curPtr;' works.
}

template <typename ItemType>
void LinkedSet<ItemType>::clear() {

   NodePtr nodeToDeletePtr(headPtr);

   while (headPtr != nullptr) { // headPtr != nullptr
      headPtr = headPtr->getNext();

      delete nodeToDeletePtr;

      nodeToDeletePtr = headPtr;
   }

   // Note that headPtr == nodeToDeletePtr == nullptr
   itemCount = 0;
}

template <typename ItemType>
bool
LinkedSet<ItemType>::contains(const ItemType& anEntry) const {

   return static_cast<bool>(getPointerTo(anEntry) ); // ... != nullptr;
}

template <typename ItemType>
int
LinkedSet<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

   int frequency(0);

   NodePtr curPtr(headPtr);

   while (curPtr) { // != nullptr
      if (curPtr->getItem() == anEntry) {
         ++frequency;
      }

      curPtr = curPtr->getNext();
   }

   return frequency;
}

template <typename ItemType>
std::vector<ItemType> LinkedSet<ItemType>::toVector() const {

   std::vector<ItemType> SetContents;

   NodePtr curPtr(headPtr);

   while (curPtr) { // != nullptr
      SetContents.push_back(curPtr->getItem() );

      curPtr = curPtr->getNext();
   }

   return SetContents;
}

template <typename ItemType>
LinkedSet<ItemType> LinkedSet<ItemType>::difference(const LinkedSet<ItemType>& set) const {
    LinkedSet<ItemType> newSet = LinkedSet(*this);
    NodePtr curPtr(set.headPtr);
    while(curPtr != nullptr){
        newSet.remove(curPtr->getItem());
        curPtr = curPtr->getNext();
    }


    return newSet;
}
