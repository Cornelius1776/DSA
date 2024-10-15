#ifndef IN_ORDER_H
#define IN_ORDER_H
#include <iostream>
// #include <queue>

// BST = Binary search tree
class BST_node
{
    int m_data;
    BST_node *left;
    BST_node *right;

public:
    // Methods
    // Create nodes of the tree
    BST_node *create_node(int data)
    {
        BST_node *new_node = new BST_node();
        new_node->m_data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }

    // Insert data into the nodes of the tree
    BST_node *insert(BST_node *root, int data)
    {
        if (root == nullptr)
        {
            root = create_node(data);
            // return root;
        }
        else if (data <= root->m_data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->m_data)
        {
            root->right = insert(root->right, data);
        }
        return root;
    }

    // Check if tree is empty
    bool is_empty(BST_node *root)
    {
        if (root != nullptr)
        {
            return false;
        }
        return true;
    }

    // Search data in the tree
    bool search(BST_node *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (root->m_data == data)
        {
            return true;
        }
        else if (data <= root->m_data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }

    // Prints the data in a depth-first in-order traversal
    void in_order(BST_node *root)
    {
        if (is_empty(root))
        {
            return;
        }

        in_order(root->left);
        std::cout << root->m_data << " ";
        in_order(root->right);
    }
};

#endif // IN_ORDER_H
