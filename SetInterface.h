//Mark Hentges 5814125 2/14/2023

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  SetInterface class template definition.
 *
 *  Adapted from page 24-25 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Mark Hentges 5814125
 *
 *  @date 14 Feb 2023
 *
 *  @version 7.0 */

#ifndef SET_INTERFACE_
#define SET_INTERFACE_

#include <vector>

/** @class SetInterface SetInterface.h "SetInterface.h"
 *
 *  SetInterface abstract base class template. */
template <typename ItemType>
class SetInterface {
public:
   /** Virtual destructor. (See C++ Interlude 2.) */
   virtual ~SetInterface() {}

   /** Gets the current number of entries in this Set.
    *
    *  @return The integer number of entries currently in the Set. */
   virtual int getCurrentSize() const = 0;

   /** Sees whether this Set is empty.
    *
    *  @return True if the Set is empty, or false if not. */
   virtual bool isEmpty() const = 0;

   /** Adds a new entry to this Set - cant have duplicate.
    *  @pre the set cannot already have that item inside of it
    *  @post If successful, newEntry is stored in the Set and the
    *        count of items in the Set has increased by 1.
    *
    *  @param newEntry The object to be added as a new entry.
    *
    *  @return True if addition was successful, or false if not. */
   virtual bool add(const ItemType& newEntry) = 0;

   /** Removes occurrence of a given entry from this Set, if
    *  possible.
    *
    *  @post If successful, anEntry has been removed from the Set and
    *        the count of items in the Set has decreased by 1.
    *
    *  @param anEntry The value of the entry to be removed.
    *
    *  @return True if removal was successful, or false if not. */
   virtual bool remove(const ItemType& anEntry) = 0;

   /** Removes all entries from this Set.
    *
    *  @post This Set contains no items (thus the count is 0). */
   virtual void clear() = 0;


   /** Counts the number of times a given entry appears in Set.
    *
    *  @param anEntry The value of the entry to be counted.
    *
    *  @return The number of times anEntry appears in this Set. */
   virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

   /** Tests whether this Set contains a given entry.
    *
    *  @param anEntry The value of the entry to locate.
    *
    *  @return True if this Set contains anEntry, or false
    *          otherwise. */
   virtual bool contains(const ItemType& anEntry) const = 0;

   /** Converts this Set into a vector.
    *
    *  @return A vector containing all the entries in this Set. */
   virtual std::vector<ItemType> toVector() const = 0;
};

#endif
