#ifndef MIN_MAX_H
#define MIN_MAX_H
#include <iostream>

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
            return root;
        }
        else if (data <= root->m_data)
        {
            root->left = insert(root->left, data);
        }
        else
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

    // Find the minimum element in the tree
    int find_min(BST_node *root)
    {
        if (is_empty(root))
        {
            std::cout << "The tree is empty " << std::endl;
            return -1;
        }
        else if (root->left == nullptr)
        {
            std::cout << "The minimum element in the tree is ";
            return root->m_data;
        }
        return find_min(root->left);
    }

    // Find maximum element in a tree
    int find_max(BST_node *root)
    {
        if (is_empty(root))
        {
            std::cout << "The tree is empty " << std::endl;
            return -1;
        }
        else if (root->right == nullptr)
        {
            std::cout << "The maximum element in the tree is ";
            return root->m_data;
        }
        return find_max(root->right);
    }
};

#endif // !