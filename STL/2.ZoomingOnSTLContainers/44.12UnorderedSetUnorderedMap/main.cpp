#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

/* An unordered-map is an unordered container that stores data as key/value pairs.
Unordered map keys and the values are unique. However,
the elements are not sorted they are outputed randomly. */

/* An unordered set is an assciative container that stores unique element, but they are not sorted.
This allows for fast insertion and removal, with a O(1) time complexity. */

template <typename T>
void show_collection(const T &collection)
{

    std::cout << " [";
    for (const auto &element : collection)
    {
        std::cout << " " << element;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void show_map_collection(const T &collection)
{

    std::cout << " [";
    for (const auto &[key, value] : collection)
    {
        std::cout << " (" << key << "," << value << ")";
    }
    std::cout << "]" << std::endl;
}

int main()
{

    // std::set<int> collection_1 = {11,16,2,912,15,6,15,2};
    std::unordered_set<int> collection_1 = {11, 16, 2, 912, 15, 6, 15, 2};

    std::cout << "collection_1 : ";
    show_collection(collection_1);

    // std::map<int, int> collection_2 = {{1, 11}, {0, 12}, {4, 13}, {2, 14}, {3, 15}};
    std::unordered_map<int, int> collection_2 = {{1, 11}, {0, 12}, {4, 13}, {2, 14}, {3, 15}};

    std::cout << "collection_2 : ";
    show_map_collection(collection_2);

    collection_2[1] = 16;
    show_map_collection(collection_2);

    return 0;
}