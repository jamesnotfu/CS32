#include "Sequence.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    Sequence a;
    a.insert(0, 31);
    a.insert(1, 130);
    a.insert(2, 117);
    a.insert(3, 43);
    a.insert(4, 299);
    assert(a.remove(130) == 1);
    assert(a.size() == 4);

    Sequence b;
    b.insert(300);
    b.insert(399);
    b.insert(32);

    b.swap(a);
    a.dump();
    cerr << endl;
    b.dump();
    cerr << "Passed all test cases.";
    cerr << endl;
}
