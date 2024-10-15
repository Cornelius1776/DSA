#include "min_max.h"

/* Iterator(loops) is used to find the minimum and maximum elements in the tree. */

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

    std::cout << tree.find_min(root) << std::endl;
    std::cout << tree.find_max(root) << std::endl;

    return 0;
}