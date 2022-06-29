//
//  tree.cpp
//  homework 3
//
//  Created by James Fu on 5/3/22.
//

int numberOfTimesHas(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0) {
        return 1;
    }
    if (n1 < n2 || n1 < 0) {
        return 0;
    }
    int k = numberOfTimesHas(a1+1, n1-1, a2, n2);
    if (a1[0] == a2[0]) {
        k += numberOfTimesHas(a1+1, n1-1, a2+1, n2-1);
    }
    return k;
}

// Exchange two strings
void exchange(string& x, string& y)
{
    // temp
    string t = x;
    x = y;
    y = t;
}

void split(string a[], int n, string splitter,
                                  int& firstNotLess, int& firstGreater)
{
  if (n < 0)
      n = 0;

    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < splitter
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == splitter
    //  Every element from firstUnknown to firstGreater-1 is not known yet
    //  Every element at position firstGreater or later is > splitter

  firstNotLess = 0;
  firstGreater = n;
  int firstUnknown = 0;
  while (firstUnknown < firstGreater)
  {
      if (a[firstUnknown] > splitter)
      {
          firstGreater--;
          exchange(a[firstUnknown], a[firstGreater]);
      }
      else
      {
          if (a[firstUnknown] < splitter)
          {
              exchange(a[firstNotLess], a[firstUnknown]);
              firstNotLess++;
          }
          firstUnknown++;
      }
  }
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(string a[], int n)
{
    if (n > 1) {
        int firstNotLess;
        int firstGreater;
        // recursion
        split(a, n, a[0], firstNotLess, firstGreater);
        // sorting elements first half
        order(a, firstNotLess);
        // sorting the elements second half if necessary
        if (firstGreater != n) {
            order (a + firstGreater, n - firstGreater);
        }
    }
    return;
}
