#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>

class Node
{
public:
    Node *_prev;
    int _data;
    Node *_next;
};

Node *head;

// Function to create a new node
Node *create_new_node(int data)
{
    Node *new_node = new Node();
    new_node->_data = data;
    new_node->_prev = nullptr;
    new_node->_next = nullptr;
    return new_node;
}

// Function to insert data at the head node
void insert_at_head(int data)
{
    Node *temp = create_new_node(data);
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    head->_prev = temp;
    temp->_next = head;
    head = temp;
}

// Function to display the element of the node in a forward direction
void forward_output()
{
    Node *temp = head;
    std::cout << "forward link >>>" << std::endl;
    while (temp != nullptr)
    {
        std::cout << temp->_data << " ";
        temp = temp->_next;
    }
    std::cout << std::endl;
}

// Function to display the elements in a backward direction
void reverse_output()
{
    Node *temp = head;
    if (temp == nullptr)
    {
        return; // Exit, because the list is empty
    }

    while (temp->_next != nullptr)
    {
        temp = temp->_next; // Going to the last node
    }

    std::cout << "Reverse link <<<" << std::endl;
    while (temp != nullptr)
    {
        std::cout << temp->_data << " ";
        temp = temp->_prev;
    }
    std::cout << std::endl;
}

#endif // !DOUBLY_H
