#include "level_order.h"

// Breadth first search(BFS) is also called level order traversal

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

    tree.level_order(root);

    return 0;
}