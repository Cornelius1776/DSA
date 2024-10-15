#include "array.h"

int main()
{
    Stack stack;

    std::cout << stack.is_empty() << std::endl;
    stack.Bottom(); // holds a random junk data
    stack.Top();    // Also holds a junk data
    stack.push(2);
    stack.Bottom();
    stack.Top();
    stack.print();
    stack.push(3);
    stack.print();
    stack.push(4);
    stack.print();
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.push(6);
    stack.print();
    stack.Top();
    stack.print();

    int arr[] = {23, 87, 78, 98};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        stack.push(arr[i]);
    }
    stack.print();
    stack.Bottom();
    stack.Top();
    stack.print();

    return 0;
}