#ifndef PRE_ORDER_H
#define PRE_ORDER_H
#include <iostream>

// BST = Binary search tree
class BST_node
{
    std::string m_data;
    BST_node *left;
    BST_node *right;

public:
    // Methods
    // Create nodes of the tree
    BST_node *create_node(std::string data)
    {
        BST_node *new_node = new BST_node();
        new_node->m_data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }

    // Insert data into the nodes of the tree
    BST_node *insert(BST_node *root, std::string data)
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
    bool search(BST_node *root, std::string data)
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

    // Check the root node
    void check_root(BST_node *root)
    {
        std::cout << "The root node contains: ";
        if (root != nullptr)
        {
            std::cout << root->m_data << " \n";
        }
    }

    // Prints the data in a depth-first preorder traversal
    void pre_order(BST_node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->m_data << " ";
        pre_order(root->left);
        pre_order(root->right);

        //  I wrote this for a better visualization of the preorder traversal.
        /* std::cout << "The left node contains: ";
        if (root->left == nullptr)
        {
            std::cout << "null " << std::endl;
        }
        pre_order(root->left);

        std::cout << "The right node contains: ";
        if (root->right == nullptr)
        {
            std::cout << "null " << std::endl;
        }

        pre_order(root->right); */
    }
};

#endif // PRE_ORDER_H
