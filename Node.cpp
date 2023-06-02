//Mark Hentges 5814125 2/23/2023

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for a node in the linked implementation of the
 *  ADT bag.
 *
 *  Adapted from page 137 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 23 Feb 2023
 *
 *  @version 7.0 */

#include "Node.h"

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     Node<ItemType>* nextNodePtr)
   : item(anItem),
     next(nextNodePtr) {
}

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {

   item = anItem;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {

   next = nextNodePtr;
}

template <typename ItemType>
ItemType Node<ItemType>::getItem() const {

   return item;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {

   return next;
}
