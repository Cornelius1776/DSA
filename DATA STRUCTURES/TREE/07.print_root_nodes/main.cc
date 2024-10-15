#include "root.h"

int main()
{
    BST_node tree;
    BST_node *root = nullptr;

    int arr[] = {25, 27, 20, 22, 12, 18, 45, 10, 32, 14, 56, 43, 98, 100};
    for (auto &&data : arr)
    {
        root = tree.insert(root, data);
    }

    std::cout << "The root nodes are ";
    tree.sub_roots(root);

    std::cout << std::endl;

    std::cout << "The main root node is ";
    tree.tree_root(root);
    return 0;
}