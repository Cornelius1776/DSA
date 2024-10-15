#ifndef EXERCISE_H
#define EXERCISE_H
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

    /* // check if values in a subtree are lesser than its root node
    bool is_lesser(BST_node *root, int data)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->m_data <= data &&
            is_lesser(root->left, data) &&
            is_lesser(root->right, data))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // checks if values in a subtree are greater than its root node
    bool is_greater(BST_node *root, int data)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->m_data > data &&
            is_greater(root->left, data) &&
            is_greater(root->right, data))
        {
            return true;
        }
        else
        {
            return false;
        }
    } */

    // instead of 2 seperate functions is_lesser(), is_greater(). a single function can check
    // maximum and minimum value
    bool bst_util(BST_node *root, int min_value, int max_value)
    {
        if (root == nullptr)
        {
            return true;
        }

        if ( // root->m_data > min_value && root->m_data < max_value &&
             //  in case of duplicates
            root->m_data >= min_value && root->m_data <= max_value &&
            bst_util(root->left, min_value, root->m_data) &&
            bst_util(root->right, root->m_data, max_value))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Sum of all the elements in the BST
    void sum(BST_node *root)
    {
        int sum = 0;
        while (root->left != nullptr && root->right != nullptr)
        {
            sum += root->m_data;
        }
        std::cout << "Sum of the tree is " << sum << std::endl;
    }
};

#endif // !EXERCISE_H
