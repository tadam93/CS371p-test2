// -------------
// Iterators.c++
// -------------

// http://www.cplusplus.com/doc/tutorial/control/

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

    {
    istringstream         sin("2 3 4");
    ostringstream         sout;
    istream_iterator<int> b(sin);
    istream_iterator<int> e; //end of stream iterator
    ostream_iterator<int> x(sout, " ");
    copy(b, e, x);
    assert(sout.str() == "2 3 4 ");
    }

  /*  {//Why doesn't this work?
    ostringstream         sout;
    ostream_iterator<int> b(sout, " ");
    ostream_iterator<int> e(sout);
    const int v = 2;
    fill(b, e, v);                      // error: no matching function for call to '__fill'
  }*/

    {
    forward_list<int> x(3);
    const int v = 2;
    fill(x.begin(), x.end(), v);
    assert(all_of(x.begin(), x.end(), [] (int w) -> bool {return w == v;}));
    }
/*
    { can't go iterate in both directions with a forward_list
    forward_list<int> x = {2, 3, 4}; // error: no matching function for call to '__reverse'
    reverse(x.begin(), x.end());
    }
*/
    {
    list<int>   x = {2, 3, 4};
    vector<int> y = {4, 3, 2};
    reverse(x.begin(), x.end());
    assert(equal(x.begin(), x.end(), y.begin()));
    }
/*
    {
    list<int>   x = {2, 3, 4}; // bidirectional iterators, sort needs random access
    sort(x.begin(), x.end());  // error: invalid operands to binary expression ('std::__1::__list_iterator<int, void *>' and 'std::__1::__list_iterator<int, void *>')
    }
*/
    {
    vector<int>   x = {4, 2, 3};
    list<int>     y = {2, 3, 4};
    sort(x.begin(), x.end());
    assert(equal(x.begin(), x.end(), y.begin()));
    }

    cout << "Done." << endl;
    return 0;}
