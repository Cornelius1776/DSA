#include "exercise.h"

int main()
{
    BST_node tree;
    BST_node *root = nullptr;

    root = tree.insert(root, 12);
    root = tree.insert(root, 5);
    root = tree.insert(root, 15);
    root = tree.insert(root, 3);
    root = tree.insert(root, 7);
    root = tree.insert(root, 13);
    root = tree.insert(root, 17);
    root = tree.insert(root, 1);
    root = tree.insert(root, 9);
    tree.in_order(root);
    std::cout << std::endl;
    tree.delete_node(root, 3);
    tree.in_order(root);

    std::cout << std::endl;
    tree.delete_node(root, 15);
    tree.in_order(root);

    return 0;
}