#include <iostream>
#include "reverse.h"

/* In this implementation, we are only printing the elements of the linked-list in a reverse order,
The elements in the linked list remain unreversed. */

int main()
{
    Node linked_list;
    Node *head = nullptr;
    Node *temp;
    linked_list.insert(&head, 2);
    linked_list.insert(&head, 3);
    linked_list.insert(&head, 4);
    linked_list.insert(&head, 5);
    linked_list.output(head);
    linked_list.reverse_output(head, temp);

    return 0;
}