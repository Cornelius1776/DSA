#include <iostream>
#include <vector>
#include <unordered_map>
/* how_sum() that takes an array and a target sum. The function returns an array that contains the
combination of elements that add up to the target sum. If there are multiple combbinations
that add up to the target sum, it returns any one of them. else if there are no combination
that add up to the target sum, it returns nullptr. If the target sum is 0 it return an empty array
*/

// function to print the how_sum result
void print_how_sum(std::vector<int> arr)
{
    std::cout << "[ ";
    for (auto x : arr)
        std::cout << x << " ";
    std::cout << " ]";
    std::cout << "\n";
}

int main()
{
    std::cout << "Unoptimized" << std::endl;
    std::unordered_map<int, std::vector<int>> cache;
    std::vector<int> arr = {2, 3};
    int target = 7;
    std::vector<int> result = how_sum(arr, cache, target);
    print_how_sum(result);

    std::vector<int> arr_1 = {2, 4};
    result = how_sum(arr_1, cache, target);
    print_how_sum(result);

    std::vector<int> arr_2 = {5, 3, 4, 7};
    result = how_sum(arr_2, cache, target);
    print_how_sum(result);

    std::vector<int> arr_3 = {2, 3, 5};
    result = how_sum(arr_3, cache, target);
    print_how_sum(result);

    /* int arr_4[] = {7, 14};
    target = 300;
    n = 2;
    result = how_sum(arr_4, n, target);
    print_how_sum(result); */

    /* int n = sizeof(arr_2) / sizeof(arr_2[0]);
    std::cout << "Optimized " << std::endl;
    result = optimized_how_sum(arr_2, n, target);
    print_how_sum(result);

    int arr_4[] = {7, 14};
    target = 300;
    n = 2;
    result = optimized_how_sum(arr_4, n, target);
    print_how_sum(result);

    int arr_5[] = {4, 8};
    target = 400, n = 2;
    result = optimized_how_sum(arr_5, n, target);
    print_how_sum(result);
 */
    return 0;
}