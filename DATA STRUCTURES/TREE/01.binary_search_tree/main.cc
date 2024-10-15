#include "binary_search_tree.h"

int main()
{
    BST_node *root = nullptr;
    BST_node tree;

    // Binary tree
    root = tree.insert(root, 25);
    root = tree.insert(root, 27);
    root = tree.insert(root, 20);
    root = tree.insert(root, 12);
    root = tree.insert(root, 45);
    root = tree.insert(root, 10);

    // Binary search tree
    root = tree.insert(root, 25);
    root = tree.insert(root, 27);
    root = tree.insert(root, 20);
    root = tree.insert(root, 22);
    root = tree.insert(root, 12);
    root = tree.insert(root, 18);
    root = tree.insert(root, 45);
    root = tree.insert(root, 10);

    /* int no_of_node;
    std::cout << "How many nodes? " << std::endl;
    std::cin >> no_of_node;
    int add_node;
    for (size_t i = 0; i < no_of_node; i++)
    {
        std::cout << "Enter the data..." << std::endl;
        std::cin >> add_node;
        root = tree.insert(root, add_node);
        tree.display(root);
    } */

    int data, no_of_search;
    std::cout << "How many searches do you want to perform? ";
    std::cin >> no_of_search;

    for (int i = 0; i < no_of_search; i++)
    {
        std::cout << "What data do you want to search? ";
        std::cin >> data;

        if (tree.search(root, data) == true)
        {
            std::cout << data << " is found!" << std::endl;
        }
        else
        {
            std::cout << data << " not found!" << std::endl;
        }
    }

    std::cout << std::boolalpha << tree.is_empty(root) << std::endl;

    return 0;
}