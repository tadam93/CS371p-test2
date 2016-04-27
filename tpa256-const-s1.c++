#include <cassert>  // assert
#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Consts.c++" << endl;

    // Will it compile? yes
    {
      int i = 2;
      int * const p = &i;
      ++*p;
      assert(i == 3);
    }

    // Will it compile? no
    {
      int i = 2;
      const int * p;
      p = &i;
      //++*i; can't modify because the p points to a const int
      assert(i == 2);
    }

    // Will it compile? yes, but t produces undefined behavior
    {
      const int i = 2;
      const int * const p = &i;
      int * t = const_cast<int *>(p);
      ++*t; // undefined
    }

    // Will it compile? nope
    {
      int i  = 2;
      const int & r = i;
      //int & f = r;
      //f++;
    }
}
