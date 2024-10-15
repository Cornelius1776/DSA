#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/* The g++ compiler also supports some data structures that are not part of the C++
standard library. Such structures are called policy-based data structures. */

int main()
{
    // indexed_set that is like set but can be indexed like an array
    typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);

    // find_by_order() returns an iterator to the element at a given position:
    auto x = s.find_by_order(2);
    std::cout << *x << "\n"; // 7
    // order_of_key() returns the position of a given element:
    std::cout << s.order_of_key(7) << "\n"; // 2
    // If the element is not in the set, the position that the element would have in the set is returned:
    std::cout << s.order_of_key(6) << "\n"; // 2
    std::cout << s.order_of_key(8) << "\n"; // 3

    return 0;
}