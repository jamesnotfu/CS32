#include "Sequence.h"
#include <iostream>

using namespace std;

Sequence::Sequence(int value)
    : m_size(0)  // Create an empty sequence (i.e., one whose size() is 0).
{
}

bool Sequence::empty() const
{
    if(m_size == 0) return true;
    return false;
}

int Sequence::size() const  // Return the number of items in the sequence.
{
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value)
{
    if(pos > size() || size() == DEFAULT_MAX_ITEMS || pos < 0) {
        return -1;
    }
    else {
        m_size++;
        for(int i = size()-1; i > pos; i--) {
            m_array[i] = m_array[i-1];
        }
        m_array[pos] = value;
        return pos;
    }
}
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one greater than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.

int Sequence::insert(const ItemType& value) {
    if(size() == DEFAULT_MAX_ITEMS) return -1;
    else {
        for(int i = 0; i < size(); i++) {
            if(value <= m_array[i])
            {
                m_size++;
                for(int j = size() - 1; j > i; j--) {
                    m_array[j] = m_array[j-1];
                }
                m_array[i] = value;
                return i;
            }
        }
        m_size++;
        m_array[size()-1] = value;
        return size()-1;
    }
}
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item at position p and those that follow it end
// up at positions one greater than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).

bool Sequence::erase(int pos) {
    // Otherwise, leave the sequence unchanged and return false.
    if(pos < 0 || pos >= size()) return false;
    // If 0 <= pos < size(), remove the item at position pos from
    // the sequence (so that all items that followed that item end up at
    // positions one lower than they were at before), and return true.
    else {
        for(int i = pos; i < size() - 1; i++) {
            m_array[i] = m_array[i+1];
        }
        m_size--;
        return true;
    }
}

int Sequence::remove(const ItemType& value) {
    int m_count = 0;
    for(int i = 0; i < size(); i++) {
        if(m_array[i] == value) {
            erase(i);
            m_count+=1;
        }
    }
    return m_count;
}
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).

bool Sequence::get(int pos, ItemType& value) const {
    if(pos < 0 || pos >= size()) return false;
    else {
        value = m_array[pos];
        return true;
    }
}
// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.

bool Sequence::set(int pos, const ItemType& value) {
    if(pos < 0 || pos >= size()) return false;
    else {
        m_array[pos] = value;
        return true;
    }
}
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.

int Sequence::find(const ItemType& value) const {
    int p;
    for(int p = 0; p < size(); p++) {
        if(m_array[p] == value) return p;
    }
    p = -1;
    return p;
}
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.

void Sequence::swap(Sequence& other) {
    ItemType temparray[DEFAULT_MAX_ITEMS];

        int tempsize = size(); //Copy this Sequence to the temp storage
        for (int k = 0; k < size(); k++)
        {
            get(k,temparray[k]);
        }
        m_size = other.size(); //Copy other to this Sequence
        for (int k = 0; k < size(); k++)
        {
            set(k, other.m_array[k]);
        }
        other.m_size = tempsize; //Copy temp to other Sequence
        for (int k = 0; k < tempsize; k++)
        {
            other.m_array[k] = temparray[k];
        }
}
// Exchange the contents of this sequence with the other one.


void Sequence::dump() const {
    for(int i = 0; i < m_size; i++){
        cerr<<m_array[i]<<endl;
    }
}
