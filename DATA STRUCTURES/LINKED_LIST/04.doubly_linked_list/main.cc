#include "doubly.h"

/* When we say linked-list, by default we are talking about what is called singly linked-list this
is a linked-list where the link between the nodes go in one (forward) directiion. Doubly linked-list
on the other hand is one where there is a 2-way (forward and backward) link between the linked-list.*/

int main()
{
    head = nullptr; // Empty list

    insert_at_head(2);
    insert_at_head(3);
    insert_at_head(4);
    insert_at_head(5);
    insert_at_head(6);
    forward_output();
    reverse_output();

    return 0;
}