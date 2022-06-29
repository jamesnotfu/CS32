//
//  NameTable.cpp
//  project_4
//
//  Created by James Fu on 5/30/22.
//
// This is a correct and efficient implementation of
// the NameTable functionality.

#include "NameTable.h"
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <functional>
#include <iostream>
using namespace std;

// This class does the real work of the implementation.
// prime number max buckets to have a more even distribution and avoid collisions
const int HASH_SIZE = 19997;

class NameTableImpl
{
  private:
    // nachenberg lecture 14 function to create a mapping function
    unsigned int mapFunc(const string& id) const {
      // can't use an int like in slides bc of precision causing errors
      size_t h = hash<string>()(id);
      return h % HASH_SIZE;
    }
    // keep track of the scope globally and update this if it changes
    int m_scope = 0;
    struct idNode {
        // the id, linenumber, and scope that is being examined
        string id;
        int lineNum, scope;
        // default constructor
        idNode() {
            this->id = "";
            this->lineNum = 0;
            this->scope = 0;
        }
        // constructor to be able to create an idNode object and add it to the hash table
        idNode(const string& id, const int lineNum, const int scope) {
            this->id = id;
            this->lineNum = lineNum;
            this->scope = scope;
        }
    };
    // hold the ID and scope of the item
    // vector<list<string, int>> hashTable[HASH_SIZE];
    // would be more efficient to use a list of structs
    vector<list<idNode>> hashTable;
    // store the scopes
    // vector<string> m_scp;
    stack<string> m_scp;
  public:
    NameTableImpl();
    ~NameTableImpl();
    void enterScope();
    bool exitScope();
    bool declare(const string& id, int lineNum);
    int find(const string& id) const;
    bool insert(const string& id, int lineNum, int scope);
};

bool NameTableImpl::insert(const string& id, int line, int scope) {
    // get the hash id using the mapping function, starting bucket number
    int hashId = mapFunc(id);
    auto temp = hashTable.at(hashId).begin();
    // check duplicate
    if(temp->id == id && temp->scope == scope) {
        return false;
    }
    // otherwise add element to the hashtable if it isn't a duplicate
    hashTable.at(hashId).push_front(idNode(id, line, scope));
    return true;
}

NameTableImpl::NameTableImpl() {
    // should be O(N)
    for(int i = 0; i < HASH_SIZE; i++) {
        hashTable.push_back(list<idNode>());
    }
}

NameTableImpl::~NameTableImpl() {
    // should be O(N), remove each element from the hashtable
    for(int i = 0; i < HASH_SIZE; i++) {
        hashTable.pop_back();
    }
}

void NameTableImpl::enterScope() {
    // Extend the id vector with an empty string that
    // serves as a scope entry marker.
//  m_ids.push_back("");
//  m_lines.push_back(0);
    m_scp.push("");
    m_scope++;
}

bool NameTableImpl::exitScope() {
    // if the scope is not valid
    if(m_scope <= 0)
        return false;
    
    string id = m_scp.top();
    m_scp.pop();
    
    // while there are still scope ids in the stack remove them if they have the current scope
    while(!id.empty()) {
        int hashId = mapFunc(id);
        for(auto temp = hashTable.at(hashId).begin(); temp != hashTable.at(hashId).end(); temp++) {
            // check if id and scope are equal
            if(temp->id == id && temp->scope == m_scope) {
                hashTable.at(hashId).erase(temp);
                break;
            }
        }
        id = m_scp.top();
        m_scp.pop();
    }
    m_scope--;
    return true;
}

bool NameTableImpl::declare(const string &id, int lineNum) {
    if (id.empty())
        return false;
    m_scp.push(id);
    // use recursion to save the declaration
    // m_ids.push_back(id);
    // m_lines.push_back(lineNum);
    return insert(id, lineNum, m_scope);
}

int NameTableImpl::find(const string& id) const
{
    if (id.empty())
        return -1;
    int rv = -1; // return -1 unless a greater scope is found
    int max = 0; // store the largest scope found from for loop
    // bucket starting
    int hashId = mapFunc(id);
    for(auto temp = hashTable.at(hashId).begin(); temp != hashTable.at(hashId).end(); temp++) {
        // if the ids are equal and the scope is greater than the previous max
        if(temp->id == id && temp->scope >= max) {
            rv = temp->lineNum;
            max = temp->scope;
        }
    }
    return rv;
}

//*********** NameTable functions **************

// For the most part, these functions simply delegate to NameTableImpl's
// functions.

NameTable::NameTable()
{
    m_impl = new NameTableImpl;
}

NameTable::~NameTable()
{
    delete m_impl;
}

void NameTable::enterScope()
{
    m_impl->enterScope();
}

bool NameTable::exitScope()
{
    return m_impl->exitScope();
}

bool NameTable::declare(const string& id, int lineNum)
{
    return m_impl->declare(id, lineNum);
}

int NameTable::find(const string& id) const
{
    return m_impl->find(id);
}
