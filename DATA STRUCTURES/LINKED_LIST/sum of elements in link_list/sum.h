#ifndef SUM
#define SUM
#include <iostream>

class Node
{
    int m_data;
    Node *next;

public:
    void insert(Node **head, int data)
    {
        Node *temp = new Node();
        temp->m_data = data;
        temp->next = *head;
        *head = temp;
    }

    // Function to display the linked list
    void output(Node *head)
    {
        // Node *temp = head;
        std::cout << "The linked list contains: ";
        while (head != nullptr)
        {
            // std::cout << temp->data << " address is " << &temp->data << std::endl;
            std::cout << head->m_data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    // Sum the elements of the linked list
    // Using Iteration
    void sum(Node *head)
    {
        int sum = 0;
        while (head != nullptr)
        {
            sum += head->m_data;
            head = head->next;
        }
        std::cout << "The sum of the linked list is " << sum << std::endl;
    }

    // Using Recursion
    int my_sum(Node *head)
    {
        if (head != nullptr)
        {
            return head->m_data + my_sum(head->next);
        }
        return 0;
    }
};

#endif