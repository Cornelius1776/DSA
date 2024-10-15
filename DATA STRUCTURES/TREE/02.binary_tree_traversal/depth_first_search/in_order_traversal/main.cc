#include "in_order.h"

int main()
{
    BST_node *root = nullptr;
    BST_node tree;

    root = tree.insert(root, 25);
    root = tree.insert(root, 273);
    root = tree.insert(root, 2);
    root = tree.insert(root, 12);
    root = tree.insert(root, 45);
    root = tree.insert(root, 10);

    tree.in_order(root);
    std::cout << std::endl;
    std::cout << std::boolalpha << tree.search(root, 11) << std::endl;
    std::cout << std::boolalpha << tree.search(root, 10) << std::endl;

    return 0;
}