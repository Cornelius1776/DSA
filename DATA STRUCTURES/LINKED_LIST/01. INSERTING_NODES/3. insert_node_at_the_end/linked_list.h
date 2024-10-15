#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>

class Node
{
    int m_data;
    Node *next;

public:
    // Function to insert elements at the beginning of the linked-list
    void insert(Node **head, int data)
    {
        Node *temp = new Node();
        temp->m_data = data;
        temp->next = *head;
        *head = temp;
    }

    // Function to add node at the end of the linked list
    void append(Node **head, int data)
    {
        Node *temp = new Node();
        Node *tail = *head;
        temp->m_data = data;
        temp->next = nullptr;
        if (head == nullptr)
        {
            *head = temp;
            return;
        }

        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = temp;
        return;
    }

    // Function to display the linked list
    void output(Node *head)
    {

        // Node *temp = head;
        std::cout << "The linked list contains:" << std::endl;
        while (head != nullptr)
        {
            // std::cout << temp->data << " address is " << &temp->data << std::endl;
            std::cout << head->m_data << " ";
            head = head->next;
        }
        std::cout << std::endl;
        // std::cout << std::endl;
    }
};

#endif