#include "odd_or_even.h"

int main()
{
    BST_node tree;
    BST_node *root = nullptr;
    std::cout << std::boolalpha << tree.is_empty(root) << std::endl;

    int arr[] = {25, 27, 20, 22, 12, 18, 45, 10, 32, 14, 56, 43, 98, 100};
    for (auto &&data : arr)
    {
        root = tree.insert(root, data);
    }
    std::cout << "Odd number elements are: ";
    tree.odd(root);
    std::cout << std::endl;
    std::cout << "Even number elements are: ";
    tree.even(root);
    std::cout << std::endl;

    std::cout << std::boolalpha << tree.is_empty(root) << std::endl;

    return 0;
}