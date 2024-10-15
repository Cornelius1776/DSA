#include "exercise.h"
/* Check if a binary tree(BT) is a binary search tree(BST). a BT is where each node can have at
most 2 children, while a BST is one where the data of the left node must be lesser or equal to
the value of the root node, and the data of the right node must be greater than that of the root
node. This rule applies starting from the root node of the entire tree down to the left and right
sub-trees. So, all BST are BT, but all BT are not BST. */

int main()
{
    BST_node *root = nullptr;
    BST_node tree;
    BST_node tree_1;

    // Binary search tree
    root = tree.insert(root, 7);
    root = tree.insert(root, 4);
    root = tree.insert(root, 9);
    root = tree.insert(root, 1);
    root = tree.insert(root, 1);
    root = tree.insert(root, 6);
    std::cout << std::boolalpha << tree.is_BST(root) << std::endl;

    // Binary tree
    root = tree.insert(root, 5);
    root = tree.insert(root, 1);
    root = tree.insert(root, 8);
    root = tree.insert(root, 9);
    root = tree.insert(root, 12);
    std::cout << std::boolalpha << tree.is_BST(root) << std::endl;

    // Binary search tree
    root = tree.insert(root, 8);
    root = tree.insert(root, 6);
    root = tree.insert(root, 4);
    std::cout << std::boolalpha << tree.is_BST(root) << std::endl;

    // Binary tree
    root = tree.insert(root, 10);
    root = tree.insert(root, 4);
    root = tree.insert(root, 16);
    root = tree.insert(root, 4);
    root = tree.insert(root, 7);
    root = tree.insert(root, 1);
    root = tree.insert(root, 11);
    std::cout << std::boolalpha << tree.is_BST(root) << std::endl;

    return 0;
}