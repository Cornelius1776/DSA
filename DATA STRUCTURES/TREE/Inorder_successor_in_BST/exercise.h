#ifndef EXERCISE_H
#define EXERCISE_H
#include <iostream>
#include <queue>

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

    // Prints the data in a depth-first inorder traversal pattern
    void in_order(BST_node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        in_order(root->left);
        std::cout << root->m_data << " ";
        in_order(root->right);
    }

    // Find data in the tree
    BST_node *find(BST_node *root, int data)
    {
        if (is_empty(root))
        {
            return nullptr;
        }
        if (root->m_data == data)
        {
            return root;
        }
        else if (root->m_data < data)
        {
            return find(root->right, data);
        }
        else
        {
            return find(root->left, data);
        }
    }

    // Find minimum element in a tree
    BST_node *find_min(BST_node *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    // Find Inorder successor node
    BST_node *get_successor(BST_node *root, int data)
    {
        // Search the node
        BST_node *current = find(root, data);
        if (current == nullptr)
        {
            return nullptr;
        }

        // Case 1: Node has a right subtree
        if (current->right != nullptr)
        {
            return find_min(current->right);
        }
        else // Case 2: Node has no right subtree
        {
            BST_node *child = nullptr;
            BST_node *parent = root;

            while (parent != current)
            {
                if (current->m_data < parent->m_data)
                {
                    child = parent;
                    parent = parent->left;
                }
                else
                {
                    parent = parent->right;
                }
            }
            return parent;
        }
    }
};

#endif // EXERCISE_H