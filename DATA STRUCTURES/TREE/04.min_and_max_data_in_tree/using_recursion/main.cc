#include "min_max.h"
/* Recursion(the process of function calling themselves) is used to find the minimum and maximum
elements in a tree. */

int main()
{
    BST_node *root = nullptr;
    BST_node tree;

    /* root = tree.insert(root, 25);
    root = tree.insert(root, 27);
    root = tree.insert(root, 20);
    root = tree.insert(root, 12);
    root = tree.insert(root, 45);
    root = tree.insert(root, 10);
    root = tree.insert(root, 110);
    root = tree.insert(root, 5); */

    int element;
    int no_of_node;
    std::cout << "How many node do you want in the? ";
    std::cin >> no_of_node;

    for (int i = 0; i <= no_of_node; i++)
    {
        std::cout << "Enter the elements ";
        std::cin >> element;
        root = tree.insert(root, element);
    }

    std::cout << tree.find_min(root) << std::endl;
    std::cout << tree.find_max(root) << std::endl;

    return 0;
}