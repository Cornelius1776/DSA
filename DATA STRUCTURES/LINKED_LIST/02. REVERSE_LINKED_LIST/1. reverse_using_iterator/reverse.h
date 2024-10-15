#ifndef REVERSE_H
#define REVERSE_H
#include <iostream>

class Node
{

    int data_;
    Node *next_;

public:
    Node *insert(Node *head, int data)
    {
        Node *temp = new Node();
        temp->data_ = data;
        temp->next_ = head;
        head = temp;
        return head;
    }

    void output(Node *head)
    {
        Node *temp = head;
        std::cout << "The linked list contains: " << std::endl;
        while (temp != nullptr)
        {
            // std::cout << temp->data << " address is " << &temp->data << std::endl;
            std::cout << temp->data_ << " ";
            temp = temp->next_;
        }
        std::cout << std::endl;
    }

    Node *reverse(Node *head)
    {
        // *next in this function scope temporarily holds the next node as the linked list is being
        // reversed, it helps to hold the link btw the nodes as *current points backward to *prev.
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current) // or current != nullptr
        {
            next = current->next_;
            current->next_ = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};

#endif // !REVERSE_H