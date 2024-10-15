#include "exercise.h"

int main()
{
    BST_node *root = nullptr;
    BST_node tree;
    BST_node tree_1;

    // Binary search tree
    // tree.is_empty(root);
    root = tree.insert(root, 7);
    root = tree.insert(root, 4);
    root = tree.insert(root, 9);
    root = tree.insert(root, 1);
    root = tree.insert(root, 1);
    root = tree.insert(root, 6);

    // tree.is_empty(root);
    tree.search(root, 1);
    tree.sum(root);

    return 0;
}