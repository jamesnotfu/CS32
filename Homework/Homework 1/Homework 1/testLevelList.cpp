#include "LevelList.h"
#include <cassert>
#include <iostream>

using namespace std;

int main(){
    LevelList k;
    k.add(49);
    k.add(59);
    k.add(69);
    k.add(109);
    assert(k.size()==4);
    assert(k.maximum()==109);
    assert(k.minimum()==49);
    k.add(41);
    k.add(142);
    assert(k.size()==6);
    assert(k.minimum()==41);
    assert(k.maximum()==142);
    assert(k.add(20)==false);
    assert(k.remove(109)==true);
    assert(k.remove(40)==false);
    assert(k.remove(69)==true);
    assert(k.size() == 4);
    k.add(40);
    assert(k.minimum()==40);
    cerr << "Passed all test cases.";
    cerr << endl;
}
