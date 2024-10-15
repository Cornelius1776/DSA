#include <iostream>
#include <array>
/* std::array is an STL container that encapsulates fixed size arrays. It is important that the
compiler knows the size of the array at compile time. */

template <typename T, size_t Size> // The second template argument is the size.

void print_array(const std::array<T, Size> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print_raw_array(const T *arr, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

int main()
{

    std::array<int, 3> array_1;          // Will contain junk by default
    std::array<int, 3> array_2 = {1, 2}; // Will contain 1,2,0
    std::array<int, 3> array_3 = {};     // Will contain 0 0 0
    std::array array_4 = {1, 2};         // Compiler will deduce std::array<int,2>
    // std::array<int, 3> int_array5{1,2,3,4,5}; // Compiler error : Exceeded speified number of elements

    std::cout << "array_1 : ";
    print_array(array_1);

    std::cout << "array_2 : ";
    print_array(array_2);

    std::cout << "array_3 : ";
    print_array(array_3);

    std::cout << "array_4 : ";
    print_array(array_4);

    // Adding and removing stuff
    // Can't really add stuff. Can specify content at initialization
    // Can also fill the entire array with an element
    std::cout << std::endl;

    std::cout << "Filling the array : " << std::endl;
    array_1.fill(321); // all 3 elements will be 321.
    array_4.fill(500);
    std::cout << "array_1 : ";
    print_array(array_1);
    std::cout << "array_4 : ";
    print_array(array_4);
    std::cout << std::endl;

    // Accessing elements
    std::cout << "Accessing elements in an array: " << std::endl;
    std::cout << "array_2[0] : " << array_2[0] << std::endl;
    std::cout << "array_2.at(1) : " << array_2.at(1) << std::endl;
    std::cout << "array_2.front() : " << array_2.front() << std::endl;
    std::cout << "array_2.back() : " << array_2.back() << std::endl;
    // data method
    print_raw_array(array_1.data(), array_1.size());
    print_raw_array(array_2.data(), array_2.size());
    print_raw_array(array_3.data(), array_3.size());
    print_raw_array(array_4.data(), array_4.size());

    return 0;
}