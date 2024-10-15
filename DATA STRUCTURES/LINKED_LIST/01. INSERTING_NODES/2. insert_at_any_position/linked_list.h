#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>

struct Node
{
    int m_data;
    Node *next;
};

// Global head pointer can also be used but it is not recommended
Node *head;

// Function to insert at nth position
void insert(int data, int n)
{
    Node *temp_1 = new Node();
    temp_1->m_data = data;
    temp_1->next = nullptr;

    if (n == 0) // n(index) can also start at 1
    {
        temp_1->next = head; // This is because head is equal to nullptr in main
        head = temp_1;       // Allows head to point to temp_1 data
        return;              // execution for insert is returned
    }

    // temporary pointer to the address of head, indicates beginning of the linked list
    Node *temp_2 = head;

    int count = n - 1; // if index starts at 1, then count = n - 1
    for (int i = 0; i < count; i++)
    {
        temp_2 = temp_2->next;
    }

    temp_1->next = temp_2->next;
    temp_2->next = temp_1;
}

// Display the elements in the linked-list
void output()
{
    Node *temp = head;
    while (temp) // or temp != nullptr
    {
        std::cout << temp->m_data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // !LINKED_LIST