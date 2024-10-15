#include "linked_list.h"

int main()
{
    Node node;
    int no_of_item; // Number of elements to input to the linked-list
    int element;
    Node *head = nullptr;

    std::cout << "How many elements? ";
    std::cin >> no_of_item;

    // insert at the beginning/head
    for (size_t i = 0; i < no_of_item; i++)
    {
        std::cout << "Enter elements at head: ";
        std::cin >> element;
        node.insert(&head, element);
        node.output(head);
    }

    std::cout << "\n";

    // insert at the end/tail
    for (size_t i = 0; i < no_of_item; i++)
    {
        std::cout << "Enter elements at tail: ";
        std::cin >> element;
        node.append(&head, element);
        node.output(head);
    }

    /* node.insert(&head, 12);
    node.insert(&head, 24);
    node.insert(&head, 48);
    node.output(head);
    */

    /*
     node.append(&head, 12);
     node.append(&head, 24);
     node.append(&head, 48);
     node.output(head);
     */

    return 0;
}
