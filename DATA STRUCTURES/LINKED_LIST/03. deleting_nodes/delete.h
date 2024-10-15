#ifndef DELETE_H
#define DELETE_H
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

Node *head;

void insert(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

void output()
{
    Node *temp = head;
    std::cout << "[";
    while (temp != nullptr) // or temp != nullptr
    {
        std::cout << temp->data;
        if ((temp - 1) != nullptr)
        {
            std::cout << ", ";
        }
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

void delete_node(int n)
{
    Node *temp_1 = head;
    // Deleting the first/head node
    if (n == 0)
    {
        std::cout << "Deleted node at index " << n << std::endl;
        head = temp_1->next;
        delete temp_1;
        return; // this way it won't execute for non-head node
    }

    int i;
    int count = n - 1;
    // deleting any given Node n
    for (i = 0; i < count; i++)
    {
        temp_1 = temp_1->next; // temp_1 points to (n-1)th Node
    }

    Node *temp_2 = new Node();
    std::cout << "Deleted node at index " << n << std::endl;
    std::cout << std::endl;
    temp_2 = temp_1->next;       // nth Node
    temp_1->next = temp_2->next; // (n+1)th Node
    delete temp_2;
}

#endif // !DELETE_H
