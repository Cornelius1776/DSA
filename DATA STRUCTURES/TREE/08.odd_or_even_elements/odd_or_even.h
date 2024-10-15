#ifndef ODD_OR_EVEN_H
#define ODD_OR_EVEN_H
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
            // return root;
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

    // print values in the tree that are odd numbers
    void odd(BST_node *root)
    {
        if (is_empty(root))
        {
            return;
        }

        if (root->m_data % 2 != 0)
        {
            std::cout << root->m_data << " ";
        }

        if (root->left != nullptr)
        {
            odd(root->left);
        }

        if (root->right != nullptr)
        {
            odd(root->right);
        }
    }

    // print values in the tree that are even numbers
    void even(BST_node *root)
    {
        if (is_empty(root))
        {
            return;
        }

        if (root->m_data % 2 == 0)
        {
            std::cout << root->m_data << " ";
        }

        if (root->left != nullptr)
        {
            even(root->left);
        }

        if (root->right != nullptr)
        {
            even(root->right);
        }
    }
};

#endif // !ODD_OR_EVEN_H
