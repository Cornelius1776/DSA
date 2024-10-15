#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/* The Nth element algorithm allows partial sorting by arranging the elements in such a way that
the nth element will be at a position where all the elements that come before it must either be
greater or lesser than the nth element, whichever way you choose to implement it. */

int main()
{
    std::vector<int> my_vec = {5, 6, 4, 3, 2, 6, 7, 8, 94, 1, 25};

    std::nth_element(my_vec.begin(), my_vec.begin() + my_vec.size() / 2, my_vec.end());
    std::cout << "The median is: " << my_vec[my_vec.size() / 2] << std::endl;

    std::nth_element(my_vec.begin(), my_vec.begin() + 1, my_vec.end(), std::greater<int>());
    std::cout << "The second largest element is: " << my_vec[1] << std::endl;

    return 0;
}