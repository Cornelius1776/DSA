#include "exercise.h"

/* Inorder successor(of a node) is the node that appears just after the provided key node in an
inorder traversal of the BST.*/

int main()
{
    BST_node tree;
    BST_node *root = nullptr;
    BST_node *child = nullptr;

    root = tree.insert(root, 5);
    root = tree.insert(root, 3);
    root = tree.insert(root, 1);
    root = tree.insert(root, 10);
    root = tree.insert(root, 4);
    root = tree.insert(root, 11);
    tree.in_order(root);
    std::cout << std::endl;
    child = tree.get_successor(root, 3);
    if (child == nullptr)
    {
        std::cout << "Successor not found! \n";
    }
    else
    {
        std::cout << "Successor found! \n";
    }

    return 0;
}