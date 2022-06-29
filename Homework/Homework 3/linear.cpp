//
//  linear.cpp
//  homework 3
// 
//  Created by James Fu on 5/3/22.
//

// Return false if the somePredicate function returns true for at
// least one of the array elements; return true otherwise.
bool allFalse(const string a[], int n)
{
    if (n > 0) {
        // Look and find  if there is another element if n > 0
        if (somePredicate(a[0])) return false;
        return allFalse(a + 1, n - 1);
    }
    return true;
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
    if (n <= 0) return 0;
    if (!somePredicate(a[0])) {
        return countFalse(a + 1, n - 1) + 1;
    }
    return countFalse(a + 1, n - 1);
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n)
{
    if (n <= 0) {
        return -1;
    }
    int k = firstFalse(a, n - 1);
    if (!somePredicate(a[n-1]) && k == -1) {
        return n - 1;
    }
    return firstFalse(a, n - 1);
}

int positionOfLeast(const string a[], int n)
{
    // If the function is told that no strings are to
    // be considered in the array, return -1.
    if (n <= 0) {
        return -1;
    }
    // Return the subscript of the least string in the array (i.e.,
    // return the smallest subscript m such that a[m] <= a[k] for all
    // k from 0 to n-1).
    if (n == 1) {
        return 0;
    }
    if (a[0] > a[n-1]) {
        if (n == 2) return n - 1;
        else return positionOfLeast(a + 1, n - 1) + 1;
    }
    return positionOfLeast(a, n - 1);
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "merida" "tiana" "raya" "belle" "tiana" "raya" "moana"
// then the function should return true if a2 is
//    "tiana" "belle" "moana"
// or
//    "tiana" "raya" "raya"
// and it should return false if a2 is
//    "tiana" "moana" "belle"
// or
//    "merida" "belle" "belle"
bool has(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0) {
        return true;
    }
    if (n1 <= 0) {
        return false;
    }
    // a2 and a1 are nonempty
    if (a1[0] == a2[0]) {
        return has(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
    }
    else {
        return has(a1 + 1, n1 - 1, a2, n2);
    }
    // shouldn't get here but just in case
    return has(a1 + 1, n1 - 1, a2, n2);
}
