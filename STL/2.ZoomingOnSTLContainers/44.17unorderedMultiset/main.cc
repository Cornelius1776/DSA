#include <iostream>
#include <unordered_set>

template <typename T>
void print_umset(const T &collection)
{
    std::cout << "[";
    for (const auto &element : collection)
    {
        std::cout << element << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

template <typename T>
void find_element(int num, const T &collection)
{
    auto search = collection.find(num);

    if (collection.count(*search) >= 2)
    {
        std::cout << "Found: " << *search << " in " << collection.count(*search) << " places\n";
    }
    else if (search != collection.end())
    {
        std::cout << "Found: " << *search << "\n";
    }
    else
    {
        std::cout << num << " not found!\n";
    }
}

int main()
{
    std::unordered_multiset<int> my_umset = {1, 2, 3, 2, 4, 5, 2, 6, 54, 3, 4, 8};
    print_umset(my_umset);

    int element = 2;
    find_element(element, my_umset);

    return 0;
}