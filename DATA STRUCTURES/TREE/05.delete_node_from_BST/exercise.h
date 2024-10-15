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

    // Find the minimum element in the tree
    BST_node *find_min(BST_node *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    // Delete node in the tree
    BST_node *delete_node(BST_node *root, int data)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (data < root->m_data)
        {
            root->left = delete_node(root->left, data);
        }
        else if (data > root->m_data)
        {
            root->right = delete_node(root->right, data);
        }
        else
        {
            // Delete cases
            // Case 1: Node with no child a.k.a leaf node
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root; // deletes the node from heap
                root = nullptr;
            }
            else if (root->left == nullptr) // Case 2: Node with one child
            {
                BST_node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr)
            {
                BST_node *temp = root;
                root = root->left;
                delete temp;
            }
            else // Case 3: Node with 2 children
            {
                BST_node *temp = find_min(root->right);
                root->m_data = temp->m_data;
                root->right = delete_node(root->right, temp->m_data);
            }
        }
        return root;
    }

    // Prints the data in a depth-first inorder traversal
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
};

#endif // !EXERCISE_H
