#include "linked_list.h"

int main()
{
    Node linked_list;
    int no_of_element;    // No of elements to input to the linked-list
    Node *head = nullptr; // Empty linked list

    std::cout << "How many elements? ";
    std::cin >> no_of_element;

    int element;
    for (int i = 0; i < no_of_element; i++)
    {
        std::cin >> element;
        linked_list.insert(&head, element); // Syntax 1 function call
        // head = linked_list.insert(head, element); // Syntax 2 function call
        linked_list.output(head);
    }

    return 0;
}
