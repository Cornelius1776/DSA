#include <iostream>
#include <vector>
#include <array>

template <typename T>
void print_collection(const T &collection)
{

    auto it = collection.begin();

    std::cout << " [";
    while (it != collection.end())
    {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> ints_1 = {11, 22, 33, 44};
    std::array<int, 4> ints_2 = {100, 200, 300, 400};

    std::vector<int>::iterator it_begin = ints_1.begin();
    std::vector<int>::iterator it_end = ints_1.end();

    std::cout << "ints_1 elements" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "first element : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "second element : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "third element : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "fourth element : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "junk element : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl; // true
    std::cout << std::endl;

    std::cout << "ints_2 elements" << std::endl;
    std::array<int, 4>::iterator arr_begin = ints_2.begin();
    std::array<int, 4>::iterator arr_end = ints_2.end();
    std::cout << std::boolalpha;
    std::cout << "first element : " << *arr_begin << std::endl;
    std::cout << "it == end_it : " << (arr_begin == arr_end) << std::endl;

    arr_begin++;
    std::cout << "second element : " << *arr_begin << std::endl;
    std::cout << "it == end_it : " << (arr_begin == arr_end) << std::endl;

    arr_begin++;
    std::cout << "third element : " << *arr_begin << std::endl;
    std::cout << "it == end_it : " << (arr_begin == arr_end) << std::endl;

    arr_begin++;
    std::cout << "fourth element : " << *arr_begin << std::endl;
    std::cout << "it == end_it : " << (arr_begin == arr_end) << std::endl;

    arr_begin++;
    std::cout << "junk element : " << *arr_begin << std::endl;
    std::cout << "it == end_it : " << (arr_begin == arr_end) << std::endl; // true

    std::cout << "--------" << std::endl;
    std::cout << "ints_1 : ";
    print_collection(ints_1);

    std::cout << "ints_2 :";
    print_collection(ints_2);

    return 0;
}