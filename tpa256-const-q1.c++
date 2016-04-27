#include <cassert>  // assert
#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Consts.c++" << endl;

    // Will it compile?
    {
      int i = 2;
      int * const p = &i;
      ++*p;
    }

    // Will it compile?
    {
      int i = 2;
      const int * p;
      p = &i;
      ++*p;
    }

    // Will it compile?
    {
      const int i = 2;
      const int * const p = &i;
      int * t = const_cast<int *>(p);
      ++t;
    }

    // Will it compile?
    {
      int i  = 2;
      const int & r = i;
      int & f = r;
      f++;
    }
}
