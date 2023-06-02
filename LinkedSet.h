//Mark Hentges 5814125 2/23/2023

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for a linked implementation of the ADT Set.
 *
 *  Adapted from page 139 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Mark Hentges
 *
 *  @date 23 Feb 2023
 *
 *  @version 7.0 */

#ifndef LINKED_SET_
#define LINKED_SET_

#include <vector>

#include "SetInterface.h"
#include "Node.cpp"

/** @class LinkedSet LinkedSet.h "LinkedSet.h"
 *
 *  Specification of a pointer-based ADT Set. */
template <typename ItemType>
class LinkedSet : public SetInterface<ItemType> {
private:
   /** Define nested data type 'NodePtr'.
    *
    * Create a more "friendly" type name for a
    * pointer-to-a-node-of-ItemType. */
   using NodePtr = Node<ItemType>*;

   /** Pointer to first node in this LinkedSet's linked chain.
    *
    * Default initialized to 'nullptr', which is an empty linked
    * chain. */
   NodePtr headPtr = nullptr;

   /** Number of items in this Set.
    *
    * An empty Set has no (zero) items. */
   int itemCount = 0;

   /** Gets a pointer to the node containing the target in this Set.
    *
    * @pre None.
    *
    * @post None.
    *
    * @param target The 'ItemType' value to find.
    *
    * @return A pointer to the node that contains the given 'target'
    *         or 'nullptr' if this Set does not contain 'target'. */
   NodePtr getPointerTo(const ItemType& target) const;

public:
   /** Default constructor. */
   LinkedSet() = default;

   /** Copy constructor. */
   LinkedSet(const LinkedSet<ItemType>& aSet);

   virtual ~LinkedSet();

   virtual int getCurrentSize() const;

   virtual bool isEmpty() const;

   virtual bool add(const ItemType& newEntry);

   virtual bool remove(const ItemType& anEntry);

   virtual void clear();

   virtual int getFrequencyOf(const ItemType& anEntry) const;

   virtual bool contains(const ItemType& anEntry) const;

   virtual std::vector<ItemType> toVector() const;

    /** Performs the difference set theoritic operation.
     *
     *
     *  @param set the set that will be subtracted.
     *
     *  @return new difference set. */
   LinkedSet<ItemType> difference(const LinkedSet<ItemType>& set) const;
};

#endif
