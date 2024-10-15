#include "pre_order.h"

int main()
{
    BST_node *root = nullptr;
    BST_node tree;

    root = tree.insert(root, "Dog");
    root = tree.insert(root, "Cat");
    root = tree.insert(root, "Eagle");
    root = tree.insert(root, "Lion");
    root = tree.insert(root, "Ant");
    root = tree.insert(root, "Zebra");

    tree.pre_order(root);
    std::cout << std::endl;
    tree.check_root(root);

    return 0;
}