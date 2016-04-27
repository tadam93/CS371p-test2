
#include <algorithm>    // all_of, copy, fill, reverse, sort
#include <cassert>      // assert
#include <forward_list> // forward_list
#include <iostream>     // cout, endl
#include <iterator>     // istream_iterator, ostream_iterator
#include <list>         // list
#include <sstream>      // istringstream, ostringstream
#include <vector>       // vector

int main () {
    using namespace std;
    cout << "Iterators.c++" << endl;

    istringstream         sin("2 3 4");
    ostringstream         sout;
    istream_iterator<int> b(sin);
    istream_iterator<int> e;
    ostream_iterator<int> x(sout, " ");
    copy(b, e, x);
    assert(sout.str() == "2 3 4 ");
}
