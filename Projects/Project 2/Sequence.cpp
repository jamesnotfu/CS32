#include "Sequence.h"
#include <iostream>

using namespace std;

// CONSTRUCTOR
Sequence::Sequence() : m_size(0) {
    Node* dummy = new Node; // make head point to a dummy node
    // make previous pointers and next pointers point to dummy node (see ipad diagram)
    dummy->m_next = dummy;
    dummy->m_previous = dummy;
    head = dummy;
}

// DESTRUCTOR
// When as Sequence is destroyed, the nodes in the linked list must be deallocated
Sequence::~Sequence() {
    // create a dummy node
    Node* p;
    // set it equal to the next element
    p = head->m_next;
    Node* toBeDeleted = p;
    // while there is a next element and it isn't null
    while(p!=head) {
        // look at the next element
        p = p->m_next;
        // delete the node of the second pointer
        toBeDeleted->m_previous->m_next = toBeDeleted->m_next;
        toBeDeleted->m_next->m_previous = toBeDeleted->m_previous;
        delete toBeDeleted;
        // set the new to be deleted element to point at p
        toBeDeleted = p;
    }
    // delete head node
    delete head;
}

// COPY CONSTRUCTOR
Sequence::Sequence(const Sequence& other) {
    m_size = 0;
    head = new Node; // this is the dummy node
    head->m_next = head; // circular method
    head->m_previous = head;
    for(int count = 0; count < other.size(); count++)
    {
        ItemType temp;
        other.get(count, temp);
        insert(count, temp);
    }
}

Sequence& Sequence::operator=(const Sequence& other) {
    // lecture 4/5
    // check for aliasing to make sure the same thing is not being compared
    if(this != &other) {
        // make a copy of rhs
        Sequence temp(other);
        // swap this set with the copy
        swap(temp);
    }
    return *this;
}

// FUNCTIONS
bool Sequence::empty() const {
    if(m_size == 0) return true;
    return false;
}

int Sequence::size() const {
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value)
{
    // determine if position is valid and it can actually be inserted otherwise return error -1
    if(pos > size() || pos < 0) {
        return -1;
    }
    else {
        Node* temp = head->m_next;
        for (int i = 0; i < pos; i++) {
            temp = temp->m_next;
        }
        Node* insertItem = new Node; // represent inserted value
        insertItem->data = value; // store value being inserted
        insertItem->m_previous = temp->m_previous; // current temp node's previous becomes inserted node's previous
        insertItem->m_next = temp; // current temp node becomes inserted node
        temp->m_previous->m_next = insertItem; // node after temp node's previous node becomes inserted node
        temp->m_previous = insertItem;
        m_size+=1; // increase size because added new item
        return pos;
    }
    // otherwise an error occured
    return -1;
}

int Sequence::insert(const ItemType& value) {
    int chode = m_size; // let p be the smallest integer
    Node* p = head;
    for(int i = 0; i < m_size; p=p->m_next, i++) {
        if(value<= p->m_next->data) {
            chode = i;
            break;
        }
    }
    if(insert(chode, value)!=-1) return chode;
    return -1;
}

bool Sequence::erase(int pos) {
    // If 0 <= pos < size(), remove the item at position pos from the sequence
    // the code below breaks a test case for when the array is empty
//    if(!empty()) {
//        // if array is empty there is nothing to erase
//        return false;
//    }
    if(pos >= 0 && pos < m_size) {
//        Node* p = head->m_next;
        Node* p = head;
//        for(int i = 0; i < pos; p = p->m_next, i++)
        for(int i = -1; i < pos; p = p->m_next, i++)
            ;
        // the node before points to the node after p
        p->m_previous->m_next = p->m_next;
        // the node after points to the node before p
        p->m_next->m_previous = p->m_previous;
        m_size--;
        // remove the node
        delete p;
        // return true if element was returned
        return true;
    }
    // return false to provide a return value OR error occurred
    return false;
}


int Sequence::remove(const ItemType& value)
{
    // create an int to store the number of elements removed to return
    // need to watch lecture 5 and fix
    int count = 0;
    // create a dummy
    Node *p = head;
    // as long as there is a next element and it isnt null/empty
    for (int i = 0; i < m_size; p = p->m_next, i++) {
        if (p->m_next->data == value) {
            erase(i);
            count++;
            i--;
            p = p->m_previous;
        }
    }
    return count;
}

bool Sequence::get(int pos, ItemType& value) const {
    if(pos < 0 || pos >= m_size) {
        return false;
    }
    else {
        int count = 0;
        Node* p = head->m_next;
        while(p != head) {
            if(count == pos) {
                value = p->data;
            }
            count++;
            p = p->m_next;
        }
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value) {
    if(pos < 0 || pos >= m_size) {
        return false;
    }
    else {
        int count = 0;
        Node* p = head->m_next;
        while(p != head) {
            if(count == pos) {
                p->data = value;
            }
            count++;
            p = p->m_next;
        }
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const {
    // return -1 if no item exists, so make chode -1
    int chode = -1;
    Node* p = head;
    for(int i = 0; i < m_size; p=p->m_next, i++) {
        if(p->m_next->data==value) {
            chode = i;
            // exit the for loop if the element is found
            break;
        }
    }
    return chode;

}

void Sequence::swap(Sequence& other)
{
    Node* temp = head; // temp pointer
    int temp_size = m_size;

    head = other.head; // switch the heads
    m_size = other.m_size;

    other.head = temp; // make sure that the sizes are swapped properly
    other.m_size = temp_size;
}

void Sequence::dump() const{
    
    int count = 0;
    for (Node* p = head->m_next; count < 15; p = p->m_next){
        cerr << "  " << p->data;
        count++;
    }

    cerr << endl << "head = " << head->data << endl;
}
