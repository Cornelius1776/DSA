#include <iostream>
#include <cstring>
#ifndef STRING_H
#define STRING_H

class Stack
{
    int _top;
    unsigned _capacity;
    char *_array;

public:
    // create a new stack
    Stack *new_stack(unsigned capacity)
    {
        Stack *stack = new Stack();
        stack->_capacity = capacity;
        stack->_top = -1;
        stack->_array = new char(stack->_capacity * sizeof(char));
        return stack;
    }

    // check if stack is full
    int is_full(Stack *stack)
    {
        return stack->_top == stack->_capacity - 1;
    }

    // chech if stack is empty
    int is_empty(Stack *stack)
    {
        return stack->_top == -1;
    }

    // Add item to the stack
    void push(Stack *stack, char item)
    {
        if (is_full(stack))
        {
            return;
        }
        stack->_array[++stack->_top] = item;
    }

    // Remove item from the stack
    char pop(Stack *stack)
    {
        if (is_empty(stack))
        {
            return -1;
        }
        return stack->_array[stack->_top--];
    }

    // Reverse the string
    void reverse(char str[])
    {
        // create a stack with capacity equal to the length of the string
        int n = strlen(str);
        Stack *stack = new_stack(n);

        // pushing characters of the string into the stack
        int i;
        for (i = 0; i < n; i++)
        {
            push(stack, str[i]);
        }

        // pop the characters of the string out of the stack
        for (i = 0; i < n; i++)
        {
            str[i] = pop(stack);
        }
    }
};

#endif // !STRING_H