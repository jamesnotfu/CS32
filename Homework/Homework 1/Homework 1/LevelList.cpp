#include "LevelList.h"

LevelList::LevelList() {
}

bool LevelList::add(unsigned long level) {
    // If the level is valid (a value from 30 to 400) and the level list
    // has room for it, add it to the level list and return true.
    if(level >=30 && level <=400 && m_list.insert(m_list.size(), level)!=-1) {
        return true;
    }
    // Otherwise, leave the level list unchanged and return false.
    return false;
}

bool LevelList::remove(unsigned long level) {
    // Remove one instance of the specified level from the level list.
    // Return true if a level was removed; otherwise false.
    int pos = m_list.find(level);
    return m_list.erase(pos);
}

int LevelList::size() const {
    // Return the number of levels in the list.
    return m_list.size();
}

unsigned long LevelList::minimum() const {
    if(m_list.empty()) return NO_LEVEL;
    unsigned long min = NO_LEVEL;
    unsigned long temp = 0;
    for(int i = 0; i < m_list.size(); i++) {
        m_list.get(i, temp);
        if(temp < min) min = temp;
    }
    return min;
}

unsigned long LevelList::maximum() const {
    if(m_list.empty()) return NO_LEVEL;
    unsigned long min = 0;
    unsigned long temp = 0;
    for(int i = 0; i < m_list.size(); i++) {
        m_list.get(i, temp);
        if(temp > min) min = temp;
    }
    return min;
}
// Return the lowest-valued level in the level list.  If the list is
// empty, return NO_LEVEL.
