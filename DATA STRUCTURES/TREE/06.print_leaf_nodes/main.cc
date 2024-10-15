#include "leaf.h"

int main()
{
    BST_node tree;
    BST_node *root = nullptr;

    /* root = tree.insert(root, 25);
    root = tree.insert(root, 27);
    root = tree.insert(root, 20);
    root = tree.insert(root, 22);
    root = tree.insert(root, 12);
    root = tree.insert(root, 18);
    root = tree.insert(root, 45);
    root = tree.insert(root, 10); */

    int arr[] = {25, 27, 20, 22, 12, 18, 45, 10};
    for (auto &&data : arr)
    {
        root = tree.insert(root, data);
    }

    tree.print_leaf(root);
    std::cout << std::endl;

    return 0;
}