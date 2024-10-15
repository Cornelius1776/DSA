#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H
#define MAX_SIZE 200
class Stack
{
    int _array[MAX_SIZE];
    int top = -1;
    int bottom = 0;

public:
    // Methods
    // Insert elements into the stack
    void push(int data)
    {
        if (top == MAX_SIZE - 1)
        {
            std::cout << "Error: stack overflow " << std::endl;
            return;
        }

        _array[++top] = data; // top++ will corrupt the output
    }

    bool is_empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    // Delete element from the stack
    void pop()
    {
        if (top == -1)
        {
            std::cout << "Error: no element in the stack" << std::endl;
            return;
        }
        top--;
    }

    // Check the element at the top of the stack
    void Top()
    {
        std::cout << "Element at the top of the stack is " << _array[top] << std::endl;
    }

    // Check element at the bottom of the stack
    void Bottom()
    {
        std::cout << "Element at the bottom of the stack is " << _array[bottom] << std::endl;
    }

    // Print the elements of the stack
    void print()
    {
        std::cout << "[";
        for (int i = 0; i <= top; i++)
        {
            std::cout << _array[i];
            if (i < top)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

#endif // !ARRAY_H
