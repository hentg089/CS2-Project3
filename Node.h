//Mark Hentges 5814125 2/23/2023

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for a node in the linked implementation of the ADT
 *  bag.
 *
 *  Adapted from pages 136-137 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 23 Feb 2023
 *
 *  @version 7.0 */

#ifndef NODE_
#define NODE_

template <typename ItemType>
class Node {
private:
   ItemType item;
   Node<ItemType>* next = nullptr;

public:
   Node() = default;

   Node(const ItemType& anItem,
        Node<ItemType>* nextNodePtr = nullptr);

   virtual ~Node() = default;

   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);

   ItemType getItem() const;
   Node<ItemType>* getNext() const;
};

#endif
