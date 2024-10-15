#ifndef REVERSE_H
#define REVERSE_H
#include <iostream>

struct Node
{
    int data_;
    Node *next_;

    /* // Constructor
    Node() = default
    Node(int data, Node *next)
    {
        data_ = data;
        next_ = nullptr;
    }*/

    void insert(Node **head, int data)
    {
        Node *temp = new Node();
        temp->data_ = data;
        temp->next_ = *head;
        *head = temp;
    }

    void output(Node *head)
    {
        std::cout << "The linked list contains: \n";
        while (head != nullptr)
        {
            std::cout << head->data_ << " ";
            head = head->next_;
        }
        std::cout << std::endl;
    }

    void reverse_output(Node *head, Node *temp)
    {
        if (temp->next_ == nullptr)
        {
            head = temp;
            return; // Exit condition
        }
        std::cout << head->data_ << " ";
        reverse_output(head, temp->next_);
        Node *temp_1 = temp->next_;
        temp_1->next_ = temp;
        temp->next_ = nullptr;
    }
};

#endif // !REVERSE_H
