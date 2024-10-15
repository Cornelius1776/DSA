#include <iostream>
#include "sum.h"

int main()
{
    Node linked_list;
    Node *head = nullptr;

    linked_list.insert(&head, 23);
    linked_list.insert(&head, 2);
    linked_list.insert(&head, 54);
    linked_list.insert(&head, 74);
    linked_list.insert(&head, 84);
    linked_list.output(head);
    linked_list.sum(head);
    std::cout << "Sum is " << linked_list.my_sum(head) << std::endl;

    return 0;
}