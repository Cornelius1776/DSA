#ifndef ROOT_H
#define ROOT_H
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

    // Print the value of the main tree root node
    void tree_root(BST_node *root)
    {
        if (root != nullptr)
        {
            std::cout << root->m_data << "\n";
        }
    }

    // Print the values of main root and the sub-tree roots
    void sub_roots(BST_node *root)
    {
        if (is_empty(root))
        {
            return;
        }

        if (root != nullptr && root->left != nullptr || root->right != nullptr)
        {
            // print the values using recursive DFS Algorithm in-order traversal
            sub_roots(root->left);
            std::cout << root->m_data << " ";
            sub_roots(root->right);
        }
    }
};

#endif // !ROOT_H
