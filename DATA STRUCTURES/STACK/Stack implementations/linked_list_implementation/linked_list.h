#include <iostream>
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class Node
{
    int _data;
    Node *_link;

public:
    Node *top = nullptr;

    // Methods
    // 1. Insert element on the stack
    void push(int data)
    {
        Node *temp = new Node();
        temp->_data = data;
        temp->_link = top;
        top = temp;
    }

    // 2. check if stack is empty
    bool is_empty()
    {
        if (top == nullptr)
        {
            return true;
        }

        return false;
    }

    // 3. delete element from the stack
    void pop()
    {
        if (is_empty())
        {
            std::cout << "The stack is empty" << std::endl;
        }

        Node *temp = new Node();
        std::cout << top->_data << " has been removed from the stack" << std::endl;
        temp = top;
        top = top->_link;
        delete temp;
    }

    // 4. show element at the top of the stack
    void show_top()
    {
        if (is_empty())
        {
            std::cout << "Stack is empty! " << std::endl;
        }
        std::cout << "Element at the top is: " << top->_data << std::endl;
    }

    // 5. Display stack
    void output()
    {
        if (is_empty())
        {
            std::cout << "The stack is empty! " << std::endl;
        }

        Node *temp = top;
        while (temp) // or temp != nullptr
        {
            std::cout << temp->_data << " ";
            temp = temp->_link;
        }
        std::cout << std::endl;
    }
};
#endif // !LINKED_LIST_H
