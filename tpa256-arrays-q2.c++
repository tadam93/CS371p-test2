

#include <algorithm> // copy, count, equal, fill
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t, size_t
#include <iostream>  // cout, endl
#include <string>    // string
#include <vector>    // vector

using namespace std;

void f (int p[]) {
//  assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

struct A {
    int i;

    string f () {
        return "A::f";}};

struct B : A {
    int j;

    string f () {
        return "B::f";}};

int main () {
    cout << "Arrays.c++" << endl;

    const size_t s = 10;
    {
      int a [s];
      cout << a[9] << endl; // what is the value?
      const int b[s] = {1, 2, 3};
      cout << b[9] << endl; // what is the value?
    }

    {
      int a[s] = {1, 2, 3};
      cout << a[3] << endl; // what is the value?
    }

    // will it compile? will it run?
    {
      int        a[] = {2, 3, 4};
      int        b[] = a;
      b[1] = 4;
      assert (a[1] == b[1]);
    }
}
