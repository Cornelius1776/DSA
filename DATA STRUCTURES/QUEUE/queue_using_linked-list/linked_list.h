#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

class Node
{
    int data;
    Node *next;
    Node *front = nullptr;
    Node *rear = nullptr;

public:
    // Methods
    void enqueue(int element)
    {
        Node *temp = new Node();
        temp->data = element;
        temp->next = nullptr;
        if (front == nullptr && rear == nullptr)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
        // delete temp; and watch the code go crazy
    }

    void dequeue()
    {
        Node *temp = new Node();
        temp = front;
        if (front == nullptr)
        {
            std::cout << "Queue is empty " << std::endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete temp;
    }

    bool is_empty()
    {
        if (front == nullptr && rear == nullptr)
        {
            return true;
        }
        return false;
    }

    int check_front()
    {
        if (is_empty())
        {
            std::cout << "Can't return from an empty queue" << std::endl;
            return 0;
        }
        std::cout << "Element at the front is ";
        return front->data;
        std::cout << std::endl;
    }

    void display()
    {
        Node *temp = front;
        std::cout << "Queue contains:>> ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif // !LINKED_LIST_H
