#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H
#define MAXSIZE 20
class Queue
{
    int arr[MAXSIZE];
    int front;
    int rear;

public:
    // Constructor
    Queue()
    {
        // -1 is used to represent empty queue
        front = -1;
        rear = -1;
    }

    // Methods
    // Check if queue is empty
    bool is_empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    // Check if queue is full
    bool is_full()
    {
        if ((rear + 1) % MAXSIZE == front)
        {
            return true;
        }
        return false;
    }

    // Add element to the queue from the rear
    void enqueue(int element) // or push()
    {
        std::cout << "Entering " << element << " into queue..." << std::endl;
        if (is_full())
        {
            std::cout << "The queue is full! " << std::endl;
        }
        else if (is_empty())
        {
            front = rear = 0;
        }
        else
        {
            // This allows the element to take the space of any dequeued one
            rear = (rear + 1) % MAXSIZE;
        }
        arr[rear] = element;
    }

    // Remove element from the front
    void dequeue()
    {
        std::cout << "Removing " << arr[front] << " from queue..." << std::endl;
        if (is_empty())
        {
            std::cout << "Queue is empty: " << std::endl;
            return;
        }
        else if (front == rear)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % MAXSIZE;
        }
    }

    // Return element at the back
    int back()
    {
        if (is_empty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[rear];
    }

    // Return element at the front
    int Front()
    {
        if (is_empty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1; // without this return -1, the output will be zero
        }
        return arr[front];
    }

    // Display the elements of the queue
    void display()
    {
        int count = (rear + MAXSIZE - front) % MAXSIZE + 1; // Check number of elements in the queue
        std::cout << "Queue contains: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAXSIZE; // index of each element in the queue
            std::cout << arr[index] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // !ARRAY_H
