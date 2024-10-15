#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>

class Node
{
    int m_data;
    Node *next;

public:
    // Function to insert elements at the beginning of the linked-list
    // Syntax 1 (** pointer to head pointer syntax)
    void insert(Node **head, int data)
    {
        Node *temp = new Node();
        temp->m_data = data;
        temp->next = *head;
        *head = temp;
    }

    // Syntax 2
    /* Node *insert(Node *head, int data)
    {
        Node *temp = new Node();
        temp->m_data = data;
        temp->next = head;
        head = temp;
        return head;
    } */

    // Function to display the linked list
    void output(Node *head)
    {
        Node *temp = head;
        std::cout << "The linked list contains => [";
        while (temp != nullptr)
        {
            // std::cout << temp->m_data << " : " << &temp->m_data << "\n"; // To print memory address alongside
            std::cout << temp->m_data;
            if (temp->next != nullptr)
            {
                std::cout << ", ";
            }

            temp = temp->next;
        }
        std::cout << "]" << std::endl;
    }
};

#endif